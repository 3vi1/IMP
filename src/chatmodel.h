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

#ifndef CHATMODEL_H
#define CHATMODEL_H

#include <QAbstractListModel>
#include <QList>
#include "parser.h"
#include "asyncinfo.h"

class ChatModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ChatModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    void setPilotCache(QMap<QString, PilotEntry>* pilotCache);
    void subsetForSystem(const QString &system);
    void subsetForString(const QString &string);
    void addEntry(const MessageInfo &message);
    void truncateTo(int i);

    void avatarChanged();

private:
    QList<MessageInfo> items;
    QMap<QString, PilotEntry>* pilotCache;

    QPixmap unknownPilot = QPixmap(":/graphics/impicon.png").scaledToHeight(64);

    QList<MessageInfo*> visibleItems;
    QString subset = "";
    bool    subsetOnSystem = false;
};

#endif // CHATMODEL_H
