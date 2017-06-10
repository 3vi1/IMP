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

#include "map.h"

#include <QColor>
#include <QDebug>
#include <QMessageBox>
#include <QQueue>
#include <QRegExp>

Map::Map(QObject *parent) : QObject(parent)
{
    m_timer = new QTimer(this);
    setRefresh(1000);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateActiveSystems()));
}

void Map::setRefresh(int msecs)
{
    m_timer->setInterval(msecs);
}

void Map::startUpdates()
{
    updateActiveSystems();
    if(!m_timer->isActive())
    {
        m_timer->start();
    }
}

void Map::update()
{
    updateActiveSystems();
}

void Map::loadXml(QFile& file)
{
    if (!file.open(QIODevice::ReadOnly))
        return;
    if (!m_domDoc.setContent(&file)) {
        file.close();
        return;
    }
    file.close();

    processNode(m_domDoc.documentElement());
}

void Map::loadXml(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly))
    {
        return;
    }

    return loadXml(file);
}

bool Map::contains(const QString& systemName)
{
    return m_systemMap.contains(systemName.toUpper());
}

void Map::computeDistancesFrom(const QString& from) //, const int maxDistance = 0)
{
    QString fromName = from.toUpper();
    if(!m_systemMap.contains(fromName) ||
            m_systemMap[fromName].distance.count() > 0)
    {
        // Bail out if this system is not on the map, or we've already
        // computed the distances from this system.
        return;
    }

    HopCounter origin = {fromName, 0};
    m_systemMap[from].distance.insert(fromName, 0);

    QQueue<HopCounter> queue;
    queue.enqueue(origin);

    while (!queue.isEmpty())
    {
        HopCounter current = queue.dequeue();
        foreach(QString systemName, m_systemMap[current.name].connected)
        {
            HopCounter nextHop = { systemName, current.jumps+1 };

            if (m_systemMap[fromName].distance.contains(systemName))
            {
                if (m_systemMap[fromName].distance[systemName] > nextHop.jumps)
                {
                    // This path was better to the destination than a path we previously followed.
                    m_systemMap[fromName].distance[systemName] = nextHop.jumps;
                    queue.enqueue(nextHop);
                }
            }
            else
            {
                // We do not have any previous cost for this neighbor, so add it.
                m_systemMap[fromName].distance.insert(systemName, nextHop.jumps);
                queue.enqueue(nextHop);
            }
        }
    }
}

int Map::distanceBetween(const QString& pilotLoc, const QString& system)
{
    qDebug() << "Distance from " << pilotLoc << " to " << system << " is " <<
                m_systemMap[pilotLoc.toUpper()].distance[system.toUpper()];
    return m_systemMap[pilotLoc.toUpper()].distance[system.toUpper()];
}

QString Map::getIdBySystem(const QString& systemName)
{
    return m_systemMap[systemName.toUpper()].id;
}

QString Map::getSystemById(const QString& id)
{
    return m_idToNameMap[id];
}

void Map::setPilotLocation(const QString &pilotName, const QString& systemName)
{
    QString upperSystem = systemName.toUpper();

    if(!m_pilotSystem.contains(pilotName))
    {
        emit newPilot(pilotName);
    }

    m_pilotSystem[pilotName] = upperSystem;
    emit(pilotLocationChange(pilotName, upperSystem));

    if(m_systemMap.contains(upperSystem))
    {
        computeDistancesFrom(upperSystem);
    }
}

bool Map::isAPilotIn(const QString& systemName)
{
    QString upperSystem = systemName.toUpper();
    foreach(QString pilotName, m_pilotSystem.keys())
    {
        if(m_pilotSystem[pilotName] == upperSystem)
        {
            return true;
        }
    }
    return false;
}

QStringList Map::pilotsIn(const QString& systemName)
{
    QStringList pilots;

    QString upperSystem = systemName.toUpper();
    foreach(QString pilotName, m_pilotSystem.keys())
    {
        if(m_pilotSystem[pilotName] == upperSystem)
        {
            pilots.append(pilotName);
        }
    }
    return pilots;
}

