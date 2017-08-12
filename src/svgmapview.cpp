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

#include "svgmapview.h"
#include <QApplication>  // for queryKeyboardModifiers
#include <QBuffer>
#include <QDebug>
#include <QFile>
#include <qmath.h>
#include <QMessageBox>
#include <QScrollBar>
#include <QSize>

#ifdef USE_OPENGL
#include <QOpenGLWidget>
#endif

SvgMapView::SvgMapView(QWidget *parent) : QGraphicsView(parent)
{
#ifdef USE_OPENGL
    setViewport(new QOpenGLWidget(
                    //QGLFormat(QGL::SampleBuffers | QGL::AlphaChannel),
                    this)
            );
    setViewportUpdateMode(
                QGraphicsView::FullViewportUpdate);
#endif

    // Retransmit system clicks upstream
    connect(&mapScene, &MapScene::systemClicked,
            this, &SvgMapView::systemClicked);

    // Create find shape
    findShape = new MapShape();

    logo = new QGraphicsPixmapItem(QPixmap(":/graphics/Imp.png"));
    svgLoading = new QGraphicsSvgItem(":/graphics/load3.svg");

    setScene(&loadingScene);
    setTransformationAnchor(QGraphicsView::ViewportAnchor::NoAnchor);
    setDragMode(NoDrag);
    loadingScene.clear();

    loadingScene.addItem(svgLoading);
    loadingScene.addItem(logo);

    loadText = new QGraphicsSimpleTextItem("Loading...");
    loadText->setFont(QFont("Decorative", 18));
    loadingScene.addItem(loadText);

    nameFont = QFont("Tahoma", 6);
    timeFont = QFont("Arial", 6);

    setStyleSheet("background-color: transparent;");
}

SvgMapView::~SvgMapView()
{
    qDeleteAll(pilotShapes.begin(), pilotShapes.end());
    findShape->deleteLater();
}

void SvgMapView::paintEvent(QPaintEvent *event)
{
    if(scene() == &loadingScene)
    {
        QTransform transform = getTransform();
        resetTransform();

        float logoScale = ((rect().width()/ logo->boundingRect().width() ) * 0.2f);
        logo->setScale(logoScale);
        logo->setPos( getViewportCenter() - (logo->boundingRect().bottomRight() / 2 * logoScale) );

        float spinScale = ((rect().width() / svgLoading->boundingRect().width() ) * 0.2f);
        svgLoading->setScale(spinScale);
        svgLoading->setX( getViewportCenter().x() -
                          ((svgLoading->boundingRect().width()*spinScale) / 2) );
        svgLoading->setY( getViewportCenter().y() -
                          ((svgLoading->boundingRect().height()*spinScale) / 2) );

        float textScale = 1;
        loadText->setScale(textScale);
        loadText->setX( getViewportCenter().x() - ((loadText->boundingRect().width()*textScale) / 2) );
        loadText->setY( getViewportCenter().y() + ((loadText->boundingRect().height()*textScale) / 2)  +
                (svgLoading->boundingRect().height()*spinScale) );

        QGraphicsView::paintEvent(event);
        setTransform(transform);

        return;
    }
    else if(scene() == &mapScene)
    {
        QGraphicsView::paintEvent(event);
    }
    else
    {
        qDebug() << "SvgMapView::paintEvent - Well this is weird... we don't have a current scene.";
    }

    return;
}

void SvgMapView::drawBackground(QPainter *painter, const QRectF &rect)
{
//    if(drawStandardBackground)
        QGraphicsView::drawBackground(painter, rect);
}

void SvgMapView::showMap(bool enable)
{
    if(enable)
    {
        setScene(&mapScene);
        setTransformationAnchor(AnchorUnderMouse);
        setDragMode(ScrollHandDrag);
        resetTransform();
    }
    else
    {
        setScene(&loadingScene);
        setDragMode(DragMode::NoDrag);
    }
}

void SvgMapView::setLoadText(const QString text)
{
    if(loadText != NULL)
        loadText->setText(text);
}

void SvgMapView::keyPressEvent(QKeyEvent *event)
{
    QGraphicsView::keyPressEvent(event);
}

void SvgMapView::keyReleaseEvent(QKeyEvent *event)
{
    QGraphicsView::keyReleaseEvent(event);
}

