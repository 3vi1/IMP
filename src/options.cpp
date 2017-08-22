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

#include "options.h"
#include "ui_options.h"
#include "abstract_os.h"
#include "combodelegate.h"

#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QKeyEvent>
#include <QMessageBox>
#include <QMimeData>
#include <QStandardPaths>
#include <QXmlStreamWriter>

Options::Options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
    ui->intelEdit->installEventFilter(this);

    comboDelegate = new ComboDelegate(this);
    volumeDelegate = new VolumeDelegate(this);
    playDelegate = new PlayDelegate(this);
    connect(playDelegate, &PlayDelegate::playSound,
            this, &Options::testSound);

    rebuildAudioFileList();
    rebuildStyleFileList();

    alarmModel = new AlarmModel(this);
    ui->tableProxAlarms->setModel(alarmModel);
    ui->tableProxAlarms->setEditTriggers(QAbstractItemView::AllEditTriggers);
    ui->tableProxAlarms->verticalHeader()->hide();
    ui->tableProxAlarms->setItemDelegateForColumn(1, comboDelegate);
    ui->tableProxAlarms->setItemDelegateForColumn(2, volumeDelegate);
    ui->tableProxAlarms->setItemDelegateForColumn(3, playDelegate);
    ui->tableProxAlarms->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableProxAlarms->setColumnWidth(0, 50);
    ui->tableProxAlarms->setColumnWidth(2, 300);
    ui->tableProxAlarms->setColumnWidth(3, 50);
    //ui->tableProxAlarms->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    //ui->tableProxAlarms->verticalHeader()->setDefaultSectionSize(48);
    ui->tableProxAlarms->show();

    ruleModel = new RuleModel(this);
    ui->tableView->setModel(ruleModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    ui->tableView->setColumnWidth(0, 30);
    ui->tableView->setColumnWidth(1, 100);
    ui->tableView->setColumnWidth(4, 30);
    ui->tableView->show();
}

Options::~Options()
{
    delete ui;
}

void Options::rebuildAudioFileList()
{
    ui->comboIncomplete->clear();
    ui->clipKosCombo->clear();
    ui->clipNotKosCombo->clear();
    ui->statusCombo->clear();
    ui->essCombo->clear();

    audioPath = appFilesPath() + "/audio/";
    QDir audioDir(audioPath);
    audioDir.setFilter(QDir::Files);

    // Load up audio combos
    foreach(QFileInfo fileInfo, audioDir.entryInfoList())
    {
        if(fileInfo.fileName().endsWith(".dll"))
            continue;

        ui->comboIncomplete->addItem(fileInfo.fileName());
        ui->clipKosCombo->addItem(fileInfo.fileName());
        ui->clipNotKosCombo->addItem(fileInfo.fileName());
        ui->statusCombo->addItem(fileInfo.fileName());
        ui->essCombo->addItem(fileInfo.fileName());

        m_soundList.append(fileInfo.fileName());
    }

    ui->statusCombo->setCurrentIndex(ui->statusCombo->findText(m_soundStatus));
    ui->comboIncomplete->setCurrentIndex(ui->comboIncomplete->findText(m_soundIncomplete));
    ui->clipKosCombo->setCurrentIndex(ui->clipKosCombo->findText(m_soundIsKos));
    ui->clipNotKosCombo->setCurrentIndex(ui->clipNotKosCombo->findText(m_soundNoKos));
    ui->essCombo->setCurrentIndex(ui->essCombo->findText(m_soundEss));

    comboDelegate->setItems(m_soundList);
}

void Options::rebuildStyleFileList()
{
    ui->comboStyle->clear();
    ui->comboStyle->addItem("-None-");

    QString stylePath = appFilesPath() + "/styles/";
    QDir styleDir(stylePath);
    styleDir.setFilter(QDir::Files);

    // Load up style combo
    foreach(QFileInfo fileInfo, styleDir.entryInfoList())
    {
        if(fileInfo.fileName().endsWith(".dll"))
            continue;

        ui->comboStyle->addItem(fileInfo.fileName());
    }

    ui->comboStyle->setCurrentIndex(ui->comboStyle->findText(m_style));
}

