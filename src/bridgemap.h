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

#ifndef BRIDGEMAP_H
#define BRIDGEMAP_H

#include <QFile>
#include <QObject>
#include <QList>
#include <QGraphicsSvgItem>

#include <map.h>

struct Bridge
{
    QString source;         // System name
    QString destination;
    bool oneWay;
    QString color;
};

class BridgeMap : public QObject
{
    Q_OBJECT
public:
    explicit BridgeMap(QObject *parent = 0);

    void init(QFile& file, Map* map);

    // Make private later, implement custom iterator
    QList<QGraphicsLineItem*> arrows;

signals:

public slots:

private:
    QList<Bridge> bridges;
};

#endif // BRIDGEMAP_H