void SvgMapView::mouseMoveEvent(QMouseEvent *event)
{
    return QGraphicsView::mouseMoveEvent(event);
}

void SvgMapView::mousePressEvent(QMouseEvent *event)
{
    return QGraphicsView::mousePressEvent(event);
}

void SvgMapView::mouseReleaseEvent(QMouseEvent *event)
{
    return QGraphicsView::mouseReleaseEvent(event);
}


void SvgMapView::wheelEvent(QWheelEvent *event)
{
    Qt::KeyboardModifiers mods = QApplication::queryKeyboardModifiers();

    if(mods.testFlag(Qt::AltModifier) && mods.testFlag(Qt::ControlModifier))
    {
        emit sendOpacity(event->delta());
    }
    else if(mods.testFlag(Qt::ControlModifier))
    {
        setTransformationAnchor(AnchorViewCenter);
        qreal angle = event->delta() * .025f;
        rotate(angle);

        rotateSystems(-angle);

        setTransformationAnchor(AnchorUnderMouse);
    }
    else
    {
        qreal factor = qPow(1.2, event->delta() * .004);
        setZoom(factor);
    }

    event->accept();
}

void SvgMapView::setZoom(float factor)
{
    if(factor <= 0)
    {
        // Just in case someone managed to break it.
        factor = 1;
    }

    scale(factor, factor);
}

QTransform SvgMapView::getTransform()
{
    return transform();
}

void SvgMapView::setTransform(QTransform trans)
{
    savedTransform = trans;
    return QGraphicsView::setTransform(trans);
}

QRectF SvgMapView::getSceneRect()
{
    return sceneRect();
}

void SvgMapView::setSceneRect(QRectF rect)
{
    return QGraphicsView::setSceneRect(rect);
}

QPointF SvgMapView::getViewportCenter()
{
    // Use centerOn() to set.
    return mapToScene((viewport()->rect().center()));
}

int SvgMapView::getHorizontalScroll()
{
    return horizontalScrollBar()->value();
}

void SvgMapView::setHorizontalScroll(int x)
{
    horizontalScrollBar()->setValue(x);
}

int SvgMapView::getVerticalScroll()
{
    return verticalScrollBar()->value();
}

void SvgMapView::setVerticalScroll(int y)
{
    verticalScrollBar()->setValue(y);
}

void SvgMapView::showBridges(bool enable)
{
    drawBridges = enable;

    if(enable)
    {
        foreach(QGraphicsLineItem* arrow, arrows)
        {
            mapScene.addItem(arrow);
        }
    }
    else
    {
        foreach(QGraphicsLineItem* arrow, arrows)
        {
            mapScene.removeItem(arrow);
        }
    }
}

void SvgMapView::clearBridges()
{
    arrows.clear();
}

void SvgMapView::addBridge(QGraphicsLineItem* arrow)
{
    arrows.append(arrow);
    arrow->setZValue(-2);
}

void SvgMapView::gotLine(qreal x1, qreal x2, qreal y1, qreal y2, const QString& /*connectionClass*/)
{
    QGraphicsLineItem* line = new QGraphicsLineItem(x1, x2, y1, y2);

    line->setPen(_linesColor);
    lines.append(line);
    mapScene.addItem(line);

    line->setZValue(-3);
}

void SvgMapView::clearMap()
{
    clearLines();
    clearShapes();
    clearTexts();

    if(mapScene.items().contains(findShape))
        mapScene.removeItem(findShape);

    foreach(MapShape* pilotShape, pilotShapes)
    {
        mapScene.removeItem(pilotShape);
        pilotShape->deleteLater();
    }
    pilotShapes.clear();

    mapScene.clear();
}

void SvgMapView::clearLines()
{
    foreach(QGraphicsLineItem* line, lines)
    {
        mapScene.removeItem(line);
        delete line;
    }
    lines.clear();
}

void SvgMapView::clearTexts()
{
    foreach(QGraphicsTextItem* t, m_texts)
    {
        mapScene.removeItem(t);
        t->deleteLater();
    }
    m_texts.clear();
}

