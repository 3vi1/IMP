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
