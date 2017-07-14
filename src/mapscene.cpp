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

#include "mapscene.h"
#include "systemshape.h"

#include <QDebug>
#include <QGraphicsView>

MapScene::MapScene(QObject *parent) : QGraphicsScene(parent)
{

}

void MapScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    return QGraphicsScene::mouseMoveEvent(event);
}

void MapScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::MouseButton::LeftButton)
    {
        QList<QGraphicsItem*> clicked = items(event->scenePos(), Qt::IntersectsItemShape, Qt::DescendingOrder, views().first()->transform());
        foreach(QGraphicsItem* item, clicked)
        {
            SystemShape *sys = qgraphicsitem_cast<SystemShape *>(item);
            if(sys && sys->name().endsWith(":system"))
            {
                qDebug() << "SvgMapView::mousePressEvent - " << sys->name() << " clicked.";
                emit systemClicked(sys->name().left(sys->name().length()-7));
                return QGraphicsScene::mousePressEvent(event);
            }
            else
            {
                qDebug() << "SvgMapView::mousePressEvent - Not a system" << event->scenePos();
                if(item)
                    qDebug() << item->boundingRect();
            }
        }
    }

    emit systemClicked("");
    return QGraphicsScene::mousePressEvent(event);
}

void MapScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    return QGraphicsScene::mouseReleaseEvent(event);
}
