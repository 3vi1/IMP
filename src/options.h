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

#include "audio.h"
#include "rulemodel.h"
#include "theme.h"

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
    void saveSettings(QSettings& settings);

    void setAudio(ImpAudio* impAudio);

    int getAlarmDistance();
    int getAlarmVolume();

    bool getAutofollow();
    void setAutofollow(bool checked);
    int getAutoPeriod();
    int getAutoRefresh();

    int getAvatarExpiration();

    QString getBridgePath();

    bool getEssAndKos();
    int getHistoryMax();
    bool getKosCheck();
    int getMapRefresh();
    int getMaxEntries();
    int getPollerRefresh();
    int getRedundantSuppress();

    QString getFontName();
    int getFontSize();
    QStringList getIntelChannels();

    QString getLogPath();
    void setLogPath(QString path);

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

    QString getSoundAlarm();
    QString getSoundEss();
    QString getSoundStatus();
    QString getSoundIsKos();
    QString getSoundNoKos();

    QString getThemeName(){ return m_themeName; }
    ThemeType getThemeType(){ return m_themeType; }
    void setTheme(const QString& n, ThemeType t){
        m_themeName = n; m_themeType = t; }

    RuleModel* ruleModel;

signals:
    void autoPeriodChanged(int msecs);
    void pollerRefreshChanged(int msecs);
    void mapRefreshChanged(int msecs);
    void logDirChanged(const QString&);
    void fontChanged(const QString& fontName, int fontSize);

protected:
    bool eventFilter(QObject *, QEvent *evt);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_alarmTestButton_clicked();
    void on_statusTestButton_clicked();
    void on_volume_sliderReleased();
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

private:
    Ui::Options *ui;

    ImpAudio* audio;
    QString audioPath;

    void readTextElements(QXmlStreamReader& reader, Rule& rule);
    QList<Rule> readRules(QXmlStreamReader& reader);

    bool _autofollow = true;
    bool _smoothAutofollow;
    bool _essAndKos;
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

    QString     m_themeName;
    ThemeType   m_themeType;

    QStringList _intelChannels;

    QList<Rule> _rules;

    QString _soundAlarm;
    QString _soundEss;
    QString _soundIsKos;
    QString _soundNoKos;
    QString _soundStatus;

};

#endif // OPTIONS_H
