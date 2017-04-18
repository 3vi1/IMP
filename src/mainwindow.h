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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QClipboard>
#include <QMainWindow>
#include <QShortcut>
#include <QString>

#include "asyncinfo.h"
#include "audio.h"
#include "bridgemap.h"
#include "chatitemdelegate.h"
#include "chatmodel.h"
#include "info.h"
#include "finddialog.h"
#include "logcatcher.h"
#include "map.h"
#include "meta.h"
#include "options.h"
#include "parser.h"
#include "theme.h"
#include "themedialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addMessage(const MessageInfo& message);
    void doUserActions(const MessageInfo& message);

public slots:
    void failedGettingRegionFile(QNetworkReply::NetworkError err);
    void gotRegionFile();

    void failedGettingBridgeFile(QNetworkReply::NetworkError err);
    void gotBridgeFile();

    void fileChanged(const QString &absoluteFilePath);
    void gotAutoPeriodChange(int msecs);
    void gotAvatar(PilotEntry* pilotEntry);
    void gotKosError(const QString &pilotName);
    void gotKosReply(const QString &pilotName, const QList<KosEntry>& entries);
    void gotRblReply(QString name, bool rbl, int corpNum = 0);
    void gotEssReply(const QList<KosEntry>& entries);
    void gotMapRefreshChange(int msecs);
    void gotNewPilot(const QString& pilotName);
    void gotPollerRefreshChange(int msecs);
    void gotSystemClick(const QString& name);
    void findLocation(const QString& systemName);
    void logDirChanged(const QString& dir);
    void gotOpacity(int delta);
    void saveSettings();

private slots:
    void changeFont(const QString& fontName, int fontSize);
    void clipboardUpdated();
    void pilotSelected();
    void themeSelected();
    void updatePosition();
    void onPilotLocation(const QString &pilotName, const QString &systemName);
    void on_actionAbout_triggered();
    void on_actionOptions_triggered();
    void on_actionF_YH5B_triggered();
    void on_actionN_RMSH_triggered();
    void on_actionAuto_follow_triggered();
    void on_actionProvidence_triggered();
    void on_actionCatch_triggered();
    void on_actionQuerious_triggered();
    void on_actionSystem_triggered();
    void on_actionShow_Bridges_triggered(bool checked);
    void on_actionSave_As_Theme_triggered();
    void on_actionFindMessages_triggered();
    void on_actionCustomize_triggered();
    void on_actionReset_Rotation_triggered();
    void on_action_Always_on_Top_triggered(bool checked);
    void on_listView_doubleClicked(const QModelIndex &index);
    void on_actionToggle_Frameless_triggered();

private:
    void initParsing();
    void initThemes();
    void addThemesFromSubdirectories(QDir dir, ThemeType themeType);
    void addThemeToMenu(QString name, ThemeType);
    void opacityChange(QString obj, ThemeObject objType);
    void scaleChange(QString obj, ThemeObject objType);
    void customizeShape(QString obj, ThemeObject objType);

    void doRedByLastCheck(const QString& name, int id);

    void loadMap();
    void loadBridges();

    void loadSettings();

    bool pilotIsEnabled(QString pilotName);

    void positionTo(const QString& systemName);

    void changeImpStatus(const QString& text);
    void changeTheme(const QString& themeName, ThemeType themeType);

    QString shortName(const QString &absoluteFilePath);
    void switchToRegion(const QString& currentRegion);
    void updateRegionMenu(const QString& currentRegion);

    Ui::MainWindow*         ui;
    bool                    frameless = false;
    ChatModel*              chatModel;
    ChatItemDelegate        m_cid;
    QShortcut*              findShortcut;
    Theme*                  m_theme = NULL;
    ImpAudio                audio;

    Info                    info;
    Options                 options;
    FindDialog              find;

    LogCatcher*             lc = NULL;
    Parser*                 parser = NULL;

    QNetworkAccessManager   manager;
    QNetworkReply*          reply;

    Map*                    regionMap = NULL;
    QTransform              m_mapTransform;
    bool                    mapLoading = true;
    bool                    errorRetrievingRegionFile = false;

    BridgeMap* bridgeMap = NULL;
    bool bridgeLoading = true;
    bool errorRetrievingBridgeFile = false;

    QMap<QString, PilotEntry> pilotCache;

    int pilotsBeingChecked = 0;
    bool kosSoundPlayed = false;
    QString m_lastClipboard;

    QDateTime lastAlertTime;
    QString lastAlertSystem = "";

    QPoint destinationPos;
    int haltedFor = 0;
    QPoint lastPos;
    QTimer* positionTimer = NULL;

    QPointF startPos;
    qint64 startTime = 0;
    int timeToScroll = 4000;

    LogInfo impLogInfo = { "*IMP*", QFileInfo(), "Khasm Kaotiqa", "None", 0 };

    // Used to restore system rotation until I take the time to figure out
    // how to pull it out of the transform matrix and level systems at
    // restart.
    qreal m_savedSystemRotation = 0;
};

#endif // MAINWINDOW_H