void Options::cacheSettings()
{
    QStringList channels;
    for(int i=0; i < ui->intelWidget->count(); i++)
    {
        channels.append(ui->intelWidget->item(i)->text());
    }
    _intelChannels = channels;

    _avatarExpiration = ui->avatarBox->value();
    _historyCount = ui->historySpinBox->value();
    _autoPeriod = ui->autoPeriodSpin->value();
    _autoRefresh = ui->autoRefreshSpin->value();
    _mapRefresh = ui->refreshSpin->value();
    _maxEntries = ui->maxEntriesSpinBox->value();
    _pollerRefresh = ui->pollerSpinBox->value();
    _redundantSuppress = ui->redundantSpinBox->value();

    m_checkForUpdate = ui->checkUpdates->isChecked();
    _kosDouble = ui->checkKosDouble->isChecked();
    _selfSuppress = ui->selfSuppressCheck->isChecked();
    _smoothAutofollow = ui->smoothCheck->isChecked();
    _essAndKos = ui->essBox->isChecked();
    m_showAvatar = ui->checkAvatar->isChecked();

    m_initOldIntel = ui->checkOldIntel->isChecked();

    m_soundStatus = ui->statusCombo->currentText();
    m_soundIncomplete = ui->comboIncomplete->currentText();
    m_soundIsKos = ui->clipKosCombo->currentText();
    m_soundNoKos = ui->clipNotKosCombo->currentText();
    m_soundEss = ui->essCombo->currentText();

    _logPath = ui->logsEdit->text();
    _mapPath = ui->mapEdit->text();
    _bridgePath = ui->bridgeEdit->text();

    _fontName = ui->fontComboBox->currentText();
    _fontSize = ui->fontSpinBox->value();

    m_alarms = alarmModel->getAlarms();
    _rules = ruleModel->getRules();

    m_style = ui->comboStyle->currentText();
}

void Options::restoreSettings()
{
    ui->intelWidget->clear();
    ui->intelWidget->addItems(_intelChannels);

    ui->avatarBox->setValue(_avatarExpiration);
    ui->historySpinBox->setValue(_historyCount);
    ui->autoPeriodSpin->setValue(_autoPeriod);
    ui->autoRefreshSpin->setValue(_autoRefresh);
    ui->maxEntriesSpinBox->setValue(_maxEntries);
    ui->refreshSpin->setValue(_mapRefresh);
    ui->pollerSpinBox->setValue(_pollerRefresh);
    ui->redundantSpinBox->setValue(_redundantSuppress);

    ui->checkUpdates->setChecked(m_checkForUpdate);
    ui->selfSuppressCheck->setChecked(_selfSuppress);
    ui->smoothCheck->setChecked(_smoothAutofollow);
    ui->essBox->setChecked(_essAndKos);
    ui->checkKosDouble->setChecked(_kosDouble);
    ui->checkAvatar->setChecked(m_showAvatar);
    ui->checkOldIntel->setChecked(m_initOldIntel);

    ui->statusCombo->setCurrentIndex(ui->statusCombo->findText(m_soundStatus));
    ui->comboIncomplete->setCurrentIndex(ui->comboIncomplete->findText(m_soundIncomplete));
    ui->clipKosCombo->setCurrentIndex(ui->clipKosCombo->findText(m_soundIsKos));
    ui->clipNotKosCombo->setCurrentIndex(ui->clipNotKosCombo->findText(m_soundNoKos));
    ui->essCombo->setCurrentIndex(ui->essCombo->findText(m_soundEss));

    /* Works on Linux, but not on Windows...
    ui->alarmCombo->setCurrentText(_soundAlarm);
    ui->statusCombo->setCurrentText(_soundStatus);
    ui->clipKosCombo->setCurrentText(_soundIsKos);
    ui->clipNotKosCombo->setCurrentText(_soundNoKos);
    ui->essCombo->setCurrentText(_soundEss);
    */

    ui->logsEdit->setText(_logPath);
    ui->mapEdit->setText(_mapPath);
    ui->bridgeEdit->setText(_bridgePath);

    ui->fontComboBox->setCurrentIndex(ui->fontComboBox->findText(_fontName));
    ui->fontSpinBox->setValue(_fontSize);

    alarmModel->setAlarms(m_alarms);
    ruleModel->setRules(_rules);

    ui->comboStyle->setCurrentIndex(ui->comboStyle->findText(m_style));
}


