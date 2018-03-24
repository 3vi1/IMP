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

#include <QApplication>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

#include "utility.h"
#include "abstract_os.h"

QStringList fromFile(const QString& fileName)
{
    QStringList stringList;

    QFile file(appFilesPath() + "/dictionaries/" + fileName);

    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(NULL, "Error Opening File", "Could not open file " +
                             appFilesPath() + "/dictionaries/" + fileName +
                             ".");
        QApplication::exit(1);
    }
    else
    {
        QTextStream in(&file);
        QString all = in.readAll();
        stringList = all.split('\n');
        stringList.removeAll("");

        for(int i=stringList.length()-1; i>=0; i--)
        {
            if(stringList[i].trimmed()[0]=='#')
            {
                // Discard comments
                stringList.removeAt(i);
            }
        }
    }

    return stringList;
}

QRegularExpression logName_re("(?:.+/)?(.+?)(?: \\[\\d+\\])?_[0-9]+_[0-9]+\\.txt$");

bool isLog(const QString &absoluteFilePath)
{
    QRegularExpressionMatch logMatch = logName_re.match(absoluteFilePath);
    if (logMatch.hasMatch())
    {
        return true;
    }

    return false;
}

QString logChannelName(const QString &absoluteFilePath)
{
    QRegularExpressionMatch logMatch = logName_re.match(absoluteFilePath);
    int lastCapturedIndex = logMatch.lastCapturedIndex();
    QString captured = logMatch.captured(lastCapturedIndex);

    return captured;
}
