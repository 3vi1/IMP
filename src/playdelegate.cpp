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

#include "playdelegate.h"

#include <QApplication>
#include <QDebug>
#include <QMouseEvent>

PlayDelegate::PlayDelegate(QObject *parent) : QStyledItemDelegate(parent)
{

}

void PlayDelegate::paint(QPainter *painter,
                         const QStyleOptionViewItem &option,
                         const QModelIndex &/*index*/) const
 {
     QStyleOptionButton button;
     button.rect = option.rect;
     button.icon = QIcon(":/graphics/volume-icon.png");
     button.state = QStyle::State_Enabled;
     QApplication::style()->drawControl( QStyle::CE_PushButton, &button, painter);
 }

 bool PlayDelegate::editorEvent(QEvent *event,
                                QAbstractItemModel *model,
                                const QStyleOptionViewItem &option,
                                const QModelIndex &index)
 {
     if( event->type() == QEvent::MouseButtonRelease )
     {
         QMouseEvent * e = (QMouseEvent *)event;
         if (option.rect.contains(e->x(),e->y()))
         {
             qDebug() << "PlayDelegate signaling" << model->index(index.row(), 1).data(Qt::DisplayRole).toString()
                      << "@" << model->index(index.row(), 2).data(Qt::DisplayRole).toFloat();
             emit playSound(model->index(index.row(), 1).data(Qt::DisplayRole).toString(),
                            model->index(index.row(), 2).data(Qt::DisplayRole).toFloat());
             return true;
         }
     }

     return false;
 }
