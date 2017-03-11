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
#include "ui_mainwindow.h"
#include "abstract_os.h"
#include "findmessagesdialog.h"
#include "themecustomizationdialog.h"

#include <QColorDialog>
#include <QFontDialog>
#include <QKeySequence>
#include <QListWidget>
#include <QListWidgetItem>
#include <QMap>
#include <QMessageBox>
#include <QPoint>
#include <QProcess>
#include <QSettings>
#include <QStandardPaths>
#include <QtDebug>

#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>

#include <iostream>

void messageHandler(QtMsgType, const QMessageLogContext &, const QString & msg)
{
    QString txt = QString(QDateTime::currentDateTimeUtc().toString(
                              "yyyy.MM.dd HH:mm:ss") + "> %1").arg(msg);

    QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    QDir dataDir{dataPath};
    QFile outFile(dataDir.absoluteFilePath("imp.log"));
    outFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
    QTextStream ts(&outFile);
    ts << txt << endl;
    std::cout << txt.toStdString() <<endl;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qInstallMessageHandler(messageHandler);

    qDebug() << "---------------";
    qDebug() << "* Imp Started *";
    qDebug() << "---------------";

    ui->setupUi(this);

    // Initialize lastAlertTime
    lastAlertTime = QDateTime::currentDateTimeUtc().addDays(-1);

    initThemes();

    ui->mapView->setFocus();
    ui->mapView->gotSystemShapesFile(":/graphics/systems.svg");

    QApplication::setWindowIcon(QIcon(":/graphics/impicon.png"));
    options.setAudio(&audio);

    chatModel = new ChatModel(this);
    chatModel->setPilotCache(&pilotCache);
    ui->listView->setModel(chatModel);
    m_cid.setModel(chatModel);
    ui->listView->setItemDelegate(&m_cid);
    ui->listView->show();

    loadSettings();
    ui->actionAuto_follow->setChecked(options.getAutofollow());
    updateRegionMenu(options.getRegion());
    changeFont(options.getFontName(), options.getFontSize());

    // Init theme - Remove later, when theme returns all defaults for non-existant entries?.
    changeTheme("-Default-", ThemeType::THEME_DEFAULT);

    loadMap();
    regionMap->setRefresh(options.getMapRefresh());

    connect(&options, &Options::pollerRefreshChanged,
            this, &MainWindow::gotPollerRefreshChange);
    connect(&options, SIGNAL(logDirChanged(const QString&)),
            this, SLOT(logDirChanged(const QString&)));
    connect(&options, SIGNAL(fontChanged(QString,int)),
            this, SLOT(changeFont(QString,int)));
    connect(&options, &Options::mapRefreshChanged,
            this, &MainWindow::gotMapRefreshChange);
    connect(&options, &Options::autoPeriodChanged,
            this, &MainWindow::gotAutoPeriodChange);

    // Connect find dialog's button to our search function
    connect(&find, SIGNAL(searchRequested(QString)), this, SLOT(findLocation(QString)));

    // If we do a macOS port later, we will need to set up a timer and another
    // function to compare the previous/current clipboard value, because
    // they cannot detect the clipboard is changed until the app is activated.
    connect(QApplication::clipboard(), SIGNAL(dataChanged()),
            this, SLOT(clipboardUpdated()));

#ifndef QT_DEBUG
    ui->menuDebug->menuAction()->setVisible(false);
#endif

    connect(ui->mapView, &SvgMapView::systemClicked,
            this, &MainWindow::gotSystemClick);

    ui->mapView->show();
}

MainWindow::~MainWindow()
{
    saveSettings();
    delete ui;
}


void MainWindow::themeSelected()
{
    QAction *s = qobject_cast<QAction *> (sender());

    qDebug() << "MainWindow::themeSelected - loading " + s->text();
    changeTheme(s->text(), qvariant_cast<ThemeType>(s->data()) );
    options.setTheme(s->text(), qvariant_cast<ThemeType>(s->data()));
}

void MainWindow::changeTheme(const QString& themeName, ThemeType themeType)
{
    if(m_theme == NULL)
    {
        m_theme = new Theme(this);

        connect(m_theme, SIGNAL(backColorChanged(const QColor&)),
                ui->mapView, SLOT(gotBackColor(const QColor&)));
        connect(m_theme, SIGNAL(lineColorChanged(const QColor&)),
                ui->mapView, SLOT(gotLineColor(const QColor&)));

        connect(m_theme, &Theme::sendUpdate,
                ui->mapView, &SvgMapView::receiveThemeUpdate);
    }
    m_theme->load(themeName, themeType);
    ui->mapView->setTheme(m_theme);
}


