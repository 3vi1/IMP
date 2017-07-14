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

#include "systemshape.h"

#include <QDebug>
#include <QPainter>

SystemShape::SystemShape(QSvgRenderer* svgRenderer,
                         QString name,
                         QString c,
                         QGraphicsItem *parentItem)
    : MapShape(svgRenderer, name, c, parentItem)
{
    shapeName = name + ":system";
    className = c;

    setFlags(QGraphicsItem::ItemClipsToShape);
    setZValue(0);
    setGraphicsEffect(0);

}

SystemShape::~SystemShape()
{
}

void SystemShape::setColor(const QColor& c)
{
    colorizer.setColor(c);
    setGraphicsEffect(&colorizer);
}

void SystemShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    MapShape::paint(painter, option, widget);
}

void SystemShape::setPos(QPointF& point)
{
    MapShape::setPos(point);
}
