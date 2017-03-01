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

#include "abstract_os.h"

#include <QCoreApplication>
#include <QDebug>
#include <QDir>

QString appFilesPath()
{
    QString appDirPath = QCoreApplication::applicationDirPath();

#if defined(Q_OS_WIN32) || defined(Q_OS_MACOS)
    return appDirPath;

#else
    // Running on a *nix system, and installed to the standard directories.
    if(appDirPath.left(5) == "/usr/")
    {
        return "/usr/share/imp";
    }
#endif

    // Running from its own program directory on *nux, or any unhandled OS.

#ifdef QT_DEBUG
    return "/usr/share/imp";
#endif

    qDebug() << "Defaulting to appPath" << QCoreApplication::applicationDirPath();
    return appDirPath;
}