void Map::setSystemStatus(const QString& system, SystemStatus status,
                          QDateTime &dateTime, bool emitChange)
{
    QString upperSystem = system.toUpper();
    if(!m_systemMap.contains(upperSystem))
    {
        return;
    }

    if(!m_activeSystems.contains(upperSystem))
    {
        Active newActiveSystem;
        m_activeSystems.insert(upperSystem, newActiveSystem);
    }
    else
    {
        // When reading in files at initial load, it's possible to get messages from multiple channels
        // with a systems status, out of order.
        if(m_activeSystems[upperSystem].dateTime > dateTime)
        {
            // Ignore older status and return.
            return;
        }
    }

    m_activeSystems[upperSystem].dateTime = dateTime;
    m_activeSystems[upperSystem].status = status;

    if(emitChange)
        updateSystem(upperSystem);
}

void Map::updateActiveSystems()
{
    if(m_activeSystems.count() == 0)
    {
        return;
    }

    foreach(QString system, m_activeSystems.keys())
    {
        updateSystem(system);
    }
}

void Map::updateSystem(QString system)
{
    QString primaryColor, secondaryColor;
    QDateTime dateTime = m_activeSystems[system].dateTime;
    qint64 secondsDiff = dateTime.msecsTo(QDateTime::currentDateTimeUtc()) / 1000;

    // TODO:  Simplify all this below now that we're no longer directly manipulating the maps xml.
    //        i.e. Get rid of the hex texts and work directly with QColors.

    bool stale = false;
    float fadeOut = 20 * 60;  // 20 Minutes
    if (secondsDiff > fadeOut)
    {
        secondaryColor = "FF";

        // Active systems never really go inactive again, because we want to update
        // their time last seen.
        stale = true;
    }
    else
    {
        if(secondsDiff > 0)
        {
            int intensity = ((fadeOut - secondsDiff) / fadeOut) * 255.0f;
            secondaryColor = QString::number(255-intensity, 16).rightJustified(2, '0');
        }
        else
        {
            secondaryColor = "FF";
        }
    }

    QString prefix;
    primaryColor = "000000";
    switch(m_activeSystems[system].status)
    {
    case SystemStatus::clear:
        emit systemColorUpdated(system, QColor("#" + secondaryColor + "FF" + secondaryColor));
        prefix = "clr: ";
        if(stale)
            primaryColor = "009F00";
        break;
    case SystemStatus::red:
        emit systemColorUpdated(system, QColor("#FF" + secondaryColor + secondaryColor));
        prefix = "";
        if(stale)
            primaryColor = "FF0000";
        break;
    default:
        emit systemColorUpdated(system, QColor(Qt::white));
        break;
    }

    int m = (secondsDiff / (60));
    int s = (secondsDiff) - (m * 60);

    emit systemTimeUpdated(
                system,
                prefix + QString::number(m) + ":" + QString::number(s).rightJustified(2, '0'),
                QColor("#" + primaryColor));
}

QString Map::getSystemByAbbreviation(const QString& word)
{
    if(word.length() == 0)
        return word;

    QString upperWord = word.toUpper();

    if(m_systemMap.keys().contains(upperWord))
    {
        // Not abbreviated at all.
        return upperWord;
    }

    int wordLength = upperWord.length();

    foreach(QString system, m_systemMap.keys())
    {
        if (system.left(wordLength) == upperWord)
        {
            // System name starts with word
            return system;
        }
        else
        {
            // Check it without the dash
            QString systemNoDash = system;
            systemNoDash.remove('-');
            if (systemNoDash.length() >= wordLength)
            {
                if (systemNoDash.left(wordLength) == upperWord)
                {
                    return system;
                }
            }

            // Check it for x-x... format
            int dashPos = system.indexOf('-');
            if (dashPos > 0 && wordLength >= 3)
            {
                QString shortName = system.mid(dashPos-1);
                if (shortName.left(wordLength) == upperWord)
                {
                    return system;
                }
            }
            else if(wordLength == 2)
            {
                // Maybe just two letters (nr instead of n-r), but not
                //    x1 -
                QString shortName = system.mid(dashPos-1) +
                        system.mid(dashPos+1);
                if (shortName == upperWord &&
                        !(shortName[0] == 'X' &&
                          (shortName[1].isDigit() && shortName[1].digitValue() > 1)
                         )
                   )
                {
                    return system;
                }
            }
        }
    }

    // Still no match?  Maybe they mispelled it, like people do with 9-F0B2 (9-fob)
    if(upperWord.contains('-') && upperWord.contains('0'))
    {
        upperWord.replace('0', 'O');
        return getSystemByAbbreviation(upperWord);
    }

    return "";
}