void MainWindow::on_actionSave_As_Theme_triggered()
{
    // Set initial name value for dialog.
    QString name = m_theme->name();
    if(name == "-Default-")
    {
        name = "";
    }

    ThemeDialog themeDialog(name);
    if(themeDialog.exec())
    {
        // Name may have changed on save;
        QString name = themeDialog.getName();

        // Make sure they aren't trying to override a default theme
        foreach(QAction* action, ui->menuTheme->actions())
        {
            if(action->text() == name &&
                    action->data() == ThemeType::THEME_DEFAULT)
            {
                QMessageBox::critical(NULL, "Invalid Theme Name",
                                      "Theme not saved!  The default themes are "
                                      "updated from version to version and should "
                                      "not be replaced.  Please save your "
                                      "customized theme with a different name.",
                                      QMessageBox::Ok);
                return;
            }

        }

        if(m_theme->save(name))
            addThemeToMenu(name, ThemeType::THEME_USER);
    }
}

void MainWindow::addThemeToMenu(QString name, ThemeType themeType)
{
    QAction* newAct = new QAction(name, this);
    connect(newAct, SIGNAL(triggered()), this, SLOT(themeSelected()));
    newAct->setData(themeType);

    foreach(QAction* action, ui->menuTheme->actions())
    {
        //qDebug() << action->text();
        if(action->text() == name)
        {
            // Theme was already in menu
            return;
        }
        if(action->text() > name || action->text().length() == 0)
        {
            ui->menuTheme->insertAction(action, newAct);
            break;
        }
    }
}

void MainWindow::addThemesFromSubdirectories(QDir dir, ThemeType themeType)
{
    foreach (QFileInfo fileInfo, dir.entryInfoList()) {
        if (fileInfo.isDir() )
        {
            QString absoluteFilePath = dir.absoluteFilePath(fileInfo.fileName() + "/theme.ini");
            QFile file(absoluteFilePath);
            if(!file.exists())
                continue;

            // Add this theme to menu
            addThemeToMenu(fileInfo.fileName(), themeType);
        }
    }

}
void MainWindow::initThemes()
{
    // Add default theme to menu
    addThemeToMenu("-Default-", ThemeType::THEME_DEFAULT);
            ;
    // Add default themes to menu
    addThemesFromSubdirectories(QDir(appFilesPath() + "/themes"),
                  ThemeType::THEME_DEFAULT);

    // Pull in user themes
    QDir userThemeDir{QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation) +
                "/themes"};

    // First make directory if it doesn't exist.
    if (!userThemeDir.exists())
    {
        changeImpStatus("Creating user themes directory...");
        if (!userThemeDir.mkpath(userThemeDir.absolutePath()))
        {
            QMessageBox::critical(NULL, "Error Creating Themes Directory",
                                  "Could not create the users themes subdirectory.  "
                                  "Please check permissions on " +
                                  userThemeDir.absolutePath(), QMessageBox::Ok);
            return;
        }
    }
    else
    {
        addThemesFromSubdirectories(userThemeDir, ThemeType::THEME_USER);
    }

}

void MainWindow::changeFont(const QString& fontName, int fontSize)
{
    ui->listView->setFont(QFont(fontName,fontSize));
}

void MainWindow::loadMap()
{
    qDebug() << "MainWindow::loadMap - region = " << options.getRegion();

    ui->mapView->setLoadText("Downloading map...");
    ui->mapView->clearMap();

    if(regionMap != NULL)
    {
        regionMap->deleteLater();
        regionMap = NULL;
    }
    regionMap = new Map(this);

    ui->mapView->setMap(regionMap);
    connect(regionMap, &Map::lineAdded,
            ui->mapView, &SvgMapView::gotLine);
    connect(regionMap, &Map::systemAdded,
            ui->mapView, &SvgMapView::gotSystem);
    connect(regionMap, &Map::systemPosition,
            ui->mapView, &SvgMapView::gotSystemPosition);

    QNetworkRequest request(QUrl(options.getMapPath() +
                                 options.getRegion() + ".svg"));
    reply = manager.get(request);
    connect(reply, SIGNAL(finished()),
            this, SLOT(gotRegionFile()) );
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),
            this, SLOT(failedGettingRegionFile(QNetworkReply::NetworkError)));

    changeImpStatus("Attempting to download map for " + options.getRegion() + "...");

}

void MainWindow::loadBridges()
{
    bridgeLoading = true;

    if(bridgeMap != NULL)
    {
        bridgeMap->deleteLater();
        bridgeMap = NULL;
    }
    bridgeMap = new BridgeMap(this);

    // Append filename to URI
    QString fullPath = options.getBridgePath();
    if(!fullPath.endsWith('/'))
        fullPath += "/";
    fullPath += options.getRegion().toLower();

    qDebug() << "Loading bridges from " << fullPath;

    QNetworkRequest request(QUrl((QString)fullPath));
    reply = manager.get(request);
    connect(reply, SIGNAL(finished()),
            this, SLOT(gotBridgeFile()) );
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),
            this, SLOT(failedGettingBridgeFile(QNetworkReply::NetworkError)));

    changeImpStatus("Attempting to bridge data for " + options.getRegion() + "...");

}

void MainWindow::changeImpStatus(const QString& text)
{
    QString statusText = text;
    qDebug() << statusText;
    ui->statusBar->showMessage(statusText);
}

