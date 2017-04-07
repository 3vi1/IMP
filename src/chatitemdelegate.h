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

#ifndef CHATITEMDELEGATE_H
#define CHATITEMDELEGATE_H

#include <QItemDelegate>
#include <QObject>
#include <QStyledItemDelegate>

#include "chatmodel.h"

class ChatItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit ChatItemDelegate(QObject *parent = Q_NULLPTR);

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index ) const override;
    void setModel(ChatModel* model);
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

signals:
public slots:

private:
    ChatModel*  m_model;
    QSize       m_avatarSize = QSize(64,64);
    QSize       padding = QSize(2,1);
};

#endif // CHATITEMDELEGATE_H
