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
#include <QMessageBox>
#include <QStandardPaths>


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

    setBackColor(Qt::white);
    setLineColor(Qt::black);

    // Set default attributes
    setAttribute("pilotGraphic",    PILOT, "", "graphic",
                 ":/graphics/blue_circle_100.svg");
    setAttribute("pilotOpacity",    PILOT, "", "opacity", 1.0);
    setAttribute("pilotScale",      PILOT, "", "scale", 0.2);
    setAttribute("pilotZ",          PILOT, "", "z", -0.5);
    setAttribute("pilotXOffset",    PILOT, "", "xOffset", -0.0);
    setAttribute("pilotYOffset",    PILOT, "", "yOffset", -0.0);

    setAttribute("findGraphic",     FIND, "", "graphic",
                 ":/graphics/triangle_orange.svg");
    setAttribute("findOpacity",     FIND, "", "opacity", 0.7);
    setAttribute("findScale",       FIND, "", "scale", 1.0);
    setAttribute("findZ",           FIND, "", "z", -0.5);
    setAttribute("findXOffset",     FIND, "", "xOffset", 0);
    setAttribute("findYOffset",     FIND, "", "yOffset", 0);

    setAttribute("defaultNameFont", SYSTEM, "font", "name",
                 QStringList({"Tahoma", QString::number(4)}) );
    setAttribute("defaultTimeFont", SYSTEM, "font", "time",
                 QStringList({"Arial", QString::number(4)}) );

    setAttribute("backgroundImage", SYSTEM, "", "background", "");

    if(m_name != "-Default-")
    {
        // Attempt to load theme...
        QString themePath = dir.absolutePath() + "/" + m_name;
        QString absoluteFilePath = themePath + m_themeIni;
        qDebug() << "path=" << absoluteFilePath;

        if(QFile(absoluteFilePath).exists())
        {
            QSettings settings(absoluteFilePath, QSettings::IniFormat);

            setBackColor(settings.value("backColor").value<QColor>());
            setLineColor(settings.value("lineColor").value<QColor>());

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
    packageImage(themePath, "findGraphic");
    packageImage(themePath, "backgroundGraphic");

    QSettings settings(themePath + m_themeIni, QSettings::IniFormat);

    settings.setValue("name", m_name);
    settings.setValue("backColor", m_backColor);
    settings.setValue("lineColor", m_lineColor);

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
        qDebug() << "Theme::getAttribute for unknown attribute:  " <<
                    saveName << ".  Returning a default instead.";

        if(saveName == "pilotGraphic")
            return ":/graphics/blue_circle_100.svg";
        if(saveName == "pilotOpacity")
            return 1.0;
        if(saveName == "pilotScale")
            return 0.2;
        if(saveName == "pilotZ")
            return -0.5;
        if(saveName == "pilotXOffset")
            return 0.0;
        if(saveName == "pilotYOffset")
            return 0.0;

        if(saveName == "findGraphic")
            return ":/graphics/triangle_orange.svg";
        if(saveName == "findOpacity")
            return -0.7;
        if(saveName == "findScale")
            return 1.0;
        if(saveName == "findZ")
            return -0.5;
        if(saveName == "findXOffset")
            return 0.0;
        if(saveName == "findYOffset")
            return 0.0;

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
