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

#include "mainwindow.h"
#include <QApplication>
#include <QCommandLineParser>
#include <QDebug>
#include <QDir>
#include <QtWidgets/QMessageBox>
#include <QStandardPaths>
#include <iostream>

using namespace std;

bool debugLogging = false;

void messageHandler(QtMsgType, const QMessageLogContext &, const QString & msg)
{
    QString txt = QString(QDateTime::currentDateTimeUtc().toString(
                              "yyyy.MM.dd HH:mm:ss") + "> %1").arg(msg);

    if(debugLogging)
    {
        QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
        QDir dataDir{dataPath};
        QFile outFile(dataDir.absoluteFilePath("imp.log"));
        outFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
        QTextStream ts(&outFile);

        ts << txt << endl;
    }
    std::cout << txt.toStdString() <<endl;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setOrganizationName("EternalDusk");
    a.setOrganizationDomain("https://github.com/3vi1/IMP");
    a.setApplicationName("IMP");

    QCommandLineParser parser;
    parser.setApplicationDescription("Eve Online Intelligence Management Program");
    parser.addHelpOption();
    parser.addVersionOption();

    QCommandLineOption debugOption(QStringList() << "d" << "debuglogging",
            QCoreApplication::translate("main", "Write debugging log."));
    parser.addOption(debugOption);

    // Process the actual command line arguments given by the user
    parser.process(a);
    debugLogging = parser.isSet(debugOption);

    qInstallMessageHandler(messageHandler);

    MainWindow w;
    w.show();

    return a.exec();
}