QStringList Map::getSystemNames()
{
    return m_systemMap.keys();
}

QPoint Map::getCoordinates(const QString& name)
{
    QString upperName = name.toUpper();
    if (!m_systemMap.contains(upperName))
    {
        return QPoint();
    }

    return m_systemMap[upperName].coords;
}


// Process XML of the dotlan SVG and emit our mapview objects

void Map::processNode(const QDomNode& inNode)
{
    QDomNode node = inNode.firstChild();
    while(!node.isNull())
    {
        if(node.nodeName() == "g")
        {
            QDomElement e = node.toElement();
            if (e.hasAttribute("id"))
            {
                QString id = e.attribute("id");
                if(id == "controls")
                {
                    // Our app handles controls, so do nothing.
                }
                else if(id == "jumps")
                {
                    processNode(node);
                }
                else if(id == "map")
                {
                    processNode(node);
                }
                else if(id == "sysuse")
                {
                    processNode(node);
                }
                else if(id == "glow" ||
                        id == "campaigns" ||
                        id == "highlights" ||
                        id == "legend" ||
                        id == "notes" ||
                        id == "standings")
                {
                    // We don't use these, at this time.
                }
                else
                {
                    qDebug() << "Map::processNode - Unknown node id:  " << node.nodeName() << " & id=" << e.attribute(("id"));
                }
            }
        }
        else if(node.nodeName() == "defs")
        {
            QDomNode defsChild = node.firstChild();
            while(!defsChild.isNull())
            {
                if(defsChild.nodeName() == "symbol")
                {
                    QDomElement e = defsChild.toElement();
                    if(e.attribute("id").left(11) != "defCampaign")
                    {
                        // We found a system symbol!  Hopefully...
                        doSymbol(defsChild);
                    }
                }
                else if(defsChild.nodeName() == "radialGradient")
                {
                    // We are a strong black independent woman that does not need
                    // radialGradients to tell us how to draw our systems.
                }
                else
                {
                    qDebug() << "Map::processNode - Unhandled defsChild: " << defsChild.nodeName();
                }

                defsChild = defsChild.nextSibling();
            }

        }
        else if(node.nodeName() == "line")
        {
            QRegExp jumpRegExp("j-([0-9]+)-([0-9]+)$");
            QDomElement e = node.toElement();
            if (e.hasAttribute("id"))
            {
                QString id = e.attribute("id");
                if(id.length() > 2 && id.left(2) == "j-")
                {
                    if (jumpRegExp.indexIn(e.attribute("id")) != -1)
                    {
                        QString from = m_idToNameMap[jumpRegExp.cap(1)];
                        QString to = m_idToNameMap[jumpRegExp.cap(2)];

                        if (!m_systemMap[from].connected.contains(to))
                        {
                            m_systemMap[from].connected.append(to);
                        }
                        if (!m_systemMap[to].connected.contains(from))
                        {
                            m_systemMap[to].connected.append(from);
                        }

                        // Add this line to our view.
                        emit lineAdded(e.attribute("x1").toDouble(), e.attribute("y1").toDouble(),
                                       e.attribute("x2").toDouble(), e.attribute("y2").toDouble(),
                                       e.attribute("class") );
                    }
                }
            }
        }
        else if(node.nodeName() == "script")
        {
            // Throw it away.  We don't need no stinkin' scripts.
        }
        else if(node.nodeName() == "style")
        {
            // We have our own map themes, ignore styles.
        }
        else if(node.nodeName() == "text")
        {
            // TODO:  Maybe emit these as objects to add later...
            //        but that may not be a great idea for legends
            //        that are going to refer to stuff not in our
            //        theme.
        }
        else if(node.nodeName() == "use")
        {
            QDomElement e = node.toElement();
            if (e.hasAttribute("id"))
            {
                QString id = e.attribute("id");
                if(id.length() > 3 && id.left(3) == "sys")
                {
                    id = id.right(id.length()-3);

                    QPoint point;
                    point.setX(e.attribute("x").toDouble() +
                               (e.attribute("width").toDouble() * .5) );
                    point.setY(e.attribute("y").toDouble() +
                               (e.attribute("height").toDouble() * .5) );

                    if(m_idToNameMap[id] == "")
                    {
                        // Use nodes should be at the end of the files, by which time we should have
                        // deduced the system IDs from the symbols or other sections preceding.

                        qDebug() << "Map::processNodes - got 'use' node for unknown system id " << id;
                    }
                    m_systemMap[m_idToNameMap[id]].coords = point;
                    emit systemPosition(m_idToNameMap[id], m_systemMap[m_idToNameMap[id]].coords);
                }
            }
        }
        else
        {
            qDebug() << "Map::processNodes - Node name unsupported:  " << node.nodeName();
        }

        node = node.nextSibling();
    }
}

