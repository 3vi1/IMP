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

#include "theme.h"
#include "abstract_os.h"
#include "themedialog.h"

#include <QCoreApplication>
#include <QDebug>
#include <QMap>
#include <QMessageBox>
#include <QStandardPaths>

const QMap<QString,QVariant> defaults = {
    {"backColor", QColor(Qt::white)},
    {"backGraphic", ""},
    {"backOpacity", 1.0},
    {"backScale", 1.0},
    {"backXOffset", 0},
    {"backYOffset", 0},
    {"backZ", -10.0},

    {"findGraphic", ":/graphics/triangle_orange.svg"},
    {"findOpacity", 0.7},
    {"findScale", 1.0},
    {"findXOffset", 0},
    {"findYOffset", 0},
    {"findZ", -0.5},

    {"lineColor", QColor(Qt::black)},
    {"lineOpacity", 1.0},
    {"lineWidth", 1.0},
    {"lineXOffset", 0},
    {"lineYOffset", 0},
    {"lineZ", -1},

    {"pilotGraphic", ":/graphics/blue_circle_100.svg"},
    {"pilotOpacity", 1.0},
    {"pilotScale", 0.2},
    {"pilotXOffset", 0},
    {"pilotYOffset", 0},
    {"pilotZ", -0.5},

    {"systemGraphic", ":/graphics/systems.svg"},
    {"systemOpacity", 1.0},
    {"systemScale", 1.0},
    {"systemXOffset", 0.0},
    {"systemYOffset", 0.0},
    {"systemZ", 0},

    {"wormholeGraphic", ":/graphics/wormhole.svg"},
    {"wormholeOpacity", 0.8},
    {"wormholeScale", 0.05},
    {"wormholeXOffset", 23.0},
    {"wormholeYOffset", 10.0},
    {"wormholeZ", 1},

    {"defaultNameFont", QStringList({"Tahoma", QString::number(6)}) },
    {"defaultTimeFont", QStringList({"Arial", QString::number(6)}) }
};

Theme::Theme(QObject *parent) : QObject(parent)
{
    qRegisterMetaTypeStreamOperators<AttributeMap>("AttributeMap");

    m_defaultDir = QDir(appFilesPath() + "/themes");

    m_userDir = QDir{QStandardPaths::writableLocation(
                QStandardPaths::AppLocalDataLocation
                ) + "/themes"};
}

