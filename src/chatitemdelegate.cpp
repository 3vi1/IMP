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

#include "chatitemdelegate.h"

ChatItemDelegate::ChatItemDelegate(QObject *parent) : QItemDelegate(parent)
{
}

void ChatItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
           const QModelIndex &index ) const
{
    if (index.column() == 0) {
        QItemDelegate::paint(painter, option, index);
        return;
    }

    /* This is not really used yet..  For future plans
    */
}

void ChatItemDelegate::setModel(ChatModel* model)
{
    m_model = model;
}

QSize ChatItemDelegate::sizeHint(const QStyleOptionViewItem& /*option*/, const QModelIndex &index) const
{
    // Yes.  I'm guessing.  I welcome a real way to get the right
    // text height.

    int guess = (m_model->data(index).toString().length() * .2);
    return QSize(0, guess + 64);
}