void Options::loadSettings(QSettings& settings)
{
    _autofollow = settings.value("autofollow", true).toBool();
    _currentRegion = settings.value("currentRegion", "Providence").toString();
    m_themeName = settings.value("themeName", "-Default-").toString();
    m_themeType = settings.value("themeType", ThemeType::THEME_DEFAULT).value<ThemeType>();

    ui->intelWidget->addItems(settings.value("intelChannels",
        QStringList({ "TheCitadel", "North Provi Intel",
          "North Catch Intel", "North Querious Intel" })
                                             ).toStringList());

    QStringList dpList = settings.value("disabledPilots", QStringList()).toStringList();
    m_disabledPilots = m_disabledPilots.fromList(dpList);

    ui->avatarBox->setValue(settings.value("avatarExpiration", 0).toInt());

    ui->historySpinBox->setValue(settings.value("historyCount", 0).toInt());
    ui->autoPeriodSpin->setValue(settings.value("autoPeriod", 4000).toInt());
    ui->autoRefreshSpin->setValue(settings.value("autoRefresh", 33).toInt());
    ui->maxEntriesSpinBox->setValue(settings.value("maxEntriesToLoad", 50).toInt());
    ui->refreshSpin->setValue(settings.value("mapRefresh", 1000).toInt());
    ui->pollerSpinBox->setValue(settings.value("pollerRefresh", 500).toInt());
    ui->redundantSpinBox->setValue(settings.value("redundantSuppress", 30).toInt());

    ui->checkUpdates->setChecked(settings.value("checkForUpdate", true).toBool());
    ui->selfSuppressCheck->setChecked(settings.value("selfSuppress", true).toBool());
    ui->smoothCheck->setChecked(settings.value("smoothAutofollow", true).toBool());
    ui->essBox->setChecked(settings.value("essAndKos", true).toBool());
    ui->checkKosDouble->setChecked(settings.value("kosDouble", true).toBool());
    ui->checkAvatar->setChecked(settings.value("showAvatar", true).toBool());
    ui->checkOldIntel->setChecked(settings.value("initOldIntel", true).toBool());

    // Deprecated - remove after a few versions
    _alarmDistance = settings.value("alarmDistance", 1).toInt();
    _volume = settings.value("volume", 100).toInt();
    audio->setVolume(_volume);
    m_soundAlarm = settings.value("soundAlarm", "red-alert.wav").toString();

    // On Linux, you can just setCurrentText(), but there appears to be a Qt bug on Windows
    // such that it doesn't update the index.
    ui->essCombo->setCurrentIndex(
                ui->essCombo->findText(
                    settings.value("soundEss", "sci-fi-alarm.wav").toString()
                    )
                );
    ui->comboIncomplete->setCurrentIndex(
                ui->clipKosCombo->findText(
                    settings.value("soundIncomplete", "bottle-cap-drop.wav").toString()
                    )
                );
    ui->clipKosCombo->setCurrentIndex(
                ui->clipKosCombo->findText(
                    settings.value("soundIsKos", "140-bpm-wobble-c-in-c.wav").toString()
                    )
                );
    ui->clipNotKosCombo->setCurrentIndex(
                ui->clipNotKosCombo->findText(
                    settings.value("soundNoKos", "toy-hit.wav").toString()
                    )
                );
    ui->statusCombo->setCurrentIndex(
                ui->statusCombo->findText(
                    settings.value("soundStatus", "radio-beep.wav").toString()
                    )
                );

    ui->comboStyle->setCurrentIndex(
                ui->comboStyle->findText(
                    settings.value("style", "-None-").toString()
                    )
                );

    // Hack that works around a problem where null values are written if the previous run
    // exited uncleanly.  This can happen when the parser files aren't found, but
    // I'm just going to brute force fix this for now.
    if(ui->essCombo->currentText() == "") {
        ui->essCombo->setCurrentIndex(
                    ui->essCombo->findText("sci-fi-alarm.wav")
                    );
    }
    if(ui->comboIncomplete->currentText() == "") {
        ui->comboIncomplete->setCurrentIndex(
                    ui->comboIncomplete->findText("bottle-cap-drop.wav")
                    );
    }
    if(ui->clipKosCombo->currentText() == "") {
        ui->clipKosCombo->setCurrentIndex(
                    ui->clipKosCombo->findText("140-bpm-wobble-c-in-c.wav")
                    );
    }
    if(ui->clipNotKosCombo->currentText() == "") {
        ui->clipNotKosCombo->setCurrentIndex(
                ui->clipNotKosCombo->findText("toy-hit.wav")
                );
    }
    if(ui->statusCombo->currentText() == "")
    {
        ui->statusCombo->setCurrentIndex(
                ui->statusCombo->findText("radio-beep.wav")
                );
    }

    if(ui->comboStyle->currentText() == "")
    {
        ui->comboStyle->setCurrentIndex(
                ui->comboStyle->findText("-None-")
                );
    }
    m_style = ui->comboStyle->currentText();
    emit styleChanged(m_style);

    QString logDir;
    logDir = settings.value("logPath", "").toString();

    if(logDir.length() == 0)
    {
#ifdef Q_OS_WIN32
        logDir = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/EVE/logs/Chatlogs";
#elif defined(Q_OS_MAC)
        logDir = QDir::homePath() + "/Library/Application Support/Eve Online/p_drive/User/My Documents/EVE/logs/Chatlogs";
#else
        // Assume Q_OS_LINUX
        logDir = QDir::homePath() + "/Documents/EVE/logs/Chatlogs";
#endif
    }

    ui->logsEdit->setText(logDir);

    qDebug() << "Log Directory " << logDir << "... ";
    if (!QDir(logDir).exists())
    {
        qDebug() << "does not exist." << endl;
        QMessageBox::critical(NULL, "Log Path Not Found", "Log directory " + logDir +
                              " was not found.  If you installed to a nonstandard location, " +
                              "please configure the path from the settings dialog.",
                              "Continue");
    }

    ui->mapEdit->setText(settings.value("mapPath", "http://evemaps.dotlan.net/svg/").toString());
    ui->bridgeEdit->setText(settings.value("bridgePath", "http://eternaldusk.com/imp/jb/").toString());

    m_showBridges = settings.value("showBridges", false).toBool();

    // Font settings
    ui->fontComboBox->setCurrentIndex(
                ui->fontComboBox->findText(
                    settings.value("fontName", "Arial").toString()
                    )
                );
    ui->fontSpinBox->setValue(settings.value("fontSize", 10).toInt());

    QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    QDir dataDir{dataPath};

    // Load rules
    QFile ruleFile(dataDir.absoluteFilePath("imp_rules"));

    if (ruleFile.open(QFile::ReadOnly | QFile::Text))
    {
        QXmlStreamReader reader(&ruleFile);

        while (!reader.atEnd() && !reader.hasError())
        {
            reader.readNext();
            if (reader.isStartElement())
            {
                if (reader.name() == "Rules")
                {
                    ruleModel->setRules(readRules(reader));
                }
            }
        }
    }
    else
    {
        ruleModel->insertRule(true, "Lo[ck]al", " ([Rr][Ee][Dd]|[Kk][Oo][Ss])[\\.!]?$", "play system-grind-01.wav", true);
    }

    // Load alarms
    QFile alarmFile(dataDir.absoluteFilePath("imp_alarms"));

    if (alarmFile.open(QFile::ReadOnly | QFile::Text))
    {
        QXmlStreamReader reader(&alarmFile);

        while (!reader.atEnd() && !reader.hasError())
        {
            reader.readNext();
            if (reader.isStartElement())
            {
                if (reader.name() == "Alarms")
                {
                    alarmModel->setAlarms(readAlarms(reader));
                }
            }
        }
    }
    else
    {
        if(m_soundAlarm.length() > 0)
        {
            // Bring in legacy values, if they're in config.
            for(int i=0; i <= _alarmDistance; i++)
            {
                alarmModel->insertAlarm(m_soundAlarm, _volume/100.0f);
            }
        }
        else
        {
            // New Default
            alarmModel->insertAlarm("red-alert.wav", 1.0f);
            alarmModel->insertAlarm("Danger.wav", 1.0f);
        }
    }


    cacheSettings();
}

