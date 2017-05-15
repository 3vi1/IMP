#include "msgstyle.h"

MsgStyle::MsgStyle(QWidget *parent) : QWidget(parent)
{
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
