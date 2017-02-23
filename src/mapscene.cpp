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
