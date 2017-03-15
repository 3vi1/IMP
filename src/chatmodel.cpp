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

#include "chatmodel.h"

ChatModel::ChatModel(Options *options, QObject *parent)
    : QAbstractListModel(parent)
{
    _options = options;
}

void ChatModel::setPilotCache(QMap<QString, PilotEntry>* pilotCache)
{
    this->pilotCache = pilotCache;
}

void ChatModel::addEntry(const MessageInfo& message)
{
    beginInsertRows(QModelIndex(), items.size(), items.size());

    items.append(message);

    if(subset == "" ||
            (subsetOnSystem && message.systems.contains(subset)) ||
            (!subsetOnSystem && message.text.contains(subset)))
    {
        visibleItems.append(&items[items.count()-1]);
    }
    endInsertRows();
}

void ChatModel::truncateTo(int i)
{
    if (i == 0 || items.size() < i)
    {
        // We already have fewer rows than the requested max.
        return;
    }

    removeRows(0, visibleItems.size() - i);
}

int ChatModel::rowCount(const QModelIndex & /*parent*/) const
{
    return visibleItems.count();
}

int ChatModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 1;
}

QVariant ChatModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int row = index.row();

    MessageInfo message;

    message = *visibleItems.at(row);

    switch(role){
    case Qt::DecorationRole:
        if(!_options->showAvatar())
        {
            return (QPixmap());
        }
        else if(pilotCache->contains(message.sender))
        {
            return (QPixmap)((*pilotCache)[message.sender].avatar);
        }
        else
        {
            return unknownPilot;
        }
        break;
    case Qt::DisplayRole:
        return "(" + message.logInfo->channel + " @ " +
                message.dateTime.toString("hh:mm:ss") + " " + message.sender + ")\n" +
                message.text;
        break;
    }

    return QVariant();
}

void ChatModel::avatarChanged()
{
    QModelIndex miFrom = createIndex(0, 0);
    QModelIndex miTo = createIndex(0, visibleItems.size());
    emit dataChanged(miFrom, miTo);
}

bool ChatModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if(count == 0)
    {
        return true;
    }

    beginRemoveRows(parent, row, (row + count) - 1);
    if(row == 0 && count == items.count())
    {
        items.clear();
        visibleItems.clear();
    }
    else
    {
        for(int i = 0; i < count; i++)
        {
            visibleItems.removeAt(row);
        }
    }
    endRemoveRows();

    return true;
}

void ChatModel::subsetForSystem(const QString& system)
{
    subset = system;

    if(system != "")
    {
        subsetOnSystem = true;
    }
    else
    {
        subsetOnSystem = false;
    }

    beginRemoveRows(QModelIndex(), 0, visibleItems.count() - 1);
    visibleItems.clear();
    endRemoveRows();

    for(int i = 0; i < items.count(); i++)
    {
        beginInsertRows(QModelIndex(), visibleItems.count(), 1);
        if(system == "" || items[i].systems.contains(system))
        {
            visibleItems.append(&items[i]);
        }
        endInsertRows();
    }
}

void ChatModel::subsetForString(const QString& string)
{
    subset = string;
    subsetOnSystem = false;

    beginRemoveRows(QModelIndex(), 0, visibleItems.count() - 1);
    visibleItems.clear();
    endRemoveRows();

    for(int i = 0; i < items.count(); i++)
    {
        beginInsertRows(QModelIndex(), visibleItems.count(), 1);
        if(string == "" || items[i].text.contains(string))
        {
            visibleItems.append(&items[i]);
        }
        endInsertRows();
    }
}