QList<Alarm> Options::readAlarms(QXmlStreamReader& reader)
{
    QList<Alarm> alarms;

    while (!reader.atEnd() && !reader.hasError())
    {
        reader.readNext();
        if (reader.isStartElement())
        {
            if (reader.name() == "Alarm")
            {
                Alarm alarm;
                readAlarmTextElements(reader, alarm);
                alarms.append(alarm);
            }
        }
    }

    return alarms;
}

QList<Rule> Options::readRules(QXmlStreamReader& reader)
{
    QList<Rule> rules;

    while (!reader.atEnd() && !reader.hasError())
    {
        reader.readNext();
        if (reader.isStartElement())
        {
            if (reader.name() == "Rule")
            {
                Rule rule;

                foreach(QXmlStreamAttribute attribute, reader.attributes())
                {
                    if (attribute.name() == "Enabled")
                    {
                        rule.enabled = attribute.value().toInt();
                    }
                    else if (attribute.name() == "ContinueOnMatch")
                    {
                        rule.continueOnMatch = attribute.value().toInt();
                    }
                }

                readRuleTextElements(reader, rule);
                rules.append(rule);
            }
        }
    }

    return rules;
}

void Options::readAlarmTextElements(QXmlStreamReader& reader, Alarm& rule)
{
    while (!reader.atEnd() && !reader.hasError())
    {
        reader.readNext();
        if (reader.isStartElement())
        {
            if (reader.name() == "Jumps")
            {
                rule.jumps = reader.readElementText().toInt();
            }
            else if (reader.name() == "Sound")
            {
                rule.file = reader.readElementText();
            }
            else if (reader.name() == "Volume")
            {
                rule.volume = reader.readElementText().toFloat();
                return;
            }
        }
    }

}
void Options::readRuleTextElements(QXmlStreamReader& reader, Rule& rule)
{
    while (!reader.atEnd() && !reader.hasError())
    {
        reader.readNext();
        if (reader.isStartElement())
        {
            if (reader.name() == "Channel")
            {
                rule.channel = reader.readElementText();
            }
            else if (reader.name() == "Match")
            {
                rule.match = reader.readElementText();
            }
            else if (reader.name() == "Action")
            {
                rule.action = reader.readElementText();
                return;
            }
        }
    }
}

