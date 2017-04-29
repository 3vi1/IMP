#include "systemshape.h"

#include <QDebug>
#include <QPainter>

SystemShape::SystemShape(QSvgRenderer* svgRenderer,
                         QString name,
                         QString c)
    : MapShape(svgRenderer, name, c)
{
    shapeName = name + ":system";
    className = c;

//    renderer = svgRenderer;
//    setSharedRenderer(renderer);
//    setElementId(className);
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
