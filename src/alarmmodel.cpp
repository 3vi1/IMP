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

#include <QComboBox>
#include "alarmmodel.h"

AlarmModel::AlarmModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

QVariant AlarmModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("Jumps");
            case 1:
                return QString("Alarm");
            case 2:
                return QString("Volume");
            case 3:
                return QString("Play");
            }
        }
        else
        {
            return section + 1;
        }
    }
    return QVariant();
}

int AlarmModel::rowCount(const QModelIndex& /*&parent*/) const
{
    return alarms.count();
}

int AlarmModel::columnCount(const QModelIndex& /*&parent*/) const
{
    return 4;
}

QVariant AlarmModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch(role)
    {
    case Qt::TextAlignmentRole:
        switch(index.column())
        {
        case 0:
            return Qt::AlignRight;
        default:
            return Qt::AlignHCenter;
        }
        break;

    case Qt::DisplayRole:
    case Qt::EditRole:
        if (index.row() < alarms.count())
        {
            switch (index.column())
            {
            case 0:
                return alarms[index.row()].jumps;
            case 1:
                return alarms[index.row()].file;
            case 2:
                return alarms[index.row()].volume;
            default:
                break;
            }
        }
        break;

    case Qt::CheckStateRole:
        if (index.row() < alarms.count())
        {
            switch (index.column())
            {
            default:
                break;
            }
        }
        break;

    case Qt::ToolTipRole:
        switch (index.column())
        {
        case 0:
            return QString("Number of jumps away");
        case 1:
            return QString("Sound file to play on alarm");
        case 2:
            return QString("Volume level of the alarm");
        case 3:
            return QString("Test the sound/volume");
        default:
            break;
        }
    }

    return QVariant();
}

bool AlarmModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::EditRole)
    {
        switch (index.column())
        {
        case 0:
            alarms[index.row()].jumps = value.toInt();
            break;
        case 1:
            alarms[index.row()].file = value.toString();
            break;
        case 2:
            alarms[index.row()].volume = value.toFloat();
            break;
        default:
            break;
        }

        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }

    return false;
}

Qt::ItemFlags AlarmModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    if (index.column() == 0 || index.column() == 3)
    {
        return Qt::ItemIsEnabled | QAbstractTableModel::flags(index);
    }
    else
    {
        return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
    }
}

bool AlarmModel::insertRows(int row, int count, const QModelIndex &parent)
{
    if(row < 0)
        row = alarms.count();

    beginInsertRows(parent, row, row + count - 1);

    alarms.insert(row, Alarm{(uint)row, "red-alert.wav", 1.0});
    for(int i = 0; i < alarms.count(); i++)
    {
        alarms[i].jumps = i;
    }

    endInsertRows();
    return true;
}

bool AlarmModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if(row < 0)
        row = alarms.count() - 1;

    beginRemoveRows(parent, row, row + count - 1);
    if(row == 0 && count == alarms.count())
    {
        alarms.clear();
    }
    else
    {
        for(int i = 0; i < count; i++)
        {
            alarms.removeAt(row);
        }
    }

    for(int i = 0; i < alarms.count(); i++)
    {
        alarms[i].jumps = i;
    }

    endRemoveRows();

    return true;
}

void AlarmModel::insertAlarm(QString filename, float volume)
{
    beginInsertRows(QModelIndex(), alarms.count(), alarms.count());

    alarms.insert(alarms.count(), Alarm{(uint)alarms.count(), filename, volume});

    endInsertRows();
}

QList<Alarm> AlarmModel::getAlarms()
{
    return alarms;
}

void AlarmModel::setAlarms(QList<Alarm> newAlarms)
{
    if(newAlarms.count() <= 0)
        return;

    if(alarms.count() > 0)
    {
        beginRemoveRows(QModelIndex(), 0, alarms.count()-1);
        alarms.clear();
        endRemoveRows();
    }

    beginInsertRows(QModelIndex(), 0, newAlarms.count()-1);
    alarms = newAlarms;
    endInsertRows();
}