void Options::saveSettings() //QSettings& settings)
{
    QString configPath = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    QDir configDir{configPath};
    if (configDir.mkpath(configDir.absolutePath()) && QDir::setCurrent(configDir.absolutePath()))
    {
        // Save configuration options

        qDebug() << "Settings in " << QDir::currentPath() << endl;

        QString fileName = "imp-settings";
        QSettings settings(fileName, QSettings::IniFormat);

        settings.setValue("intelChannels", getIntelChannels());

        settings.setValue("avatarExpiration", getAvatarExpiration());
        settings.setValue("themeName", getThemeName());
        settings.setValue("themeType", getThemeType());
        settings.setValue("historyCount", getHistoryMax());
        settings.setValue("autoPeriod", getAutoPeriod());
        settings.setValue("autoRefresh", getAutoRefresh());
        settings.setValue("mapRefresh", getMapRefresh());
        settings.setValue("maxEntriesToLoad", getMaxEntries());
        settings.setValue("pollerRefresh", getPollerRefresh());
        settings.setValue("redundantSuppress", getRedundantSuppress());

        settings.setValue("checkForUpdate", m_checkForUpdate);
        settings.setValue("showAvatar", m_showAvatar);
        settings.setValue("initOldIntel", m_initOldIntel);

        settings.setValue("selfSuppress", getSelfSuppress());
        settings.setValue("smoothAutofollow", getSmoothAutofollow());
        settings.setValue("essAndKos", getEssAndKos());

        //settings.setValue("soundAlarm", getSoundAlarm());
        settings.setValue("soundStatus", getSoundStatus());
        settings.setValue("soundIncomplete", getSoundIncompleteKos());
        settings.setValue("soundIsKos", getSoundIsKos());
        settings.setValue("soundNoKos", getSoundNoKos());
        settings.setValue("soundEss", getSoundEss());

        settings.setValue("bridgePath", getBridgePath());
        settings.setValue("logPath", getLogPath());
        settings.setValue("mapPath", getMapPath());
        settings.setValue("currentRegion", _currentRegion);

        settings.setValue("fontName", getFontName());
        settings.setValue("fontSize", getFontSize());

        settings.setValue("style", getStyle());

        QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
        QDir dataDir{dataPath};

        // Save rules
        QFile ruleFile(dataDir.absoluteFilePath("imp_rules"));

        if (!ruleFile.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(NULL, "Error Opening File", "Could not open output file " +
                                 ruleFile.fileName() + ".", QMessageBox::Ok);
            return;
        }

        QXmlStreamWriter xmlWriter(&ruleFile);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartDocument();
        xmlWriter.writeStartElement("Rules");

        QList<Rule> rules = ruleModel->getRules();
        for (int i = 0; i < rules.count(); ++i)
        {
            xmlWriter.writeStartElement("Rule");
            xmlWriter.writeAttribute("Enabled", QString::number(rules[i].enabled));
            xmlWriter.writeAttribute("ContinueOnMatch", QString::number(rules[i].continueOnMatch));
            xmlWriter.writeTextElement("Channel", rules[i].channel);
            xmlWriter.writeTextElement("Match", rules[i].match);
            xmlWriter.writeTextElement("Action", rules[i].action);
            xmlWriter.writeEndElement();
        }
        xmlWriter.writeEndDocument();
        ruleFile.close();

        // Save alarms
        QFile alarmFile(dataDir.absoluteFilePath("imp_alarms"));

        if (!alarmFile.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(NULL, "Error Opening File", "Could not open output file " +
                                 alarmFile.fileName() + ".", QMessageBox::Ok);
            return;
        }

        QXmlStreamWriter alarmXmlWriter(&alarmFile);
        alarmXmlWriter.setAutoFormatting(true);
        alarmXmlWriter.writeStartDocument();
        alarmXmlWriter.writeStartElement("Alarms");

        QList<Alarm> alarms = alarmModel->getAlarms();
        for (int i = 0; i < alarms.count(); ++i)
        {
            alarmXmlWriter.writeStartElement("Alarm");
            alarmXmlWriter.writeTextElement("Jumps", QString::number(alarms[i].jumps));
            alarmXmlWriter.writeTextElement("Sound", alarms[i].file);
            alarmXmlWriter.writeTextElement("Volume", QString::number(alarms[i].volume));
            alarmXmlWriter.writeEndElement();
        }
        alarmXmlWriter.writeEndDocument();
        alarmFile.close();
    }
}