void MainWindow::clipboardUpdated()
{
    if(options.getKosCheck())
    {
        QStringList lines, names;
        lines = QApplication::clipboard()->text().split('\n');

        foreach(QString line, lines)
        {
            // Sanitize the list if it's copied from chat.  i.e....
            // Rotham Visteen > <url=showinfo:1375//95666387>Sir Nicolas Struik</url>  <url=showinfo:5//30003733>TU-O0T</url> nv

            // showinfo:5//... seems to denote a link to a system, pilots will have different numbers
            QRegularExpression exp("<url=showinfo:(?!5//)[^>]+>([^<]+)</url>");
            QRegularExpressionMatch match = exp.match(line);

            if(match.hasMatch())
            {
                QRegularExpressionMatchIterator i = exp.globalMatch(QApplication::clipboard()->text());
                while(i.hasNext())
                {
                    match = i.next();
                    names.append(match.captured(1));
                }
            }
            else
            {
                // Doesn't look like a copied line with markup, so just append it unsanitized.
                names.append(line);
            }
        }

        QStringList toCheck;
        foreach(QString name, names)
        {
            // Verify this looks like a valid character or corp name before we send it.
            if(name.length() < 3 ||
                    name.length() > 37 ||
                    name.count(QLatin1Char(' ')) > 2 ||
                    name.contains(QRegExp("[^ A-Za-z0-9'\\-\\.]")))
            {
                qDebug() << "MainWindow::clipboardUpdated() - Not KOS checking invalid name " << name;
               return;
            }
            else
            {
                toCheck.append(name);
            }
        }

        pilotsBeingChecked += toCheck.count();
        QString checkString = toCheck.join(',');

        if(checkString != "")
        {
            AsyncInfo* kosInfo = new AsyncInfo(manager, this);
            connect(kosInfo, &AsyncInfo::kosResultReady,
                    this, &MainWindow::gotKosReply);
            kosInfo->kosCheck(checkString);
        }
    }
}

void MainWindow::doRedByLastCheck(const QString& name, int id)
{
    qDebug() << "RBL Checking " << id;

    AsyncInfo* rblInfo = new AsyncInfo(manager, this);
    connect(rblInfo, &AsyncInfo::rblResultReady,
            this, &MainWindow::gotRblReply);
    rblInfo->rblCheck(name, id);
}

void MainWindow::gotRblReply(QString name, bool rbl)
{
    qDebug() << "MainWindow::gotRblReply - " << name << ": " << rbl;

    if(rbl)
    {
        audio.playLocalFile(options.getSoundIsKos());
        kosSoundPlayed = true;

        MessageInfo info;
        info.sender = "Khasm Kaotiqa";
        info.logInfo = &impLogInfo;
        info.dateTime = QDateTime::currentDateTimeUtc();
        info.text = name + " is RED BY LAST!";
        addMessage(info);
    }

    if(--pilotsBeingChecked == 0)
    {
        if(kosSoundPlayed)
        {
            kosSoundPlayed = false;
        }
        else
        {
            audio.playLocalFile(options.getSoundNoKos());
        }
    }
}

void MainWindow::gotKosReply(const QString& pilotNames, const QList<KosEntry>& entries)
{
    if(entries.count() == 0)
    {
        QStringList pilots = pilotNames.split(',');
        foreach(QString pilot, pilots)
        {
            doRedByLastCheck(pilot, 0);
        }
        return;
    }

    bool playKos = false;
    foreach(KosEntry e, entries)
    {
        qDebug() << "MainWindow::gotKosReply - " << e.pilot.name;
        MessageInfo info;
        info.sender = "Khasm Kaotiqa";
        info.logInfo = &impLogInfo;
        info.dateTime = QDateTime::currentDateTimeUtc();

        if(e.pilot.kos)
        {
            info.text = e.pilot.name + " is KOS!";
            playKos = true;
            addMessage(info);
        }
        else if(e.corp.kos)
        {
            info.text = e.pilot.name + "'s corp (" + e.corp.name + ") is KOS!";
            playKos = true;
            addMessage(info);
        }
        else if(e.alliance.kos)
        {
            info.text = e.pilot.name + "'s alliance (" + e.alliance.name + ") is KOS!";
            playKos = true;
            addMessage(info);
        }
        else
        {
            // If we got a player that's in an NPC corp, do the RBL check.
            if(e.corp.npc)
            {
                doRedByLastCheck(e.pilot.name, e.pilot.eveId);
                return;
            }
        }
    }
    if(playKos && kosSoundPlayed != true)
    {
        audio.playLocalFile(options.getSoundIsKos());
        kosSoundPlayed = true;
    }

    if(--pilotsBeingChecked == 0)
    {
        audio.playLocalFile(options.getSoundNoKos());
        kosSoundPlayed = false;
    }
}

void MainWindow::gotEssReply(const QList<KosEntry>& entries)
{
    bool playKos = false;
    foreach(KosEntry e, entries)
    {
        qDebug() << "MainWindow::gotEssReply - " << e.pilot.name;
        MessageInfo info;
        info.sender = "Khasm Kaotiqa";
        info.logInfo = &impLogInfo;
        info.dateTime = QDateTime::currentDateTimeUtc();

        if(e.pilot.kos || e.corp.kos || e.alliance.kos)
        {
            info.text = e.pilot.name + " is near the ESS and is KOS!";
            playKos = true;
            addMessage(info);
        }
    }
    if(playKos)
    {
        audio.playLocalFile(options.getSoundEss());
    }
}

