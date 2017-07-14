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

#include "msgstyle.h"

MsgStyle::MsgStyle(QWidget *parent) : QWidget(parent)
{
    resize(0,0);
    reset();
}

void MsgStyle::reset()
{
    m_clearColor = Qt::green;
    m_gateColor = Qt::darkBlue;
    m_infoColor = Qt::darkMagenta;
    m_locationColor = Qt::darkRed;
    m_shipColor = Qt::darkYellow;
    m_stampColor = Qt::black;
    m_statusColor = Qt::darkCyan;
    m_systemColor = Qt::blue;
    m_warnColor = Qt::red;
}