void Options::setAudio(ImpAudio* impAudio)
{
    audio = impAudio;
}

int Options::getAvatarExpiration()
{
    return ui->avatarBox->value();
}

bool Options::getCheckForUpdate()
{
    return ui->checkUpdates->isChecked();
}

bool Options::getEssAndKos()
{
    return ui->essBox->isChecked();
}

int Options::getHistoryMax()
{
    return ui->historySpinBox->value();
}

bool Options::getAutofollow()
{
    return _autofollow;
}

void Options::setAutofollow(bool checked)
{
    _autofollow = checked;
}

int Options::getAutoPeriod()
{
    return _autoPeriod;
}

int Options::getAutoRefresh()
{
    return _autoRefresh;
}

QString Options::getBridgePath()
{
    return _bridgePath;
}

QString Options::getFontName()
{
    return _fontName;
}

int Options::getFontSize()
{
    return _fontSize;
}

QStringList Options::getIntelChannels()
{
    QStringList channels = _intelChannels;
    channels.append("*Debugging*");
    return channels;
}

QString Options::getLogPath()
{
    return ui->logsEdit->text();
}

void Options::setLogPath(QString path)
{
    ui->logsEdit->setText(path);
}

QString Options::getMapPath()
{
    return ui->mapEdit->text();
}

