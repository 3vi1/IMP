#ifndef MSGSTYLE_H
#define MSGSTYLE_H

#include <QWidget>

class MsgStyle : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor clearColor READ getClearColor WRITE setClearColor DESIGNABLE true SCRIPTABLE true)
    Q_PROPERTY(QColor gateColor READ getGateColor WRITE setGateColor DESIGNABLE true SCRIPTABLE true)
    Q_PROPERTY(QColor infoColor READ getInfoColor WRITE setInfoColor DESIGNABLE true SCRIPTABLE true)
    Q_PROPERTY(QColor locationColor READ getLocationColor WRITE setLocationColor DESIGNABLE true SCRIPTABLE true)
    Q_PROPERTY(QColor shipColor READ getShipColor WRITE setShipColor DESIGNABLE true SCRIPTABLE true)
    Q_PROPERTY(QColor stampColor READ getStampColor WRITE setStampColor DESIGNABLE true SCRIPTABLE true)
    Q_PROPERTY(QColor statusColor READ getStatusColor WRITE setStatusColor DESIGNABLE true SCRIPTABLE true)
    Q_PROPERTY(QColor systemColor READ getSystemColor WRITE setSystemColor DESIGNABLE true SCRIPTABLE true)
    Q_PROPERTY(QColor warnColor READ getWarnColor WRITE setWarnColor DESIGNABLE true SCRIPTABLE true)

public:
    explicit MsgStyle(QWidget *parent = 0);

    QColor getClearColor() const { return m_clearColor; }
    void setClearColor( const QColor c ) { m_clearColor = c; }

    QColor getGateColor() const { return m_gateColor; }
    void setGateColor( const QColor c ) { m_gateColor = c; }

    QColor getInfoColor() const { return m_infoColor; }
    void setInfoColor( const QColor c ) { m_infoColor = c; }

    QColor getLocationColor() const { return m_locationColor; }
    void setLocationColor( const QColor c ) { m_locationColor = c; }

    QColor getShipColor() const { return m_shipColor; }
    void setShipColor( const QColor c ) { m_shipColor = c; }

    QColor getStampColor() const { return m_stampColor; }
    void setStampColor( const QColor c ) { m_stampColor = c; }

    QColor getStatusColor() const { return m_statusColor; }
    void setStatusColor( const QColor c ) { m_statusColor = c; }

    QColor getSystemColor() const { return m_systemColor; }
    void setSystemColor( const QColor c ) { m_systemColor = c; }

    QColor getWarnColor() const { return m_warnColor; }
    void setWarnColor( const QColor c ) { m_warnColor = c; }

signals:

public slots:

private:

    QColor  m_clearColor = Qt::green;
    QColor  m_gateColor = Qt::darkBlue;
    QColor  m_infoColor = Qt::darkMagenta;
    QColor  m_locationColor = Qt::darkRed;
    QColor  m_shipColor = Qt::darkYellow;
    QColor  m_stampColor = Qt::black;
    QColor  m_statusColor = Qt::darkCyan;
    QColor  m_systemColor = Qt::blue;
    QColor  m_warnColor = Qt::red;
};

#endif // MSGSTYLE_H