void MainWindow::initParsing()
{
    chatModel->removeRows(0,chatModel->rowCount());

    if(parser != NULL)
    {
        parser->deleteLater();
    }
    parser = new Parser(this);
    parser->setMap(*regionMap);

    if(lc != NULL)
    {
        lc->deleteLater();
    }
    lc = new LogCatcher();

    lc->setLogDir(options.getLogPath());
#ifdef USE_FALLBACK_POLLER
    lc->setPollerRefresh(options.getPollerRefresh());
#endif

    connect(lc, SIGNAL(fileChanged(QString)), this, SLOT(fileChanged(QString)));

    // Initialize with last session if not old...
    foreach(QString absoluteFilePath, lc->files())
    {
        if(options.getIntelChannels().contains(shortName(absoluteFilePath)) ||
                parser->getLocalChannels().contains(shortName(absoluteFilePath)))
        {
            fileChanged(absoluteFilePath);
        }
    }

}

void MainWindow::failedGettingRegionFile(QNetworkReply::NetworkError err)
{
    qDebug() << "MainWindow::failedGettingRegionFile - Failed to retrieve region file.";
    qDebug() << err;
    qDebug() << "MainWindow::failedGettingRegionFile - Attempting to use local file if it exists." << endl;

    changeImpStatus("Failed getting map, attempting to use last.");

    QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    QDir dataDir{dataPath};
    QFile inFile(dataDir.absoluteFilePath(options.getRegion() + ".svg"));

    if (inFile.exists())
    {
        regionMap->loadXml(inFile);
    }
    else
    {
        QMessageBox::critical(NULL, "Error Opening File",
                              "Could not download map, and could not find cached version of " +
                              inFile.fileName() + ".  Unable to continue.", QMessageBox::Ok);
        QApplication::exit(1);
    }

    reply->deleteLater();
    errorRetrievingRegionFile = true;
}

void MainWindow::gotRegionFile()
{
    if (!errorRetrievingRegionFile)
    {
        changeImpStatus("Retrieved region file.");

        QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
        QDir dataDir{dataPath};
        QFile outFile(dataDir.absoluteFilePath(options.getRegion() + ".svg"));

        if (dataDir.mkpath(dataDir.absolutePath()))
        {
            outFile.open( QIODevice::WriteOnly );
            outFile.write(reply->readAll());
            outFile.close();

            regionMap->loadXml(outFile);
        }

        reply->deleteLater();
    }
    else
    {
        errorRetrievingRegionFile = false;
    }

    // CONNECT MAP/MAPVIEW SIGNALS HERE
    connect(regionMap, &Map::newPilot,
            this, &MainWindow::gotNewPilot);
    connect(regionMap, &Map::pilotLocationChange,
            ui->mapView, &SvgMapView::gotPilotLocation);
    connect(regionMap, &Map::systemColorUpdated,
            ui->mapView, &SvgMapView::gotSystemColor);
    connect(regionMap, &Map::systemTimeUpdated,
            ui->mapView, &SvgMapView::gotSystemTime);

    initParsing();
    changeTheme(options.getThemeName(), options.getThemeType());


    mapLoading = false;
    ui->mapView->showMap(true);
    ui->mapView->setTransform(m_mapTransform);
    ui->mapView->rotateSystems(m_savedSystemRotation);

    regionMap->startUpdates();
}

void MainWindow::failedGettingBridgeFile(QNetworkReply::NetworkError err)
{
    qDebug() << "MainWindow::failedGettingBridgeFile - Failed to retrieve bridge file.";
    qDebug() << err;

    changeImpStatus("Failed getting bridges, attempting to use last good file.");

    QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    QDir dataDir{dataPath};
    QFile inFile(dataDir.absoluteFilePath(options.getRegion().toLower()));

    if (inFile.exists())
    {
        bridgeMap->init(inFile, regionMap);
    }
    else
    {
        QMessageBox::warning(NULL, "Error Opening File",
                              "Could not download bridge data, and could not find cached version of " +
                              inFile.fileName() + ".", QMessageBox::Ok);
    }

    reply->deleteLater();
    errorRetrievingBridgeFile = true;
}

void MainWindow::gotBridgeFile()
{
    if (!errorRetrievingBridgeFile)
    {
        qDebug() << "MainWindow::gotBridgeFile() - Success.";
        changeImpStatus("Retrieved bridge file.");

        QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
        QDir dataDir{dataPath};
        QFile outFile(dataDir.absoluteFilePath(options.getRegion().toLower()));

        if (dataDir.mkpath(dataDir.absolutePath()))
        {
            outFile.open( QIODevice::WriteOnly );
            outFile.write(reply->readAll());
            outFile.close();

            bridgeMap->init(outFile, regionMap);
        }

        reply->deleteLater();
    }
    else
    {
        errorRetrievingBridgeFile = false;
    }

    foreach(QGraphicsLineItem* arrow, bridgeMap->arrows)
    {
        ui->mapView->addBridge(arrow);
    }

    bridgeLoading = false;

    ui->mapView->showBridges(true);
}

