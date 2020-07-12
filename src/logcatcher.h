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

#ifndef LOGCATCHER_H
#define LOGCATCHER_H

#include <QFileInfoList>
#include <QFileSystemWatcher>
#include <QMap>
#include <QObject>
#include <QString>
#include <QTimer>

#include "options.h"

/* On Linux, QFileSystemWatcher works fine.  On Windows, it works 50% (dirs only) thanks to
 * the way Windows doesn't update the file modified time on flush().  See the bug report at
 * https://bugreports.qt.io/browse/QTBUG-41119 for more details.
 *
 * So... On Windows we currently need to use a timer-based hack to check the individual
 * files.
 */

#ifdef Q_OS_WIN32
#define USE_FALLBACK_POLLER
#endif

using namespace std;


class LogCatcher : public QObject
{
    Q_OBJECT
public:
    explicit LogCatcher(Options* options, QObject *parent = 0);

    void setLogDir(QString logDir);
    void setPollerRefresh(int interval);
    QStringList files();

signals:
    void fileChanged(const QString &absoluteFilePath);

public slots:
    void findCurrentLogs(const QString& dirNames);
    void gotFileChanged(const QString& absoluteFilePath);
    void fallbackPoller();

private:

    QMap<QString, QFileInfoList> dirLastAllFiles;
    QMap<QString, QFileInfoList> dirWatchList;
    QMap<QString, QFileSystemWatcher*> dirWatcher;

    Options* m_options;
    QSet<QString> localChannels;
    QString logDir;

    QTimer* fallbackPollTimer;
    QMap<QString, qint64>* fileSizes;
    QMap<QString, qint64>* lastSizes;
    int pollerInterval = 1000;
    bool rebuilding = false;
    bool firstPass = true;

    long int compareLastFileSize(QFileInfo fileInfo, QFileInfoList oldList);
};

#endif // LOGCATCHER_H
