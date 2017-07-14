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

    void reset();

signals:

public slots:

private:

    QColor  m_clearColor;
    QColor  m_gateColor;
    QColor  m_infoColor;
    QColor  m_locationColor;
    QColor  m_shipColor;
    QColor  m_stampColor;
    QColor  m_statusColor;
    QColor  m_systemColor;
    QColor  m_warnColor;
};

#endif // MSGSTYLE_H
