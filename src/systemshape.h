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