void MainWindow::loadSettings()
{
    changeImpStatus("Loading settings...");

    QString configPath = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    QDir configDir{configPath};   
    QString fileName = "imp-settings";
    QSettings settings(configDir.absoluteFilePath(fileName), QSettings::IniFormat);

    if (configDir.exists())
    {
        qDebug() << "= Restoring geometry " << settings.value("geometry");
        restoreGeometry(settings.value("geometry").toByteArray());
        restoreState(settings.value("windowState").toByteArray());

        m_mapTransform = settings.value("transform").value<QTransform>();
        m_savedSystemRotation = settings.value("systemRotation", 0).toDouble();
        ui->mapView->setSceneRect( settings.value("sceneRect").value<QRect>() );
        ui->mapView->centerOn(settings.value("center").value<QPointF>() );
    }

    // Let options figure out if settings does not exist and set defaults if reads fail.
    options.loadSettings(settings);

    QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    QDir dataDir{dataPath};
    if (dataDir.exists())
    {
        // Load avatar cache

        QFile file(dataDir.absoluteFilePath("imp-pilots"));
        file.open( QIODevice::ReadOnly );
        QDataStream stream( &file );

        stream >> pilotCache;
    }
}

void MainWindow::saveSettings()
{
    changeImpStatus("Saving settings...");

    QString configPath = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    QDir configDir{configPath};
    if (configDir.mkpath(configDir.absolutePath()) && QDir::setCurrent(configDir.absolutePath()))
    {
        // Save configuration options

        qDebug() << "Settings in " << QDir::currentPath() << endl;

        QString fileName = "imp-settings";
        QSettings settings(fileName, QSettings::IniFormat);

        settings.setValue("geometry", saveGeometry());
        settings.setValue("windowState", saveState());

        // TODO:  Does this actually work?  Position doesn't look quite right on load.
        settings.setValue("transform", ui->mapView->getTransform());
        settings.setValue("systemRotation", ui->mapView->getSystemsRotation());

        settings.setValue("sceneRect", ui->mapView->getSceneRect());
        settings.setValue("center", ui->mapView->getViewportCenter());

        options.saveSettings(settings);
    }

    QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    QDir dataDir{dataPath};
    if (dataDir.mkpath(dataDir.absolutePath()) && QDir::setCurrent(dataDir.absolutePath()))
    {
        // Remove expired avatar cache entries
        QDateTime oldestTime = QDateTime::currentDateTimeUtc();
        if(options.getHistoryMax() > 0)
        {
            oldestTime.addDays(-1 * (options.getAvatarExpiration() - 1));
        }

        QMap<QString, PilotEntry>::iterator i;
        for (i = pilotCache.begin(); i != pilotCache.end();)
        {
            if(i.value().cacheUntil < oldestTime)
            {
               pilotCache.erase(i++);
            }
            else
            {
                ++i;
            }
        }

        // Save avatar cache
        QFile file("imp-pilots");
        file.open( QIODevice::WriteOnly );
        QDataStream stream( &file );
        stream << pilotCache;
    }
}

QString MainWindow::shortName(const QString &absoluteFilePath)
{
    QString fileName = absoluteFilePath.right(absoluteFilePath.length() -
                                              absoluteFilePath.lastIndexOf('/')
                                              - 1);
    return fileName.left(fileName.length()-20);
}

