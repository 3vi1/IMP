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

#ifndef MAPSHAPE_H
#define MAPSHAPE_H

#include <QDateTime>
#include <QDomDocument>
#include <QGraphicsSvgItem>
#include <QObject>
#include <QByteArray>
#include <QSvgRenderer>
#include <QTimer>

class MapShape : public QGraphicsSvgItem
{
public:
    explicit MapShape();
    MapShape(QSvgRenderer* svgRenderer,
             const QString& name,
             const QString& itemId);//,
             //QGraphicsView *view);
    ~MapShape();

    void paint(QPainter * painter,
               const QStyleOptionGraphicsItem * option,
               QWidget * widget);

    void    centerOffsets();
    void    load(const QString& fileName);
    void    lockRotation(bool enable = true){rotationLocked = enable;}
    QString name(){return shapeName;}

    void    setOffset(qreal x, qreal y);
    void    setXOffset(qreal d);
    void    setYOffset(qreal d);
    void    setPos(const QPointF& point);
    void    setScale(qreal);
    void    setSystemName(QString name){shapeName = name;}
    void    setZValue(qreal z);

signals:

public slots:
    void repainter();

protected:
    // overriding mouse events
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    QString shapeName;
    QSvgRenderer* renderer;

private:
    bool rotationLocked;
    QDomDocument domDoc;

    qreal lastTime = QDateTime::currentMSecsSinceEpoch();

    QPointF realPosition;

    qreal xOffset = 0;
    qreal yOffset = 0;

    void rebuildSvg();
};

#endif // MAPSHAPE_H