void SvgMapView::clearShapes()
{
    foreach(MapShape* s, systemOutlines.values())
    {
        mapScene.removeItem(s);
        s->deleteLater();
    }
    systemOutlines.clear();

    foreach(SystemShape* s, systemShapes.values())
    {
        mapScene.removeItem(s);
        s->deleteLater();
    }
    systemShapes.clear();

    foreach(MapShape* s, wormholes.values())
    {
        mapScene.removeItem(s);
        s->deleteLater();
    }
    wormholes.clear();

}

void SvgMapView::findLocation(const QString &systemName)
{
    if(!m_map->contains(systemName))
    {
        mapScene.removeItem(findShape);
    }
    else
    {
        findShape->setPos(m_map->getCoordinates(systemName));
        if(!mapScene.items().contains(findShape))
        {
            mapScene.addItem(findShape);
        }
    }
}

void SvgMapView::gotPilotLocation(const QString& pilotName, const QString& systemName, bool enabled)
{
    if(!m_map->contains(systemName))
    {
        if(pilotShapes.contains(pilotName))
        {
            mapScene.removeItem(pilotShapes[pilotName]);
            pilotShapes[pilotName]->deleteLater();
            pilotShapes.remove(pilotName);
        }
        return;
    }

    MapShape* pilotShape;
    if(pilotShapes.contains(pilotName))
    {
        pilotShape = pilotShapes[pilotName];
    }
    else
    {
        pilotShape = new MapShape();
        if(m_theme)
        {
            pilotShape->load(m_theme->getAttribute("pilotGraphic").toString());
            pilotShape->setOpacity(m_theme->getAttribute("pilotOpacity").toDouble());
            pilotShape->setScale(m_theme->getAttribute("pilotScale").toDouble());
            pilotShape->setZValue(m_theme->getAttribute("pilotZ").toDouble());
            pilotShape->setXOffset(m_theme->getAttribute("pilotXOffset").toDouble());
            pilotShape->setYOffset(m_theme->getAttribute("pilotYOffset").toDouble());
        }

        pilotShapes.insert(pilotName, pilotShape);

        if(enabled)
            mapScene.addItem(pilotShape);
    }

    pilotShape->setPos(m_map->getCoordinates(systemName));
    pilotShape->setSystemName(systemName);
}

void SvgMapView::gotSystemShapesFile(QString shapesFile)
{
    qDebug() << "SvgMapView::gotSystemShapesFile(" << shapesFile <<
                ") - systemRenderer = " << systemRenderer;

    if(systemRenderer != NULL)
    {
        systemRenderer->deleteLater();
        systemRenderer = NULL;
    }

    systemRenderer = new QSvgRenderer(shapesFile, this);
}

void SvgMapView::handleShape(MapShape* shape, const QString& member, QVariant& data)
{
    if (member=="graphic")
    {
        shape->load(data.toString());
    }
    else if(member=="opacity")
    {
        shape->setOpacity(data.toDouble());
    }
    else if (member=="scale")
    {
        shape->setScale(data.toDouble());
    }
    else if (member=="z")
    {
        shape->setZValue(data.toDouble());
    }
    else if (member=="xOffset")
    {
        shape->setXOffset(data.toDouble());
    }
    else if (member=="yOffset")
    {
        shape->setYOffset(data.toDouble());
    }
}

void SvgMapView::handleLine(QGraphicsLineItem *line,
                            const QString& member,
                            QVariant& data)
{
    if (member=="color")
    {
        QPen pen = line->pen();
        pen.setColor(data.value<QColor>());
        line->setPen(pen);
    }
    else if(member=="opacity")
    {
        line->setOpacity(data.toDouble());
    }
    else if (member=="scale")
    {
        line->setScale(data.toDouble());
    }
    else if (member=="z")
    {
        line->setZValue(data.toDouble());
    }
    else if (member=="width")
    {
        QPen pen = line->pen();
        pen.setWidthF(data.toFloat());
        line->setPen(pen);
    }
}