void MainWindow::fileChanged(const QString &absoluteFilePath)
{
    // TODO:  Move handling to separate thread?

    QList<MessageInfo> messages;

    if(mapLoading && !parser->getLocalChannels().contains(shortName(absoluteFilePath)))
    {
        messages = parser->fileChanged(absoluteFilePath, options.getMaxEntries());
    }
    else
    {
        messages = parser->fileChanged(absoluteFilePath);
    }

    QString status = "Parsing " + QString::number(messages.count());

    if(messages.count() <= 0)
    {
        return;
    }
    else if(messages.count() == 1)
    {
        status += " new message";
    }
    else
    {
        status += " messages";
    }
    status += " from " + messages[0].logInfo->channel;
    ui->mapView->setLoadText(status);

    foreach (MessageInfo message, messages)
    {
        if(!mapLoading)
            doUserActions(message);

        bool toBeAddedToList = false;
        foreach(MessageFlag flag, message.flags)
        {
            switch(flag)
            {

            case MessageFlag::CLEAR:
                if (!options.getIntelChannels().contains(message.logInfo->channel))
                {
                    // Only accept clear messages from intel channels.
                    break;
                }

                // Someone may respond to a status message without naming the system
                // i.e. "soandso > clr"
                if(message.systems.length() == 0 && message.text.count(" ") == 0)
                {
                    message.systems.append(message.logInfo->systemLastMentioned);
                }

                foreach (QString system, message.systems)
                {
                    changeImpStatus("Clearing " + system + "...");
                    regionMap->setSystemStatus(system, SystemStatus::clear, message.dateTime);

                    if(system == lastAlertSystem)
                    {
                        lastAlertSystem = "";
                    }
                }
                toBeAddedToList = true;

                break;

            case MessageFlag::ESS:
            {
                QStringList pilots = regionMap->pilotsIn(message.systems[0]);
                foreach(QString pilot, pilots)
                {
                    if(pilotIsEnabled(pilot))
                    {
                        if(options.getEssAndKos())
                        {
                            AsyncInfo* kosInfo = new AsyncInfo(manager, this);
                            connect(kosInfo, SIGNAL(kosResultReady(const QList<KosEntry>&)),
                                    this, SLOT(gotEssReply(const QList<KosEntry>&)));
                            kosInfo->kosCheck(message.related[0]);
                        }
                        else
                        {
                            audio.playLocalFile(options.getSoundEss());
                        }
                        break;
                    }
                }
                break;
            }

            case MessageFlag::LEFT:
                break;

            case MessageFlag::LOCATION:
                break;

            case MessageFlag::MOTD:
                break;

            case MessageFlag::QUERY:
            case MessageFlag::STATUS:
                if (!options.getIntelChannels().contains(message.logInfo->channel))
                {
                    break;
                }
                foreach (QString system, message.systems)
                {
                    qint64 secondsDiff = message.dateTime.msecsTo(
                                QDateTime::currentDateTimeUtc()
                                ) / 1000;
                    if(secondsDiff < 10)
                    {
                        bool play = false;
                        foreach(QString system, message.systems)
                        {
                            // Test each pilot's location to see if we're in one of the systems.
                            QStringList pilots = regionMap->pilotsIn(system);

                            //if(regionMap->isPilotIn(system))
                            foreach(QString pilot, pilots)
                            {
                                if(pilotIsEnabled(pilot))
                                {
                                   changeImpStatus("Status requested for " + system + ".");
                                    play = true;
                                }
                            }
                        }
                        if (play)
                        {
                            audio.playLocalFile(options.getSoundStatus());
                        }
                    }
                }
                break;

            case MessageFlag::SYSTEM_CHANGE:
                if(regionMap->pilotsIn(message.systems[0]).contains(message.logInfo->pilot))
                {
                    break;

                    // We were already in that system - this is probably just a log file update.
                }
                changeImpStatus("Updating local system to " + message.systems[0] + "...");

                regionMap->setPilotLocation(message.logInfo->pilot, message.systems[0]);

                if(!pilotIsEnabled(message.logInfo->pilot))
                {
                    break;
                }

                if(options.getAutofollow())
                {
                    positionTo(message.systems[0]);
                }

                if(!mapLoading)
                    regionMap->update();
                break;

            case MessageFlag::WARNING:
                if (options.getIntelChannels().contains(message.logInfo->channel))
                {
                    foreach (QString system, message.systems)
                    {
                        regionMap->setSystemStatus(system, SystemStatus::red, message.dateTime);
                        qint64 secondsDiff = message.dateTime.msecsTo(
                                    QDateTime::currentDateTimeUtc()
                                    ) / 1000;
                        if(secondsDiff < 10)
                        {
                            bool play = false;
                            foreach(QString system, message.systems)
                            {
                                // Test each pilot location to see if it is near affected system
                                foreach(QString pilot, regionMap->pilotsAndLocation().keys())
                                {
                                    // Skip pilots that have been disabled from menu.
                                    if(!pilotIsEnabled(pilot))
                                        continue;

                                    QString pilotLoc = regionMap->pilotsSystem(pilot);
                                    if(regionMap->contains(pilotLoc) &&
                                       regionMap->distanceBetween(pilotLoc, system) <= options.getAlarmDistance()
                                      )
                                    {
                                        changeImpStatus("Setting " + system + " to red.");

                                        secondsDiff = lastAlertTime.msecsTo(
                                                    QDateTime::currentDateTimeUtc()
                                                    ) / 1000;
                                        if(!(regionMap->ourCurrentPilots().contains(message.sender) &&
                                             options.getSelfSuppress() == true) &&
                                             (secondsDiff > options.getRedundantSuppress() ||
                                              system != lastAlertSystem))
                                        {
                                            qDebug() << "-Alarming for: " << message.originalLine;
                                            qDebug() << "-pilotLoc: " << pilotLoc << "  system: " << system;
                                            lastAlertTime = QDateTime::currentDateTimeUtc();
                                            lastAlertSystem = system;
                                            play = true;
                                        }

                                        // If this is within alarm distance, let's update the map NOW.
                                        if(!mapLoading)
                                            regionMap->update();
                                    }
                                }
                            }
                            if (play)
                            {
                                audio.playLocalFile(options.getSoundAlarm());
                            }
                        }
                    }
                    toBeAddedToList = true;
                }
                break;

            default:
                qDebug() << "Unhandled flag " << flag << " found for message: " << message.text;
                break;

            }
        }
        if(toBeAddedToList)
        {
            addMessage(message);
        }

        // If we just reloaded, there may be a lot of these, so let's process other
        // events to keep the gui responsive until we rewrite multi-threaded.
        QCoreApplication::processEvents(QEventLoop::AllEvents, 20);
    }
}

