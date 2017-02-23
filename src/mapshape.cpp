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

#include "mapshape.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QGraphicsItem>
#include <QPainter>
#include <QStandardPaths>
#include <QSvgRenderer>

MapShape::MapShape()
{
    renderer = new QSvgRenderer(new QObject());
    connect(renderer, &QSvgRenderer::repaintNeeded,
            this, &MapShape::repainter );
}

MapShape::MapShape(QSvgRenderer* svgRenderer,
            const QString& name,
            const QString& itemId)
{
    renderer = svgRenderer;
    shapeName = name;
    setSharedRenderer(renderer);
    setElementId(itemId);
    connect(renderer, &QSvgRenderer::repaintNeeded,
            this, &MapShape::repainter);
}

MapShape::~MapShape()
{
}

void MapShape::repainter()
{
    update();
}

void MapShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    QGraphicsSvgItem::paint(painter, option, widget);
}

void MapShape::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //Pressed = true;
    //update();
    QGraphicsSvgItem::mousePressEvent(event);
}

void MapShape::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //Pressed = false;
    //update();
    QGraphicsSvgItem::mouseReleaseEvent(event);
}

void MapShape::load(const QString& fileName)
{
    QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    QDir dataDir{dataPath};
    QFile file(dataDir.absoluteFilePath(fileName));

    // Open file and set DOM
    if (!file.open(QIODevice::ReadOnly))
    {
        return;
    }
    if (!domDoc.setContent(&file)) {
        file.close();
        return;
    }
    file.close();

    rebuildSvg();

    setPos(realPosition);
}

void MapShape::rebuildSvg()
{
    renderer->load(domDoc.toByteArray());
    setSharedRenderer(renderer);
    setElementId("");

    setFlags(QGraphicsItem::ItemClipsToShape);
    //setCacheMode(QGraphicsItem::NoCache);
}

void MapShape::setOffset(qreal x, qreal y)
{
    xOffset = x;
    yOffset = y;
}

void MapShape::setPos(const QPointF& point)
{
    realPosition = point;

    // Calculate centered position
    qreal newX = realPosition.x() - (boundingRect().width() * 0.5f * scale());
    qreal newY = realPosition.y() - (boundingRect().height() * 0.5f * scale());

    // Set position relative to offsets
    QGraphicsSvgItem::setPos(newX - xOffset, newY - yOffset);
}

void MapShape::setScale(qreal scale)
{
    QGraphicsSvgItem::setScale(scale);

    // If scale changed, we need to recenter this.
    setPos(realPosition);
}

void MapShape::setXOffset(qreal d)
{
    xOffset = d;
    setPos(realPosition);
}

void MapShape::setYOffset(qreal d)
{
    yOffset = d;
    setPos(realPosition);
}

void MapShape::setZValue(qreal z)
{
    QGraphicsSvgItem::setZValue(z);
}
