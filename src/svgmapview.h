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

#ifndef SVGMAPVIEW_H
#define SVGMAPVIEW_H

#include <QGraphicsView>
#include <QtSvg/QGraphicsSvgItem>
#include <QGraphicsTextItem>
#include <QWidget>
#include <QString>
#include <QSvgRenderer>
#include <QWheelEvent>

#include "map.h"
#include "mapscene.h"
#include "mapshape.h"
#include "systemshape.h"
#include "theme.h"


class SvgMapView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit SvgMapView(QWidget *parent = 0);

    void setMap(Map* m){m_map = m;}

    void clearLines();
    void clearMap();
    void clearShapes();
    void clearTexts();

    void findLocation(const QString &systemName);

    int         getHorizontalScroll();
    QFont       getNameFont(){return nameFont;}
    QRectF      getSceneRect();
    qreal       getSystemsRotation();
    QFont       getTimeFont(){return timeFont;}
    QTransform  getTransform();
    int         getVerticalScroll();
    QRect       getViewRect();
    QPointF     getViewportCenter();

    void setHorizontalScroll(int x);
    void setLoadText(const QString text);
    void setNameFont(QFont newFont);
    void setSceneRect(QRectF rect);

    void resetRotation();
    void rotateSystems(qreal angle);

    void setTheme(Theme* theme){m_theme = theme;}
    void setTimeFont(QFont newFont);
    void setTransform(QTransform transform);
    void setVerticalScroll(int y);
    void setViewRect(QRect rect);
    void setZoom(float factor);

    void addBridge(QGraphicsLineItem *arrow);
    void showBridges(bool enable);

    void addLine(QGraphicsLineItem *line);
    void updateLinesColor(QColor color);

    void resetCtrl(){controlKeyDown = false;}

signals:
    void systemClicked(const QString& name);
    void sendOpacity(int delta);

public slots:
    void showMap(bool enable);

    void enablePilot(QString pilot);
    void disablePilot(QString pilot);

    void gotLine(qreal x1, qreal x2, qreal y1, qreal y2, const QString& connectionClass);
    void gotSystem(const QString& name, QPointF position, const QString& systemClass, const QString &description);
    void gotSystemPosition(const QString& name, QPointF position);
    void gotSystemTime(const QString& name, const QString& text, QColor timeColor);
    void gotSystemColor(const QString& name, QColor color);

    void gotPilotLocation(const QString &pilotName, const QString &systemName, bool enabled = true);
    void gotSystemShapesFile(QString shapesFile);

    void receiveThemeUpdate(ThemeStorage &a);

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void wheelEvent(QWheelEvent *event);

private:
    void handleLine(QGraphicsLineItem* line,
                    const QString &member,
                    QVariant& data);

    void handleShape(MapShape* shape,
                     const QString &member,
                     QVariant& data);

    //template <class T>
    //void repositionBackground(T* background);

    void setTextPosition(QGraphicsTextItem *ti, QPointF pos, QPointF offset);

    Map*                        m_map = NULL;
    Theme*                      m_theme = NULL;

    MapShape*                   findShape;
    QMap<QString, MapShape*>    pilotShapes;
    QString                     m_pilotGraphic;
    QColor                      m_linesColor;

    bool altKeyDown = false;
    bool controlKeyDown = false;
    bool drawBridges = false;
    float zoom = 1;

    //bool middlePressed = false;
    //QPoint startPosition;

    QTransform savedTransform = QTransform();

    QSvgRenderer* systemRenderer = NULL;

    QGraphicsScene loadingScene;
    MapScene mapScene;

    QGraphicsPixmapItem* logo;
    QGraphicsSvgItem* svgLoading;
    QGraphicsSimpleTextItem* loadText;

    QList<QGraphicsLineItem*> arrows;
    QList<QGraphicsLineItem*> lines;
    QColor _linesColor = Qt::black;

    QSet<QGraphicsSvgItem*> svgItems;
    QMap<QString, SystemShape*> systemShapes;
    QMap<QString, MapShape*> systemOutlines;

    QMap<QString, QGraphicsTextItem*> m_texts;
    QFont nameFont;
    QFont timeFont;

    QPointF nameOffset = QPointF(0, -6);
    QPointF timeOffset = QPointF(0, +4);

    QRectF savedSceneRect;
    QGraphicsPixmapItem* backPixmap = NULL;
    QGraphicsSvgItem* backSvg = NULL;
    qreal backgroundOpacity = 1.0;
    qreal backgroundScale = 1.0;
    qreal backgroundZ = -10;
    QPointF backgroundOffset = QPointF(0, 0);

    template<class T>
    void inline removeBackground(T* background)
    {
        if(background != NULL)
        {
            if(mapScene.items().contains(background))
            {
                mapScene.removeItem(background);
            }
            delete background;
            background = NULL;
        }
    }

    template <class T>
    void inline repositionBackground(T* background)
    {
        background->setPos(
                    ((
                        (sceneRect().bottomRight() + sceneRect().topLeft())
                        * 0.5f
                    ) -
                    (background->boundingRect().bottomRight() * 0.5f)
                    * backgroundScale )
                    + backgroundOffset
                );
    }

};

#endif