void MainWindow::doUserActions(const MessageInfo& message)
{
    foreach(Rule rule, options.ruleModel->getRules())
    {
        qint64 secondsDiff = message.dateTime.msecsTo(
                    QDateTime::currentDateTimeUtc()
                    ) / 1000;
        if(secondsDiff > 10)
        {
            // Skip old messages.  This happens when restarting IMP.
            continue;
        }

        if (!rule.enabled)
        {
            continue;
        }

        QRegExp chanExp(rule.channel);
        if(chanExp.indexIn(message.logInfo->channel) != -1)
        {
            QRegExp matchExp(rule.match);
            if(matchExp.indexIn(message.originalLine) != -1)
            {
                // Rule matches our expression

                QRegExp playExp("^play (.*)$");
                if(playExp.indexIn(rule.action) != -1)
                {
                    // This is a sound-playing rule.
                    audio.playLocalFile(playExp.cap(1).trimmed());
                }
                else {
                    QRegExp launchExp("^launch ([^ ]+) *(.*)$");
                    if(launchExp.indexIn(rule.action) != -1)
                    {
                        QProcess process;
                        switch(launchExp.captureCount())
                        {
                        case 1:
                            process.start(launchExp.cap(1));
                            break;
                        default:
                            // TODO:  Implement passing of captures.
                            qDebug() << "captureCount=" << launchExp.captureCount();

                            QStringList outTexts;
                            foreach(QString s, launchExp.capturedTexts())
                            {
                                qDebug() << "   captured" << s;
/*                                QRegExp replaceExp("\\([0-9]+)");

                                int index = replaceExp.indexIn(s);
                                while(index != -1)
                                {
                                    QString newS;
                                    if(index != 0)
                                        newS = s.left(index);
                                    newS +=
                                }
                                if()
                                outTexts.append(s);*/
                            }

                            break;
                        }
                    }
                }

                // The rule was matched, and has the continue field disabled,
                // so don't process any further user rules.
                if(rule.continueOnMatch == false)
                {
                    break;
                }
            }
        }
    }
}


void MainWindow::gotAvatar(PilotEntry* pilot)
{
    pilotCache.insert(pilot->name, *pilot);
    chatModel->avatarChanged();
    ui->listView->scrollToBottom();
}

void MainWindow::addMessage(const MessageInfo& message)
{

    if (!pilotCache.contains(message.sender))
    {
        AsyncInfo* pilotInfo = new AsyncInfo(manager, this);
        connect(pilotInfo, SIGNAL(resultReady(PilotEntry*)),
                this, SLOT(gotAvatar(PilotEntry*)));

        pilotInfo->cacheAvatar(message.sender);
    }

    chatModel->addEntry(message);
    chatModel->truncateTo(options.getHistoryMax());

    ui->listView->scrollToBottom();
}

void MainWindow::on_actionAbout_triggered()
{
    info.show();
    info.startMusic(&audio);
}

void MainWindow::on_actionOptions_triggered()
{
    options.cacheSettings();
    options.show();
}



void MainWindow::positionTo(const QString& systemName)
{
    // TODO:  Replace this all with code in the view later.  This is all old stuff
    //        for the WebKit view.

    if(!regionMap->contains(systemName))
    {
        return;
    }

    QPoint systemPos = regionMap->getCoordinates(systemName);

    destinationPos = systemPos;

    if(!options.getSmoothAutofollow())
    {
        ui->mapView->centerOn(destinationPos);
        return;
    }
    else if(positionTimer == NULL)
    {
        startPos = ui->mapView->getViewportCenter();

        positionTimer = new QTimer(this);
        connect(positionTimer, SIGNAL(timeout()), this, SLOT(updatePosition()));
        positionTimer->start(33);
    }

    startTime = QDateTime::currentMSecsSinceEpoch();

    qDebug() << "Positioning To" << systemName << destinationPos;

}

void MainWindow::updatePosition()
{
    // TEMP

    if(mapLoading)
    {
        startTime = QDateTime::currentMSecsSinceEpoch();
        return;
    }

    qint64 msecPassed = (QDateTime::currentMSecsSinceEpoch() - startTime);
    float percentToward = (float)msecPassed / (float)timeToScroll;

    QPoint nextPos;
    int diffX = std::abs(destinationPos.x() - (int)startPos.x()) * percentToward;
    int diffY = std::abs(destinationPos.y() - (int)startPos.y()) * percentToward;
    int newX = destinationPos.x() > startPos.x() ? startPos.x() + diffX : startPos.x() - diffX;
    int newY = destinationPos.y() > startPos.y() ? startPos.y() + diffY : startPos.y() - diffY;
    nextPos.setX(newX);
    nextPos.setY(newY);

    ui->mapView->centerOn(nextPos);
    //qDebug() << "Updated position to "<< nextPos;

    if(msecPassed >= timeToScroll)
    {
        positionTimer->stop();
        positionTimer->deleteLater();
        positionTimer = NULL;

        qDebug() << "positionTimer expired for"<< destinationPos;
    }
}

void MainWindow::on_actionAuto_follow_triggered()
{
    options.setAutofollow(ui->actionAuto_follow->isChecked());
}

