#include <QApplication>
#include <QCursor>
#include <QMouseEvent>

#include "chatview.h"
#include "chatitemdelegate.h"

ChatView::ChatView(QWidget *parent) : QListView(parent)
{
    // needed for the hover functionality
    setMouseTracking(true);
}

void ChatView::mousePressEvent(QMouseEvent *event) {
    QListView::mousePressEvent(event);

    QString anchor = anchorAt(event->pos());
    _mousePressAnchor = anchor;
}

void ChatView::mouseMoveEvent(QMouseEvent *event) {
    auto anchor = anchorAt(event->pos());

    if (_mousePressAnchor != anchor) {
        _mousePressAnchor.clear();
    }

    if (_lastHoveredAnchor != anchor) {
        _lastHoveredAnchor = anchor;
        if (!_lastHoveredAnchor.isEmpty()) {
            QApplication::setOverrideCursor(QCursor(Qt::PointingHandCursor));
            emit linkHovered(_lastHoveredAnchor);
        } else {
            QApplication::restoreOverrideCursor();
            emit linkUnhovered();
        }
    }
}

void ChatView::mouseReleaseEvent(QMouseEvent *event) {
    if (!_mousePressAnchor.isEmpty()) {
        auto anchor = anchorAt(event->pos());

        if (anchor == _mousePressAnchor) {
            emit linkActivated(_mousePressAnchor);
        }

        _mousePressAnchor.clear();
    }

    QListView::mouseReleaseEvent(event);
}

QString ChatView::anchorAt(const QPoint &pos) const {
    QModelIndex index = indexAt(pos);
    if (index.isValid()) {
        auto delegate = itemDelegate(index);
        auto chatDelegate = qobject_cast<ChatItemDelegate*>(delegate);
        if (chatDelegate != 0) {

            //-----jj
            QStyleOptionViewItem option;
            option.widget = this;
            option.text = model()->data(index, Qt::DisplayRole).toString();
            option.icon = model()->data(index, Qt::DecorationRole).value<QIcon>();


            QRect itemRect = visualRect(index);
            QPoint relativeClickPosition = pos - itemRect.topLeft();
            option.rect = itemRect;

            return chatDelegate->anchorAt(option, index, relativeClickPosition);
        }
    }

    return QString();
}
