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

#ifndef OPTIONS_H
#define OPTIONS_H

#include "alarmmodel.h"
#include "audio.h"
#include "combodelegate.h"
#include "playdelegate.h"
#include "rulemodel.h"
#include "theme.h"
#include "volumedelegate.h"

#include <QDialog>
#include <QFileDialog>
#include <QListWidgetItem>
#include <QSettings>
#include <QXmlStreamReader>

namespace Ui {
class Options;
}

class Options : public QDialog
{
    Q_OBJECT

public:
    explicit Options(QWidget *parent = 0);
    ~Options();

    void cacheSettings();
    void restoreSettings();

    void loadSettings(QSettings& settings);
    void saveSettings(); //QSettings& settings);

    void setAudio(ImpAudio* impAudio);

    bool getAutofollow();
    void setAutofollow(bool checked);
    int getAutoPeriod();
    int getAutoRefresh();

    int getAvatarExpiration();

    QString getBridgePath();

    bool getShowBridges(){return m_showBridges;}
    void showBridges(bool b){m_showBridges = b;}

    bool getCheckForUpdate();
    bool getEssAndKos();
    int getHistoryMax();
    bool getInitOldIntel() {return m_initOldIntel;}
    bool getKosCheck();
    bool getKosOnDouble();
    int getMapRefresh();
    int getMaxEntries();
    int getPollerRefresh();
    int getRedundantSuppress();

    QString getFontName();
    int getFontSize();
    QStringList getIntelChannels();

    QString getLogPath();
    void setLogPath(QString path);

    QString getStyle() {return m_style;}

    QColor getMapBackgroundColor();
    void setMapBackgroundColor(QColor color);
    QColor getMapLinesColor();
    void setMapLinesColor(QColor color);

    QString getMapPath();
    void setMapPath(QString path);

    QString getRegion();
    void setRegion(QString map);

    bool getSelfSuppress();
    bool getSmoothAutofollow();

    QString getSoundEss();
    QString getSoundStatus();
    QString getSoundIncompleteKos();
    QString getSoundIsKos();
    QString getSoundNoKos();

    bool musicEnabled();

    void rebuildAudioFileList();
    void rebuildStyleFileList();

    bool showAvatar();

    void disablePilot(const QString& pilotName);
    void enablePilot(const QString& pilotName);
    bool pilotIsDisabled(const QString& pilotName);
    QStringList getDisabledPilots();

    QString getThemeName(){ return m_themeName; }
    ThemeType getThemeType(){ return m_themeType; }
    void setTheme(const QString& n, ThemeType t){ m_themeName = n; m_themeType = t; }

    bool withinAlarmDistance(int distance);
    const Alarm& getAlarmForDistance(int distance);

    AlarmModel* alarmModel;
    RuleModel* ruleModel;

signals:
    void autoPeriodChanged(int msecs);
    void checkForUpdate();
    void pollerRefreshChanged(int msecs);
    void mapRefreshChanged(int msecs);
    void logDirChanged(const QString&);
    void fontChanged(const QString& fontName, int fontSize);
    void styleChanged(const QString styleName);
    void okayPressed();
    void changeAudio(AudioEngine);

public slots:
    void testSound(const QString& soundFileName, float volume);

protected:
    bool eventFilter(QObject *, QEvent *evt);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_statusTestButton_clicked();
    void on_clipKosTestButton_clicked();
    void on_clipNotKosTestButton_clicked();
    void on_ruleInsertButton_clicked();
    void on_ruleRemoveButton_clicked();
    void on_essTestButton_clicked();
    void on_mapEdit_editingFinished();
    void on_logsButton_clicked();
    void on_addIntelButton_clicked();
    void on_delIntelButton_clicked();
    void on_intelWidget_itemClicked(QListWidgetItem *item);
    void on_bridgeEdit_editingFinished();
    void on_incompleteTestButton_clicked();
    void on_buttonCheck_clicked();
    void on_btnInsertProx_clicked();
    void on_btnRemoveProx_clicked();
    void on_radioAudioQt_clicked();
    void on_radioAudioSFML_clicked();

private:
    Ui::Options *ui;
    ComboDelegate* comboDelegate;
    PlayDelegate* playDelegate;
    VolumeDelegate* volumeDelegate;

    ImpAudio* audio;
    QString audioPath;

    void readAlarmTextElements(QXmlStreamReader& reader, Alarm& rule);
    QList<Alarm> readAlarms(QXmlStreamReader& reader);

    void readRuleTextElements(QXmlStreamReader& reader, Rule& rule);
    QList<Rule> readRules(QXmlStreamReader& reader);

    bool _autofollow = true;
    bool m_checkForUpdate = true;
    bool m_disableMusic = false;
    bool m_initOldIntel = true;
    bool m_showAvatar = true;
    bool m_showBridges = false;
    bool _smoothAutofollow;
    bool _essAndKos;
    bool _kosDouble;
    bool _selfSuppress;

    int _alarmDistance = 1;
    int _avatarExpiration = 7;
    int _fontSize = 10;
    int _historyCount = 0;
    int _maxEntries = 50;
    int _volume = 100;
    int _autoRefresh = 33;
    int _autoPeriod = 4000;
    int _mapRefresh = 3000;
    int _pollerRefresh = 500;
    int _redundantSuppress = 30;

    QString _bridgePath;
    QString _fontName;
    QString _logPath;
    QString _mapPath;
    QString _currentRegion;

    QString     m_style = "-None-";
    QString     m_themeName;
    ThemeType   m_themeType;

    QStringList _intelChannels;
    //QSet<QString> m_disabledPilots;
    QStringList m_disabledPilots;

    QList<Rule> _rules;
    QList<Alarm> m_alarms;

    QStringList m_soundList;
    QString m_soundAlarm = "";
    QString m_soundEss;
    QString m_soundIncomplete;
    QString m_soundIsKos;
    QString m_soundNoKos;
    QString m_soundStatus;
};

#endif // OPTIONS_H