void Theme::load(const QString& name, ThemeType themeType)
{
    m_name = name;

    if(m_name.length() == 0)
        return;

    QDir dir;
    if(themeType == ThemeType::THEME_DEFAULT)
    {
        dir = m_defaultDir;
    }
    else
    {
        dir = m_userDir;
    }

    // Background/Map attributes
    setAttribute("backColor",   MAP, "back", "color", defaults["backColor"]);
    setAttribute("backGraphic", MAP, "back", "graphic",  defaults["backGraphic"]);
    setAttribute("backOpacity", MAP, "back", "opacity", defaults["backOpacity"]);
    setAttribute("backScale",   MAP, "back", "scale",  defaults["backScale"]);
    setAttribute("backXOffset", MAP, "back", "xOffset",  defaults["backXOffset"]);
    setAttribute("backYOffset", MAP, "back", "yOffset", defaults["backYOffset"]);
    setAttribute("backZ",       MAP, "back", "z", defaults["backZ"]);

    setAttribute("findGraphic", FIND, "find", "graphic", defaults["findGraphic"]);
    setAttribute("findOpacity", FIND, "find", "opacity", defaults["findOpacity"]);
    setAttribute("findScale",   FIND, "find", "scale", defaults["findScale"]);
    setAttribute("findXOffset", FIND, "find", "xOffset", defaults["findXOffset"]);
    setAttribute("findYOffset", FIND, "find", "yOffset", defaults["findYOffset"]);
    setAttribute("findZ",       FIND, "find", "z", defaults["findZ"]);

    setAttribute("lineColor",   LINES, "line", "color",  defaults["lineColor"]);
    setAttribute("lineOpacity", LINES, "line", "opacity", defaults["lineOpacity"]);
    setAttribute("lineWidth",   LINES, "line", "width", defaults["lineWidth"]);
    setAttribute("lineXOffset", LINES, "line", "xOffset", defaults["lineXOffset"]);
    setAttribute("lineYOffset", LINES, "line", "yOffset", defaults["lineYOffset"]);
    setAttribute("lineZ",       LINES, "line", "z", defaults["lineZ"]);

    setAttribute("pilotGraphic",    PILOT, "pilot", "graphic", defaults["pilotGraphic"]);
    setAttribute("pilotOpacity",    PILOT, "pilot", "opacity", defaults["pilotOpacity"]);
    setAttribute("pilotScale",      PILOT, "pilot", "scale", defaults["pilotScale"]);
    setAttribute("pilotXOffset",    PILOT, "pilot", "xOffset", defaults["pilotXOffset"]);
    setAttribute("pilotYOffset",    PILOT, "pilot", "yOffset", defaults["pilotYOffset"]);
    setAttribute("pilotZ",          PILOT, "pilot", "z", defaults["pilotZ"]);

    setAttribute("defaultNameFont", SYSTEM, "font", "name", defaults["defaultNameFont"] );
    setAttribute("defaultTimeFont", SYSTEM, "font", "time", defaults["defaultTimeFont"] );
    setAttribute("systemGraphic",   SYSTEM, "system", "graphic", defaults["systemGraphic"]);
    setAttribute("systemOpacity",   SYSTEM, "system", "opacity", defaults["systemOpacity"]);
    setAttribute("systemScale",     SYSTEM, "system", "scale", defaults["systemScale"]);
    setAttribute("systemXOffset",   SYSTEM, "system", "xOffset", defaults["systemXOffset"]);
    setAttribute("systemYOffset",   SYSTEM, "system", "yOffset", defaults["systemYOffset"]);
    setAttribute("systemZ",         SYSTEM, "system", "z", defaults["systemZ"]);

    setAttribute("wormholeGraphic",    WORMHOLES, "wormhole", "graphic", defaults["wormholeGraphic"]);
    setAttribute("wormholeOpacity",    WORMHOLES, "wormhole", "opacity", defaults["wormholeOpacity"]);
    setAttribute("wormholeScale",      WORMHOLES, "wormhole", "scale", defaults["wormholeScale"]);
    setAttribute("wormholeXOffset",    WORMHOLES, "wormhole", "xOffset", defaults["wormholeXOffset"]);
    setAttribute("wormholeYOffset",    WORMHOLES, "wormhole", "yOffset", defaults["wormholeYOffset"]);
    setAttribute("wormholeZ",          WORMHOLES, "wormhole", "z", defaults["wormholeZ"]);

    if(m_name != "-Default-")
    {
        // Attempt to load theme...
        QString themePath = dir.absolutePath() + "/" + m_name;
        QString absoluteFilePath = themePath + m_themeIni;
        qDebug() << "path=" << absoluteFilePath;

        if(QFile(absoluteFilePath).exists())
        {
            QSettings settings(absoluteFilePath, QSettings::IniFormat);

            attributes = (settings.value("attributes").value<AttributeMap>());

            foreach(QString key, attributes.keys())
            {
                if(key.contains("Graphic") &&
                        !attributes[key].data.toString().contains('/'))
                {
                    attributes[key].data = themePath + '/' + attributes[key].data.toString();
                    qDebug() << "Modified path " + attributes[key].data.toString();
                }
                sendUpdate(attributes[key]);
            }
        }
    }
}

bool Theme::save(const QString &m_name)
{        
    QString themePath = m_userDir.absolutePath() + "/" + m_name;
    if (!m_userDir.mkpath(themePath))
    {
        QMessageBox::critical(NULL, "Error Creating Theme Subdirectory",
                              "Could not create the theme's subdirectory.  "
                              "Please check permissions on " +
                              m_userDir.absolutePath(), QMessageBox::Ok);
        return false;
    }

    // Copy in any non-local assets and update the links to them
    packageImage(themePath, "pilotGraphic");
    packageImage(themePath, "wormholeGraphic");
    packageImage(themePath, "findGraphic");
    packageImage(themePath, "backGraphic");

    QSettings settings(themePath + m_themeIni, QSettings::IniFormat);

    settings.setValue("name", m_name);

    settings.setValue("attributes", QVariant::fromValue<AttributeMap>(attributes));

    return true;
}

void Theme::packageImage(const QString& themePath, const QString& saveName)
{
    QString graphicPath = attributes[saveName].data.toString();
    if(graphicPath.contains("/") &&
            !graphicPath.startsWith(":/") &&
            QFileInfo(graphicPath).absolutePath() != themePath)
    {

        QString fileName = QFileInfo(graphicPath).fileName();
        QString newFile = themePath + '/' + fileName;
        if(QFile(newFile).exists())
        {
            QFile(newFile).remove();
        }
        QFile::copy(graphicPath, newFile);
        attributes[saveName].data = fileName;
    }
}

QVariant Theme::getAttribute(const QString& saveName)
{
    if(attributes.contains(saveName))
        return attributes[saveName].data;
    else
    {
        qDebug() << "Theme::getAttribute for unset attribute:  " <<
                    saveName << ".  Attempting to return a default.";

        if(defaults.contains(saveName))
            return defaults[saveName];

        qDebug() << "Theme::getAttribute for unknown attribute:  " <<
                    saveName << ".  Returning a null instead.";

        return QString("");
    }
}

void Theme::setAttribute(const QString& saveName,
                         ThemeObject objType,
                         QString name,
                         QString member,
                         QVariant data)
{
    attributes[saveName] = {objType, name, member, data};
    emit sendUpdate(attributes[saveName]);
}

bool Theme::attributeExists(const QString& name)
{
    return attributes.contains(name);
}