void SvgMapView::receiveThemeUpdate(ThemeStorage& ts)
{
    switch(ts.objType)
    {
    case FIND:
        handleShape(findShape, ts.member, ts.data);
        break;
    case LINES:
        if(ts.member == "color")
        {
            m_linesColor = ts.data.value<QColor>();
        }
        foreach(QGraphicsLineItem* line, lines)
        {
            handleLine(line, ts.member, ts.data);
        }
        break;
    case MAP:
        if(ts.name == "back")
        {
            if(ts.member == "color")
            {
                backgroundColor = ts.data.value<QColor>();
                if(drawStandardBackground)
                    setBackgroundBrush(backgroundColor);
            }
            else if(ts.member == "graphic")
            {
                removeBackground(backSvg);
                removeBackground(backPixmap);

                QString data = ts.data.toString();
                if(data.length() > 0)
                {
                    /* The scene rectangle will grow if a large background had previously
                     * been added, but it does not shrink when the item is removed.  So,
                     * we should reset the sceneRect so that centering is not
                     * miscalculated.
                     */
                    if(savedSceneRect.width() != 0)
                        setSceneRect(savedSceneRect);
                    else
                        savedSceneRect = sceneRect();

                    backSvg = new QGraphicsSvgItem(data);
                    if(backSvg->boundingRect().width() == 0)
                    {
                        backPixmap = new QGraphicsPixmapItem(QPixmap(data));
                        backPixmap->setZValue(backgroundZ);
                        repositionBackground(backPixmap);
                        mapScene.addItem(backPixmap);
                    } else
                    {
                        backSvg->setZValue(backgroundZ);
                        repositionBackground(backSvg);
                        mapScene.addItem(backSvg);
                    }
                }
            }
            else if(ts.member == "opacity")
            {
                backgroundOpacity = ts.data.toDouble();
                if(backSvg != NULL)
                    backSvg->setOpacity(backgroundOpacity);
                if(backPixmap != NULL)
                    backPixmap->setOpacity(backgroundOpacity);
            }
            else if(ts.member == "scale")
            {
                backgroundScale = ts.data.toDouble();
                if(backSvg != NULL)
                {
                    backSvg->setScale(backgroundScale);
                    repositionBackground(backSvg);
                }
                if(backPixmap != NULL)
                {
                    backPixmap->setScale(backgroundScale);
                    repositionBackground(backPixmap);
                }
            }
            else if(ts.member == "xOffset")
            {
                backgroundOffset.setX(ts.data.toDouble());
                if(backSvg != NULL)
                    repositionBackground(backSvg);
                if(backPixmap != NULL)
                    repositionBackground(backPixmap);
            }
            else if(ts.member == "yOffset")
            {
                backgroundOffset.setY(ts.data.toDouble());
                if(backSvg != NULL)
                    repositionBackground(backSvg);
                if(backPixmap != NULL)
                    repositionBackground(backPixmap);
            }
            else if(ts.member == "z")
            {
                backgroundZ = ts.data.toDouble();
                if(backSvg != NULL)
                    backSvg->setZValue(backgroundZ);
                if(backPixmap != NULL)
                    backPixmap->setZValue(backgroundZ);
            }
        }
        break;
    case WORMHOLES:
        foreach(MapShape* shape, wormholes)
        {
            handleShape(shape, ts.member, ts.data);;
        }
        break;

    case PILOT:
        foreach(MapShape* shape, pilotShapes)
        {
            handleShape(shape, ts.member, ts.data);;
        }
        break;

    case SYSTEM:
        if(ts.name == "font")
        {
            QStringList fontAttributes = ts.data.toStringList();
            if(ts.member == "name")
            {
                setNameFont(QFont(fontAttributes[0], fontAttributes[1].toInt()));
            }
            else if(ts.member == "time")
            {
                setTimeFont(QFont(fontAttributes[0], fontAttributes[1].toInt()));
            }
        }
        break;
    }
}

void SvgMapView::enablePilot(QString pilot)
{
    if(!mapScene.items().contains(pilotShapes[pilot]))
    {
        mapScene.addItem(pilotShapes[pilot]);
    }
}

void SvgMapView::disablePilot(QString pilot)
{
    if(mapScene.items().contains(pilotShapes[pilot]))
    {
        mapScene.removeItem(pilotShapes[pilot]);
    }
}

