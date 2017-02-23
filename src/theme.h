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

#ifndef THEME_H
#define THEME_H

#include <QColor>
#include <QDataStream>
#include <QDir>
#include <QObject>
#include <QSettings>


enum ThemeType { THEME_DEFAULT, THEME_USER };
Q_DECLARE_METATYPE(ThemeType)

enum ThemeObject {
    PILOT,
    FIND,
    LINES,
    SYSTEM
};
Q_DECLARE_METATYPE(ThemeObject)

inline QDataStream& operator>>(QDataStream& in, ThemeObject& to)
{
    int IntType;
    in >> IntType;
    to = static_cast<ThemeObject>(IntType);
    return in;
}

inline QDataStream& operator<<(QDataStream& out, ThemeObject& to)
{
    out << (int)to;
    return out;
}

struct ThemeStorage {
    ThemeObject objType;
    QString     name;
    QString     member;
    QVariant    data;

    friend QDataStream& operator<<(QDataStream& out, const ThemeStorage& ts)
    {
        out << ts.objType << ts.name << ts.member << ts.data;
        return out;
    }

    friend QDataStream& operator>>(QDataStream& in, ThemeStorage& ts)
    {
        in >> ts.objType >> ts.name >> ts.member >> ts.data;
        return in;
    }

};
Q_DECLARE_METATYPE(ThemeStorage)

typedef QMap<QString, ThemeStorage> AttributeMap;
Q_DECLARE_METATYPE(AttributeMap)

inline QDataStream &operator<<(QDataStream &out, const AttributeMap &aMap)
{
    QVariant count = aMap.count();
    out << count;
    foreach(QString key, aMap.keys())
    {
       out << key << aMap[key];
    }
   return out;
}

inline QDataStream &operator>>(QDataStream &in, AttributeMap &aMap)
{
    QVariant count;
    QString key;
    ThemeStorage value;
    in >> count;
    for(int i = 0; i < count.toInt(); i++)
    {
        in >> key >> value;
        aMap[key] = value;
    }
    return in;
}

class Theme : public QObject
{
    Q_OBJECT

public:
    explicit Theme(QObject *parent = 0);

    void load(const QString& name, ThemeType themeType);
    bool save(const QString& name);

    // getters
    QString& name() {return m_name;}

    // setters
    void setBackColor(const QColor& c){m_backColor = c; emit backColorChanged(c);}
    void setLineColor(const QColor& c){m_lineColor = c; emit lineColorChanged(c);}
    void setName(const QString& s){m_name = s;}

    QVariant getAttribute(const QString& saveName);

    void setAttribute(const QString& saveName,
                      ThemeObject objType,
                      QString name,
                      QString member,
                      QVariant data);

    bool attributeExists(const QString &name);

signals:
    // Legacy.  I'm removing all these except sendUpdate, in favor of attributes.
    void backColorChanged(const QColor&);
    void lineColorChanged(const QColor&);

    void sendUpdate(ThemeStorage& a);

public slots:

private:
    void packageImage(const QString &themePath, const QString& saveName);

    const QString m_themeIni = "/theme.ini";

    QDir            m_defaultDir;
    QDir            m_userDir;
    QString         m_name;

    AttributeMap    attributes;

    QColor          m_backColor     = Qt::white;

    QColor          m_lineColor     = Qt::black;
    qreal           m_lineWidth     = 1;
    qreal           m_lineOpacity   = 1;
    qreal           m_lineZ         = -2;
};

#endif // THEME_H