void Options::setMapPath(QString path)
{
    ui->mapEdit->setText(path);
}

int Options::getMapRefresh()
{
    return _mapRefresh;
}

int Options::getMaxEntries()
{
    // Maximum number of log entries to load on restart
    return _maxEntries;
}


int Options::getPollerRefresh()
{
    return _pollerRefresh;
}

int Options::getRedundantSuppress()
{
    return _redundantSuppress;
}

bool Options::getSmoothAutofollow()
{
    return ui->smoothCheck->isChecked();
}

QString Options::getSoundEss()
{
    return ui->essCombo->currentText();
}

QString Options::getSoundIncompleteKos()
{
    return ui->comboIncomplete->currentText();
}

QString Options::getSoundIsKos()
{
    return ui->clipKosCombo->currentText();
}

QString Options::getSoundNoKos()
{
    return ui->clipNotKosCombo->currentText();
}

bool Options::getKosCheck()
{
    return ui->kosCheck->isChecked();
}

QString Options::getRegion()
{
    return _currentRegion;
}

void Options::setRegion(QString regionName)
{
    _currentRegion = regionName;
}

QString Options::getSoundStatus()
{
    return ui->statusCombo->currentText();
}

void Options::on_buttonBox_accepted()
{
    // If the log path was changed, let the main program know
    // so that it can rebuild the logcatcher.
    if(ui->logsEdit->text() != _logPath)
    {
        emit logDirChanged(ui->logsEdit->text());
    }

    if(ui->fontComboBox->currentText() != _fontName ||
            ui->fontSpinBox->value() != _fontSize)
    {
        emit fontChanged(ui->fontComboBox->currentText(), ui->fontSpinBox->value());
    }

    if(ui->refreshSpin->value() != _mapRefresh)
    {
        _mapRefresh = ui->refreshSpin->value();
        emit mapRefreshChanged(getMapRefresh());
    }

    if(ui->pollerSpinBox->value() != _pollerRefresh)
    {
        _pollerRefresh = ui->pollerSpinBox->value();
        emit pollerRefreshChanged(getPollerRefresh());
    }

    if(ui->autoPeriodSpin->value() != _autoPeriod)
    {
        _autoPeriod = ui->pollerSpinBox->value();
        emit autoPeriodChanged(getAutoPeriod());
    }

    if(ui->comboStyle->currentText() != m_style)
    {
        m_style = ui->comboStyle->currentText();
        emit styleChanged(m_style);
    }

    cacheSettings();
    saveSettings();
}

void Options::on_buttonBox_rejected()
{
    restoreSettings();
}

void Options::on_statusTestButton_clicked()
{
    audio->playLocalFile(getSoundStatus());
}

void Options::on_clipKosTestButton_clicked()
{
    audio->playLocalFile(getSoundIsKos());
}

void Options::on_clipNotKosTestButton_clicked()
{
    audio->playLocalFile(getSoundNoKos());
}

void Options::on_incompleteTestButton_clicked()
{
    audio->playLocalFile(getSoundIncompleteKos());
}

void Options::on_ruleInsertButton_clicked()
{
    //ruleModel->insertRule(ui->tableView->selectionModel()->selectedIndexes());
    QModelIndexList list = ui->tableProxAlarms->selectionModel()->selectedIndexes();
    int i = list.count() < 1 ? -1 : list[0].row();
    ruleModel->insertRow(i);
}

void Options::on_ruleRemoveButton_clicked()
{
    //ruleModel->removeRule(ui->tableView->selectionModel()->selectedIndexes());
    QModelIndexList list = ui->tableProxAlarms->selectionModel()->selectedIndexes();
    int i = list.count() < 1 ? -1 : list[0].row();
    ruleModel->removeRow(i);
}