void MainWindow::gotAutoPeriodChange(int msecs)
{
    timeToScroll = msecs;
}

void MainWindow::gotMapRefreshChange(int msecs)
{
    regionMap->setRefresh(msecs);
}

void MainWindow::gotPollerRefreshChange(int msecs)
{
    lc->setPollerRefresh(msecs);
}

void MainWindow::switchToRegion(const QString& currentRegion)
{
    mapLoading = true;
    ui->mapView->showMap(false);
    updateRegionMenu(currentRegion);
    options.setRegion(currentRegion);
    loadMap();
}

void MainWindow::updateRegionMenu(const QString& currentRegion)
{
    // Set menu checks
    foreach(QAction* action, ui->menuRegion->actions())
    {
        if(action->text() == "&" + currentRegion)
        {
            action->setChecked(true);
        }
        else if(action->text() == "")
        {
            // We hit the end of regions.
            break;
        }
        else
        {
            action->setChecked(false);
        }
    }
}

void MainWindow::on_actionProvidence_triggered()
{
    switchToRegion("Providence");
}

void MainWindow::on_actionCatch_triggered()
{
    switchToRegion("Catch");
}

void MainWindow::on_actionQuerious_triggered()
{
    switchToRegion("Querious");
}

void MainWindow::on_actionSystem_triggered()
{
    find.setList(regionMap->getSystemNames());
    find.show();
}

void MainWindow::findLocation(const QString& location)
{
    QString fullName = regionMap->getSystemByAbbreviation(location.toUpper());
    ui->mapView->findLocation(fullName);
    positionTo(regionMap->getSystemByAbbreviation(location));
    ui->mapView->resetCtrl();
}

void MainWindow::logDirChanged(const QString& dir)
{
    lc->deleteLater();
    lc = new LogCatcher();
    connect(lc, SIGNAL(fileChanged(QString)), this, SLOT(fileChanged(QString)));
    lc->setLogDir(dir);
}


void MainWindow::on_actionShow_Bridges_triggered(bool checked)
{
    if(checked)
        loadBridges();
    else
        ui->mapView->showBridges(false);
}


// Debug Stuff.  To be removed: -----------------------------------------------

void MainWindow::on_actionF_YH5B_triggered()
{
    // For debug testing only, remove later...

    regionMap->setPilotLocation("Khasm Kaotiqa", "F-YH5B");
    positionTo("F-YH5B");
    lc->files();
}

void MainWindow::on_actionN_RMSH_triggered()
{
    // For debug testing only...

    regionMap->setPilotLocation("Khasm Kaotiqa", "N-RMSH");
    positionTo("N-RMSH");
    lc->files();
}

// ------------------------------------------------------------------------------


void MainWindow::gotNewPilot(const QString& pilotName)
{
    // Add pilot to Pilots menu
    QAction* newAct = new QAction(pilotName, this);
    newAct->setCheckable(true);
    newAct->setChecked(true);

    connect(newAct, SIGNAL(triggered()), this, SLOT(pilotSelected()));

    foreach(QAction* action, ui->menuPilots->actions())
    {
        qDebug() << action->text();
        if(action->text() == pilotName)
        {
            // Pilot was already in menu
            return;
        }
        if(action->text() > pilotName ||
                action->text().length() == 0)
        {
            ui->menuPilots->insertAction(action, newAct);
            return;
        }
    }

    // It wasn't inserted to any existing actions, so add it now.
    ui->menuPilots->addAction(newAct);
}

void MainWindow::pilotSelected()
{
    QAction *s = qobject_cast<QAction *> (sender());

    qDebug() << "MainWindow::pilotSelected - for " << s->text();

    if(s->isChecked())
    {
        // Add pilot back to map
        ui->mapView->enablePilot(s->text());
    }
    else
    {
        // Remove pilot from map
        ui->mapView->disablePilot(s->text());
    }
}

bool MainWindow::pilotIsEnabled(QString pilotName)
{
    foreach(QAction* action, ui->menuPilots->actions())
    {
        if(action->text() == pilotName)
        {
            return action->isChecked();
        }
    }

    return false;
}

void MainWindow::gotSystemClick(const QString& name)
{
    chatModel->subsetForSystem(name);

    if(name == "")
        ui->listLabel->setText("All Messages:");
    else
        ui->listLabel->setText(name + " Messages:");

    ui->listView->scrollToBottom();
}

void MainWindow::on_actionFindMessages_triggered()
{
    FindMessagesDialog dialog;

    if(dialog.exec() == QDialog::Accepted)
    {
        chatModel->subsetForString(dialog.input());
    }

    if(dialog.input() == "")
        ui->listLabel->setText("All Messages:");
    else
        ui->listLabel->setText("'" + dialog.input() + "'");

    ui->listView->scrollToBottom();
}

void MainWindow::on_actionCustomize_triggered()
{
    ThemeCustomizationDialog dialog;
    dialog.loadValues(m_theme);

    if(dialog.exec() == QDialog::Accepted)
    {
        dialog.sendChanges(m_theme);
    }
}
