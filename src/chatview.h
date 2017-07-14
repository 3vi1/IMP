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

#ifndef CHATVIEW_H
#define CHATVIEW_H

#include <QListView>

class ChatView : public QListView
{
    Q_OBJECT
public:
    explicit ChatView(QWidget *parent = 0);

signals:
    void linkActivated(QString link);
    void linkHovered(QString link);
    void linkUnhovered();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    QString anchorAt(const QPoint &pos) const;

private:
    QString _mousePressAnchor;
    QString _lastHoveredAnchor;
};

#endif // CHATVIEW_H
