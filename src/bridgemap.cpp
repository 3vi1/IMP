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

#include "bridgemap.h"
#include <QPen>
#include <QTextStream>

BridgeMap::BridgeMap(QObject *parent) : QObject(parent)
{
}

void BridgeMap::init(QFile &file, Map* map)
{
    if (!file.open(QIODevice::ReadOnly))
        return;

    QStringList stringList;

    QTextStream in(&file);
    QString all = in.readAll();
    stringList = all.split('\n');
    stringList.removeAll("");

    foreach(QString bridgeLine, stringList)
    {
        if(!bridgeLine.contains(":"))
            continue;

        QString color = "FF0000";
        QStringList ecList = bridgeLine.split(":");
        if(ecList.count() == 2)
            color = ecList[1];
        else if(ecList.count() != 1)
            continue;

        QStringList bbList;
        bool oneWay = false;
        if(ecList[0].contains("="))
        {
            bbList = ecList[0].split("=");
        }
        else if(ecList[0].contains(">"))
        {
            bbList = ecList[0].split(">");
            oneWay = true;
        }
        else
        {
            continue;
        }

        bridges.append(Bridge({bbList[0], bbList[1], oneWay, color}));
    }

    arrows.clear();
    foreach(Bridge bridge, bridges)
    {
        QPoint sourcePoint = map->getCoordinates(bridge.source);
        //sourcePoint.setX(sourcePoint.x() + map->getWidth(bridge.source) * 0.5);
        //sourcePoint.setY(sourcePoint.y() + map->getHeight(bridge.source) * 0.5);

        QPoint destinationPoint = map->getCoordinates(bridge.destination);
        //destinationPoint.setX(destinationPoint.x() + map->getWidth(bridge.destination) * 0.5);
        //destinationPoint.setY(destinationPoint.y() + map->getHeight(bridge.destination) * 0.5);

        QGraphicsLineItem* arrow = new QGraphicsLineItem(
                    sourcePoint.x(), sourcePoint.y(),
                    destinationPoint.x(), destinationPoint.y());

        QColor namedColor;
        namedColor.setNamedColor(bridge.color);
        QBrush ourBrush = QBrush(namedColor);
        arrow->setPen(QPen(ourBrush, 5, Qt::DashLine));
        arrow->setOpacity(0.5);
        arrows.append(arrow);
    }
}