void SvgMapView::gotSystem(const QString& mixedName, QPointF position, const QString& systemClass,
                           const QString& description = "")
{
    // TODO:  Make a new starSystem item that encapsulates all these components?

    qDebug() << "SvgMapView::gotSystem(" << mixedName << "," << position << "," << systemClass << "," << description << ")";

    QString name = mixedName.toUpper();
    SystemShape* shape = new SystemShape(systemRenderer,
                                         name,
                                         systemClass +  "RectInterior");
    shape->setColor("#DFDFFF");
    systemShapes.insert(name, shape);
    systemShapes[name]->setPos(position);
    mapScene.addItem(systemShapes[name]);

    MapShape* shape2 = new MapShape(systemRenderer,
                                         name + ":outline",
                                         systemClass +  "RectExterior");
    systemOutlines.insert(name, shape2);
    systemOutlines[name]->setPos(position);
    systemOutlines[name]->lockRotation(true);
    mapScene.addItem(systemOutlines[name]);

    QGraphicsTextItem* nameItem = new QGraphicsTextItem(mixedName);
    nameItem->setZValue(10);
    nameItem->setFont(nameFont);
    nameItem->setDefaultTextColor(Qt::black);
    setTextPosition(nameItem, position, nameOffset);
    m_texts[name + ":name"] = nameItem;
    mapScene.addItem(nameItem);

    QGraphicsTextItem* timeItem = new QGraphicsTextItem(description);
    timeItem->setZValue(10);
    timeItem->setFont(timeFont);
    timeItem->setDefaultTextColor(Qt::blue);
    setTextPosition(timeItem, position, timeOffset);
    m_texts[name + ":time"] = timeItem;
    mapScene.addItem(timeItem);
}

void SvgMapView::gotSystemPosition(
        const QString& name,
        QPointF position)
{
    if(!systemShapes.contains(name))
    {
        qDebug() << "SvgMapView::gotSystemPosition - update for unknown system " << name;
        return;
    }

    systemShapes[name]->setPos(position);
    systemOutlines[name]->setPos(position);

    setTextPosition(m_texts[name + ":name"], position, nameOffset);
    setTextPosition(m_texts[name + ":time"], position, timeOffset);
}

void SvgMapView::setMap(Map* m)
{
    m_map = m;

    connect(m_map, &Map::lineAdded,
            this, &SvgMapView::gotLine);
    connect(m_map, &Map::systemAdded,
            this, &SvgMapView::gotSystem);
    connect(m_map, &Map::systemPosition,
            this, &SvgMapView::gotSystemPosition);
}

void SvgMapView::setTextPosition(QGraphicsTextItem* ti, QPointF position, QPointF offset)
{
    QPointF center = ti->boundingRect().bottomRight() * .5;
    ti->setTransformOriginPoint(center - offset);
    ti->setPos(position - center + offset);
}


void SvgMapView::gotSystemTime(const QString& name,
        const QString& text,
        QColor timeColor)
{
    if(!systemShapes.contains(name))
    {
        qDebug() << "SvgMapView::gotSystemTime - update for unknown system " << name;
        return;
    }

    QGraphicsTextItem* textItem = m_texts[name + ":time"];

    QPointF center = textItem->pos() + (textItem->boundingRect().bottomRight() * 0.5f) - timeOffset;

    textItem->setDefaultTextColor(timeColor);
    textItem->setPlainText(text);

    setTextPosition(textItem, center, timeOffset);
}

void SvgMapView::gotSystemColor(const QString& name, QColor color)
{
    if(!systemShapes.contains(name))
    {
        qDebug() << "SvgMapView::gotSystemColor - update for unknown system " << name;
        return;
    }
    systemShapes[name]->setColor(color);
}

qreal SvgMapView::getSystemsRotation()
{
    if(systemShapes.count() > 0)
        return systemShapes.first()->rotation();
    return 0;
}

void SvgMapView::resetRotation()
{
    qreal mapScale = getTransform().m22();
    qDebug() << "SvgMapView::resetRotation() scale = " << mapScale;
    resetTransform();


    for(int i=0; i<systemShapes.count(); i++)
    {
        SystemShape* item = systemShapes.values().at(i);
        item->setTransformOriginPoint(item->boundingRect().width() * .5,
                                      item->boundingRect().height() * .5);
        item->setRotation(0);

        MapShape* outlineItem = systemOutlines.values().at(i);
        outlineItem->setTransformOriginPoint(outlineItem->boundingRect().width() * .5,
                                      outlineItem->boundingRect().height() * .5);
        outlineItem->setRotation(0);
    }

    for(int j=0; j<wormholes.count(); j++)
    {
        MapShape* item = wormholes.values().at(j);
        item->setTransformOriginPoint(item->boundingRect().width() * .5,
                                      item->boundingRect().height() * .5);
        item->setRotation(0);
    }

    foreach(QGraphicsTextItem* t, m_texts.values())
    {
        t->setRotation(0);
    }
}

