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

#include <QDateTime>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include "logcatcher.h"

LogCatcher::LogCatcher(Options* options, QObject *parent) : QObject(parent)
{
    m_options = options;
}

void LogCatcher::setLogDir(QString logDir)
{
    this->logDir = logDir;

    dirWatcher.addPath(logDir);
    connect(&dirWatcher, SIGNAL(directoryChanged(const QString&)), this, SLOT(findCurrentLogs(const QString&)));

#ifdef USE_FALLBACK_POLLER
    fileSizes = new QMap<QString, qint64>;
    // So first delete is harmless and there's no need to check for null on every poll...
    lastSizes = new QMap<QString, qint64>;

    fallbackPollTimer = new QTimer(this);
    fallbackPollTimer->setInterval(1000);
    connect(fallbackPollTimer, SIGNAL(timeout()), this, SLOT(fallbackPoller()));
    fallbackPollTimer->start();

#else

    // On Linux fileChanged actually emits on flush(), but Qt can't see flushes on
    // Windows because they don't update the file modification time.
    connect(&dirWatcher, SIGNAL(fileChanged(const QString&)), this, SLOT(gotFileChanged(const QString&)));

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

void LogCatcher::findCurrentLogs(const QString& dirName)
{
#ifdef USE_FALLBACK_POLLER
    //fallbackPollTimer->stop();
    rebuilding = true;
#endif

    if(infoList.count() > 0)
        infoList.clear();

    QRegExp logNameRegEx("(.*)_[0-9]+_[0-9]+\\.txt$");

    foreach (QFileInfo fileInfo, QDir(dirName).entryInfoList()) {
        if (fileInfo.isFile()) {

            // If filename doesn't look like a log, skip it.
            if (logNameRegEx.indexIn(fileInfo.fileName()) == -1)
            {
                continue;
            }

            if (fileInfo.lastModified() > (QDateTime::currentDateTime().addDays(-1))) {

                // We only put intel channels in the list once, no matter how many pilots
                // are in them.

                QString channelName = logNameRegEx.cap(1);
                if(m_options->getIntelChannels().contains(channelName))
                {
                    QMutableListIterator<QFileInfo> i(infoList);
                    while (i.hasNext()) {
                        QString iFileName = i.next().fileName();
                        QString iChanName = iFileName.left(iFileName.length() - 20);
                        if (iChanName == channelName) {
                            if (i.value().lastModified() < fileInfo.lastModified()) {
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
    //fallbackPollTimer->start(pollerInterval);
    rebuilding = false;
#else

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
