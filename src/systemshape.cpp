#include "systemshape.h"

#include <QDebug>
#include <QPainter>

SystemShape::SystemShape(QSvgRenderer* svgRenderer,
                         QString name,
                         QString c)
    : MapShape()
{
    shapeName = name + ":system";
    className = c;

    renderer = svgRenderer;
    setSharedRenderer(renderer);
    setElementId(className);
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

/*
    painter->setPen(QPen(Qt::DotLine));
    painter->setBrush(QColor(255, 0, 0));
    painter->drawRect(boundingRect());
*/
}

void SystemShape::setPos(QPointF& point)
{
    MapShape::setPos(point);
}