void SvgMapView::rotateSystems(qreal angle)
{
    for(int i=0; i<systemShapes.count(); i++)
    {
        SystemShape* item = systemShapes.values().at(i);
        item->setTransformOriginPoint(item->boundingRect().width() * .5,
                                      item->boundingRect().height() * .5);
        item->setRotation(item->rotation() + angle);

        MapShape* outlineItem = systemOutlines.values().at(i);
        outlineItem->setTransformOriginPoint(outlineItem->boundingRect().width() * .5,
                                      outlineItem->boundingRect().height() * .5);
        outlineItem->setRotation(outlineItem->rotation() + angle);
    }

    foreach(QGraphicsTextItem* t, m_texts.values())
    {
        t->setRotation(
                t->rotation() + angle);
    }
}

void SvgMapView::setNameFont(QFont newFont)
{
    nameFont = newFont;

    foreach(QString k, m_texts.keys())
    {
        if(k.endsWith(":name"))
        {
            QPointF rectCenter = m_texts[k]->boundingRect().bottomRight() * .5;
            QPointF realPosition = m_texts[k]->pos() + rectCenter;

            m_texts[k]->setFont(nameFont);

            // Changing the font changes the dimensions, which can affect exactly
            // where the transform origin is, since it's relative to the text's
            // rectangle.

            QPointF newCenter = m_texts[k]->boundingRect().bottomRight() * .5;
            m_texts[k]->setTransformOriginPoint(newCenter - nameOffset);

            m_texts[k]->setPos(realPosition - newCenter );
        }
    }
}

void SvgMapView::setTimeFont(QFont newFont)
{
    timeFont = newFont;

    foreach(QString k, m_texts.keys())
    {
        if(k.endsWith(":time"))
        {
            QPointF rectCenter = m_texts[k]->boundingRect().bottomRight() * .5;
            QPointF realPosition = m_texts[k]->pos() + rectCenter;

            m_texts[k]->setFont(timeFont);

            QPointF newCenter = m_texts[k]->boundingRect().bottomRight() * .5;
            m_texts[k]->setTransformOriginPoint(newCenter - timeOffset);

            m_texts[k]->setPos(realPosition - newCenter );
        }
    }
}

void SvgMapView::disableBackgroundDraw(bool disable)
{
    drawStandardBackground = !disable;

    if(drawStandardBackground)
        setBackgroundBrush(backgroundColor);
    else
        setBackgroundBrush(Qt::transparent);
}

void SvgMapView::openWormhole(const QString &systemName)
{
    if(!m_map->contains(systemName))
        return;

    if(!wormholes.contains(systemName))
    {
        MapShape* shape = new MapShape();
        if(m_theme)
        {
            shape->load(m_theme->getAttribute("wormholeGraphic").toString());
            shape->setOpacity(m_theme->getAttribute("wormholeOpacity").toDouble());
            shape->setScale(m_theme->getAttribute("wormholeScale").toDouble());
            shape->setZValue(m_theme->getAttribute("wormholeZ").toDouble());
            shape->setXOffset(m_theme->getAttribute("wormholeXOffset").toDouble());
            shape->setYOffset(m_theme->getAttribute("wormholeYOffset").toDouble());
        }
        wormholes.insert(systemName, shape);
        shape->setPos(m_map->getCoordinates(systemName));
        mapScene.addItem(wormholes[systemName]);
    }
}

void SvgMapView::closeWormhole(const QString &systemName)
{
    if(!m_map->contains(systemName))
        return;

    if(wormholes.contains(systemName))
    {
        MapShape* shape = wormholes[systemName];
        mapScene.removeItem(shape);
        wormholes.remove(systemName);
        delete shape;
    }
}
