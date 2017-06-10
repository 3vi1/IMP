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


// OMG this class needs to be re-thunk.  It works, but efficiency was not in my planning.

ChatItemDelegate::ChatItemDelegate(const MsgStyle* style, QObject *parent) : QStyledItemDelegate(parent),
    m_msgStyle(style)
{
}

void ChatItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
           const QModelIndex &index ) const
{
    if (index.column() == 0) {

        QStyleOptionViewItem options = option;
        initStyleOption(&options, index);

        painter->save();


        QTextDocument* doc = document(options);

        options.text = "";
        options.widget->style()->drawControl(QStyle::CE_ItemViewItem, &options, painter);

        // shift text right to make icon visible
        QSize iconSize = options.icon.actualSize(options.rect.size());
        painter->translate(options.rect.left()+iconSize.width(), options.rect.top());
        QRect clip(0, 0, options.rect.width()+iconSize.width(), options.rect.height());

        painter->setClipRect(clip);
        QAbstractTextDocumentLayout::PaintContext ctx;

/*        if (option.state & QStyle::State_Selected)
            ctx.palette.setColor(QPalette::Text, QColor("white"));
            // Maybe we'll bring back selected colors later
            */

        ctx.clip = clip;
        doc->documentLayout()->draw(painter, ctx);
        painter->restore();

        delete doc;
    }
}

void ChatItemDelegate::setModel(ChatModel* model)
{
    m_model = model;
}

QTextDocument* ChatItemDelegate::document(const QStyleOptionViewItem &option) const
{
    QStyleOptionViewItem options = option;
    options.text = options.text.replace("<clear>", "<span style=\"color: " + m_msgStyle->getClearColor().name() + "\">");
    options.text = options.text.replace("<info>", "<span style=\"color: " + m_msgStyle->getInfoColor().name() + "\">");
    options.text = options.text.replace("<gate>", "<span style=\"color: " + m_msgStyle->getGateColor().name() + "\">");
    options.text = options.text.replace("<location>", "<span style=\"color: " + m_msgStyle->getLocationColor().name() + "\">");
    options.text = options.text.replace("<ship>", "<span style=\"color: " + m_msgStyle->getShipColor().name() + "\">");
    options.text = options.text.replace("<stamp>", "<span style=\"color: " + m_msgStyle->getStampColor().name() + "\">");
    options.text = options.text.replace("<status>", "<span style=\"color: " + m_msgStyle->getStatusColor().name() + "\">");
    options.text = options.text.replace("<system>", "<span style=\"color: " + m_msgStyle->getSystemColor().name() + "\">");
    options.text = options.text.replace("<warn>", "<span style=\"color: " + m_msgStyle->getWarnColor().name() + "\">");

    QTextDocument* doc = new QTextDocument();
    doc->setHtml(options.text);

    QTextOption textOption(doc->defaultTextOption());
    textOption.setWrapMode(QTextOption::WordWrap);
    doc->setDefaultTextOption(textOption);

    int iconWidth = (options.icon.isNull() ? 0 : m_avatarSize.width());
    doc->setTextWidth(options.rect.width() - iconWidth - padding.width());

    return doc;
}

QSize ChatItemDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex &index) const
{
    QStyleOptionViewItem options = option;
    initStyleOption(&options, index);

    QTextDocument* doc = document(options);

    int iconWidth = (options.icon.isNull() ? 0 : m_avatarSize.width());

    QSize textSize = QSize(doc->idealWidth() + iconWidth,
                           doc->size().height() > m_avatarSize.height() ?
                               doc->size().height() + padding.height() :
                               m_avatarSize.height() + padding.height());

    delete doc;
    return textSize;
}

QString ChatItemDelegate::anchorAt(const QStyleOptionViewItem& option,
                                   const QModelIndex &index,
                                   const QPoint &point)
{
    QStyleOptionViewItem options = option;
    initStyleOption(&options, index);

    QTextDocument* doc = document(options);
    QAbstractTextDocumentLayout* textLayout = doc->documentLayout();

    Q_ASSERT(textLayout != 0);

    // Need to shift the click position if there was an avatar/icon.
    int iconWidth = (options.icon.isNull() ? 0 : m_avatarSize.width());
    QPoint p = point;
    p.setX(p.x() - iconWidth - padding.width());

    QString anchor = textLayout->anchorAt(p);
    delete doc;
    return anchor;
}
