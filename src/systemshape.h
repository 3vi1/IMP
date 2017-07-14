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

#ifndef SYSTEMSHAPE_H
#define SYSTEMSHAPE_H

#include <QColor>
#include <QGraphicsColorizeEffect>
#include "mapshape.h"

class SystemShape : public MapShape
{
public:
    SystemShape(QSvgRenderer* svgRenderer,
                QString name,
                QString className,
                QGraphicsItem *parentItem = nullptr);
    ~SystemShape();

    void setColor(const QColor& c);
    void setNamePosition(QPointF point){namePosition = point;}
    void setPos(QPointF& point);
    void setText(const QString& t){text = t;}
    void setTextPosition(QPointF point){textPosition = point;}

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


private:
    QString className;
    QPointF namePosition;
    QString text;
    QPointF textPosition;

    QGraphicsTextItem* descriptionItem;

    QGraphicsColorizeEffect colorizer;
};

#endif // SYSTEMSHAPE_H