// Process a symbol section of the dotlan map.
void Map::doSymbol(const QDomNode& node)
{

    // Get Symbol ID

    System system;
    QDomElement e = node.toElement();
    if (e.attribute("id").startsWith("def"))
    {
        system.id = e.attribute("id");
        system.id = system.id.right(system.id.length()-3);
    }
    else
    {
        return;
    }

    QString name;

    QDomNode childNode = node.firstChild();
    while(!childNode.isNull())
    {
        if(childNode.nodeName() == "a")
        {
            QDomElement e = childNode.toElement();
            if(e.hasAttribute("xlink:href"))
            {
                // Everything after last forward slash is system name.
                name = e.attribute("xlink:href");
                name = name.right(name.length() - name.lastIndexOf('/') - 1);
            }

            QDomNode aChildNode = childNode.firstChild();
            while(!aChildNode.isNull())
            {
                if(aChildNode.nodeName() == "rect")
                {
                    QDomElement e = aChildNode.toElement();
                    if(e.hasAttribute("id"))
                    {
                        if(e.attribute("id").startsWith("ice"))
                        {
                            system.hasIce = true;
                        }
                    }
                }
                else if(aChildNode.nodeName() == "polygon")
                {
                }
                else if(aChildNode.nodeName() == "text")
                {
                    QDomElement e = aChildNode.toElement();
                    if(e.hasAttribute("class"))
                    {
                        QString ca = e.attribute("class");
                        if(ca.contains("ss"))
                        {
                            system.type = "internal";
                            system.text = aChildNode.childNodes().item(0).toText().nodeValue();
                        }
                        else if(ca.contains("es"))
                        {
                            system.type = "external";
                            system.text = aChildNode.childNodes().item(0).toText().nodeValue();
                        }
                        else if(ca.contains("st") or ca.contains("er"))
                        {
                            system.description = aChildNode.childNodes().item(0).toText().nodeValue();
                        }
                        else
                        {
                            qDebug() << "Map::doSymbol - unhandled text element class:  " << ca;
                        }
                    }
                    else
                    {
                        qDebug() << "Map::doSymbol - text element is like a school on Sunday.  No class.";
                    }
                }

                aChildNode = aChildNode.nextSibling();
            }
        }
        else if(childNode.nodeName() == "rect" ||
                childNode.nodeName() == "polygon" ||
                childNode.nodeName() == "text")
        {
            // We're not interested in any attributes outside the A
            // tag now.
        }
        else
        {
            qDebug() << "Map::doSymbol - Unhanded node outside of A tag: " << childNode.nodeName();
        }

        childNode = childNode.nextSibling();
    }

    m_systemMap.insert(name.toUpper(), system);
    m_idToNameMap.insert(system.id, name.toUpper());

    emit systemAdded(name,
                     system.coords,
                     system.type,
                     system.description);
}
