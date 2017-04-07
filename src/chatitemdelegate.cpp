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

#include <QAbstractTextDocumentLayout>
#include <QApplication>
#include <QPainter>
#include <QTextDocument>

ChatItemDelegate::ChatItemDelegate(QObject *parent) : QStyledItemDelegate(parent)
{
}

void ChatItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
           const QModelIndex &index ) const
{
    if (index.column() == 0) {

        QStyleOptionViewItem options = option;
        initStyleOption(&options, index);

        painter->save();

        QTextDocument doc;
        doc.setHtml(options.text);

        QTextOption textOption(doc.defaultTextOption());
        textOption.setWrapMode(QTextOption::WordWrap);
        doc.setDefaultTextOption(textOption);
        doc.setTextWidth(options.rect.width() - m_avatarSize.width() - padding.width());

        options.text = "";
        options.widget->style()->drawControl(QStyle::CE_ItemViewItem, &options, painter);

        // shift text right to make icon visible
        QSize iconSize = options.icon.actualSize(options.rect.size());
        painter->translate(options.rect.left()+iconSize.width(), options.rect.top());
        QRect clip(0, 0, options.rect.width()+iconSize.width(), options.rect.height());

        painter->setClipRect(clip);
        QAbstractTextDocumentLayout::PaintContext ctx;

        if (option.state & QStyle::State_Selected)
            ctx.palette.setColor(QPalette::Text, QColor("white"));

        ctx.clip = clip;
        doc.documentLayout()->draw(painter, ctx);
        painter->restore();
    }
}

void ChatItemDelegate::setModel(ChatModel* model)
{
    m_model = model;
}

QSize ChatItemDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex &index) const
{
    QStyleOptionViewItem options = option;
    initStyleOption(&options, index);

    QTextDocument doc;
    doc.setHtml(options.text);

    QTextOption textOption(doc.defaultTextOption());
    textOption.setWrapMode(QTextOption::WordWrap);
    doc.setDefaultTextOption(textOption);
    doc.setTextWidth(options.rect.width() - m_avatarSize.width() - padding.width());

    QSize textSize = QSize(doc.idealWidth() + m_avatarSize.width(), doc.size().height());
    return m_avatarSize.height() > doc.size().height() ?
                QSize(doc.idealWidth(), m_avatarSize.height() + padding.height()) : textSize;
}
