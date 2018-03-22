/*
 * Imp:  Copyright 2016, 2017 Jesse Litton (imp@eternaldusk.com)
 *
 * This file is part of Imp.
 *
 * Imp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Imp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Imp.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "logcatcher.h"
#include "utility.h"

#include <QDateTime>
#include <QDebug>
#include <QDir>
#include <QFileInfo>

LogCatcher::LogCatcher(Options* options, QObject *parent) : QObject(parent)
{
    m_options = options;

    localChannels = QSet<QString>::fromList(fromFile("local"));
}

void LogCatcher::setLogDir(QString logDir)
{
    this->logDir = logDir;

    dirWatcher.addPath(logDir);
    connect(&dirWatcher, &QFileSystemWatcher::directoryChanged,
            this, &LogCatcher::findCurrentLogs);

#ifdef USE_FALLBACK_POLLER
    fileSizes = new QMap<QString, qint64>;
    // So first delete is harmless and there's no need to check for null on every poll...
    lastSizes = new QMap<QString, qint64>;

    fallbackPollTimer = new QTimer(this);
    fallbackPollTimer->setInterval(pollerInterval);
    connect(fallbackPollTimer, &QTimer::timeout,
            this, &LogCatcher::fallbackPoller);
    fallbackPollTimer->start();

#else

    // On Linux fileChanged actually emits on flush(), but Qt can't see flushes on
    // Windows because they don't update the file modification time.  So on Linux we
    // can just do this:

    connect(&dirWatcher, &QFileSystemWatcher::fileChanged,
            this, &LogCatcher::gotFileChanged);

#endif

    findCurrentLogs(logDir);

}

void LogCatcher::fallbackPoller()
{
    if(rebuilding)
        return;

    delete lastSizes;
    lastSizes = fileSizes;

    // Build current file/size map
    fileSizes = new QMap<QString, qint64>;
    foreach(QFileInfo fileInfo, infoList)
    {
        QFileInfo updatedInfo(fileInfo.absoluteFilePath());
        fileSizes->insert(fileInfo.absoluteFilePath(), updatedInfo.size());
    }

    if(firstPass)
    {
        firstPass = false;
        return;
    }

    // And check them against the last pass through.
    foreach(QString absoluteFilePath, fileSizes->keys())
    {
      if(!lastSizes->contains(absoluteFilePath))
      {
          // This is a new file!
          gotFileChanged(absoluteFilePath);
      }
      else if(lastSizes->value(absoluteFilePath) != fileSizes->value(absoluteFilePath))
      {
          // File existed before, but its size has changed
          gotFileChanged(absoluteFilePath);
      }
    }
}

int LogCatcher::compareLastFileSize(QFileInfo fileInfo, QFileInfoList oldList)
{
    foreach(QFileInfo oldInfo, oldList)
    {
        if(oldInfo.absoluteFilePath() == fileInfo.absoluteFilePath())
        {
            // Return the number of bytes different in file size
            return fileInfo.size() - oldInfo.size();
        }
    }

    // Files are the same, or file was not found in old list.
    return 0;
}

void LogCatcher::findCurrentLogs(const QString& dirName)
{
#ifdef USE_FALLBACK_POLLER
    rebuilding = true;
#endif

    // TOFIX:  On Windows, timestamps don't change until the file is flushed.  So, if
    //          someone logs on a second character which has the same open channels,
    //          that characters channel files will start to get used.  Then, if they
    //          log that character off, it still has the newer timestamps and IMP
    //          will look at the non-changing file rather than go back to looking
    //          at the one from the first character.
    //
    //          Solution:  Cache the timestamp, size, and line position of the files
    //          on Windows.  Use newest file where size has changed.

    QFileInfoList lastInfoList;
    if(infoList.count() > 0)
    {
        lastInfoList = infoList;
        infoList.clear();
    }

    QRegularExpression logName_re("(.*?)( \\[\\d+\\])?_[0-9]+_[0-9]+\\.txt$");

    foreach (QFileInfo fileInfo, QDir(dirName).entryInfoList()) {
        if (fileInfo.isFile()) {

            qDebug() << "LogCatcher::findCurrentLogs:  fileName = " << fileInfo.fileName();

            // If filename doesn't look like a log, skip it.
            QRegularExpressionMatch logMatch = logName_re.match(fileInfo.fileName());
            if (!logMatch.hasMatch())
            {
                continue;
            }

            // All files that have changed since last pass or were created in the last day.
            if (fileInfo.lastModified() > (QDateTime::currentDateTime().addDays(-1))
                    || (lastInfoList.count() > 0 && compareLastFileSize(fileInfo, lastInfoList) > 0))
            {

                // We only put non-local channels in the list once, no matter how many pilots
                // are in them.
                //
                // The exception is when the older file is growing and the newer one is
                // not - which means they logged on a second character, creating a newer
                // file, then logged that character out.

                QString channelName = logMatch.captured(1); //logNameRegEx.cap(1);
                if(!localChannels.contains(channelName))
                {
                    QMutableListIterator<QFileInfo> i(infoList);
                    while (i.hasNext()) {
                        QString iFileName = i.next().fileName();
                        QRegularExpressionMatch match = logName_re.match(iFileName);

                        if (match.hasPartialMatch() && match.captured(0) == channelName)
                        {
                            // If file has changed and file is newer than what we already
                            // have in list, remove what we previously put in list.
                            if ((lastInfoList.size() == 0 ||
                                     compareLastFileSize(fileInfo, lastInfoList)) &&
                                    (i.value().lastModified() < fileInfo.lastModified()))
                            {
                                qDebug() << "LogCatcher::findCurrentLogs:  Found newer or changed log for " << match.captured(0);
                                qDebug() << "                              ignoring " << iFileName;
                                qDebug() << "                              in favor of " << fileInfo.fileName();
                                i.remove();
                            }
                        }
                    }
                }
                infoList.append(fileInfo);
            }
        }
    }

#ifdef USE_FALLBACK_POLLER
    rebuilding = false;
#else

    // Emit changes for any new files that may have popped up
    // This ensures newly logged in pilots will be seen when their
    // Local_ file is created rather than waiting until someone
    // says something in channel.

    foreach (QFileInfo i, infoList)
    {
        if(!dirWatcher.files().contains(i.absoluteFilePath()))
            emit fileChanged(i.absoluteFilePath());
    }

    // Always rebuild watched files.  The actual underlying object may have changed,
    // even if the absolute path didn't.
    if(dirWatcher.files().count() > 0) {
        dirWatcher.removePaths(dirWatcher.files());
    }

    foreach (QFileInfo i, infoList)
    {
        bool result = dirWatcher.addPath(i.absoluteFilePath());
        qDebug() << "LogCatcher::findCurrentLogs - Adding " << i.absoluteFilePath() << " = " << result;
    }

#endif

}

QStringList LogCatcher::files()
{
    qDebug() << "LogCatcher::files() dirs = " << dirWatcher.directories() << ", files = " <<
                dirWatcher.files();

#ifdef USE_FALLBACK_POLLER
    QStringList files;
    foreach(QFileInfo fileInfo, infoList)
    {
        files.append(fileInfo.absoluteFilePath());
    }
    return files;
#else
    return dirWatcher.files();
#endif
}

void LogCatcher::gotFileChanged(const QString &absoluteFilePath)
{
    emit fileChanged(absoluteFilePath);
}

void LogCatcher::setPollerRefresh(int interval)
{
    pollerInterval = interval;
#ifdef USE_FALLBACK_POLLER
    fallbackPollTimer->setInterval(interval);
#endif
}