void Options::on_essTestButton_clicked()
{
    audio->playLocalFile(getSoundEss());
}

void Options::on_mapEdit_editingFinished()
{
    if(ui->mapEdit->text().right(1) != "/")
    {
        ui->mapEdit->setText(ui->mapEdit->text() + "/");
    }
}

void Options::on_logsButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, "Select Log Directory", _logPath);

    if(dir.length())
        ui->logsEdit->setText(dir);
}

void Options::on_addIntelButton_clicked()
{
    if(ui->intelEdit->text().length() > 0)
    {
        // Check to see if this channel already exists
        for(int i=0; i < ui->intelWidget->count(); i++)
        {
            if(ui->intelWidget->item(i)->text() == ui->intelEdit->text())
                return;
        }

        ui->intelWidget->addItem(ui->intelEdit->text());
    }
    ui->intelEdit->clear();
}

void Options::on_delIntelButton_clicked()
{
    // If they selected something, it's getting removed!
    if(ui->intelWidget->selectedItems().count() > 0)
    {
        foreach(QListWidgetItem* item, ui->intelWidget->selectedItems())
        {
            ui->intelWidget->takeItem(ui->intelWidget->row(item));
        }
    }
    else if(ui->intelEdit->text() != "")
    {
        // Lets let people remove them by name too.
        for(int i=0; i < ui->intelWidget->count(); i++)
        {
            if(ui->intelWidget->item(i)->text() == ui->intelEdit->text())
            {
                ui->intelWidget->takeItem(i);
                return;
            }
        }
    }
}

void Options::on_intelWidget_itemClicked(QListWidgetItem *item)
{
    ui->intelEdit->setText(item->text());
}

bool Options::eventFilter(QObject*, QEvent *evt)
{
    if(evt->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(evt);
        if((keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return) &&
                ui->intelEdit->hasFocus())
        {
            // Mark event as handled if someone pressed enter while in the
            // intelChannel line edit, so that Okay doesn't fire.
            on_addIntelButton_clicked();
            return true;
        }
    }
    return false;
}

bool Options::getSelfSuppress()
{
    return _selfSuppress;
}

void Options::on_bridgeEdit_editingFinished()
{
    if(ui->bridgeEdit->text().right(1) != "/")
    {
        ui->bridgeEdit->setText(ui->bridgeEdit->text() + "/");
    }
}

bool Options::showAvatar()
{
    return m_showAvatar;
}

bool Options::getKosOnDouble()
{
    return _kosDouble;
}

void Options::disablePilot(const QString& pilotName)
{
    m_disabledPilots.insert(pilotName);
}

void Options::enablePilot(const QString& pilotName)
{
    m_disabledPilots.remove(pilotName);
}

bool Options::pilotIsDisabled(const QString &pilotName)
{
    return m_disabledPilots.contains(pilotName);
}

QStringList Options::getDisabledPilots()
{
    return m_disabledPilots.toList();
}

void Options::on_buttonCheck_clicked()
{
    emit checkForUpdate();
}

void Options::on_btnInsertProx_clicked()
{
    QModelIndexList list = ui->tableProxAlarms->selectionModel()->selectedIndexes();
    int i = list.count() < 1 ? -1 : list[0].row();
    alarmModel->insertRow(i);
}

void Options::on_btnRemoveProx_clicked()
{
    QModelIndexList list = ui->tableProxAlarms->selectionModel()->selectedIndexes();
    int i = list.count() < 1 ? -1 : list[0].row();
    alarmModel->removeRow(i);
}

void Options::testSound(const QString& soundFileName, float volume)
{
    audio->playLocalFile(soundFileName, volume);
}

bool Options::withinAlarmDistance(int distance)
{
    qDebug() << "Options::withinAlarmDistance : " << alarmModel->count() << " / " << distance;
    return alarmModel->count() > distance;
}

const Alarm& Options::getAlarmForDistance(int distance)
{
    return alarmModel->at(distance);
}
