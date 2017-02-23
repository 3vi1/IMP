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

#include "rulemodel.h"

RuleModel::RuleModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

QVariant RuleModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("");
            case 1:
                return QString("Channel");
            case 2:
                return QString("Match");
            case 3:
                return QString("Action");
            case 4:
                return QString("");
            }
        }
        else
        {
            return section + 1;
        }
    }
    return QVariant();
}

int RuleModel::rowCount(const QModelIndex& /*&parent*/) const
{
    return rules.count();
}

int RuleModel::columnCount(const QModelIndex& /*&parent*/) const
{
    return 5;
}

QVariant RuleModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch(role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
        if (index.row() < rules.count())
        {
            switch (index.column())
            {
            case 1:
                return rules[index.row()].channel;
            case 2:
                return rules[index.row()].match;
            case 3:
                return rules[index.row()].action;
            default:
                break;
            }
        }
        break;

    case Qt::CheckStateRole:
        if (index.row() < rules.count())
        {
            switch (index.column())
            {
            case 0:
                if(rules[index.row()].enabled)
                    return Qt::CheckState::Checked;
                return Qt::CheckState::Unchecked;
            case 4:
                if(rules[index.row()].continueOnMatch)
                    return Qt::CheckState::Checked;
                return Qt::CheckState::Unchecked;
            default:
                break;
            }
        }
        break;

    case Qt::ToolTipRole:
        switch (index.column())
        {
        case 0:
            return QString("Enabled?");
        case 1:
            return QString("Regular expression matching the channel name to which this rule applies.");
        case 2:
            return QString("regular expression for the string to match (includes \"[Date Time] sender > \" portion of text).");
        case 3:
            return QString("What do do when match is found (usually 'play soundfilename.wav')");
        case 4:
            return QString("Continue processing subsequent rules if this one matches?");
        default:
            break;
        }
    }

    return QVariant();
}

bool RuleModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::EditRole)
    {
        switch (index.column())
        {
        case 0:
            rules[index.row()].enabled = value.toBool();
            break;
        case 1:
            rules[index.row()].channel = value.toString();
            break;
        case 2:
            rules[index.row()].match = value.toString();
            break;
        case 3:
            rules[index.row()].action = value.toString();
            break;
        case 4:
            rules[index.row()].continueOnMatch = value.toBool();
            break;
        default:
            break;
        }

        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    else if (role == Qt::CheckStateRole &&
             (index.column() == 0 || index.column() == 4))
    {
        rules[index.row()].enabled = value.toBool();
        return true;
    }

    return false;
}

Qt::ItemFlags RuleModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    if (index.column() == 0 || index.column() == 4)
    {
        return Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | QAbstractTableModel::flags(index);
    }
    else
    {
        return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
    }
}

bool RuleModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    rules.insert(row, Rule{false, "", "", "", true});
    endInsertRows();

    return true;
}

bool RuleModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    //rules.removeAt(row);
    if(row == 0 && count == rules.count())
    {
        rules.clear();
    }
    else
    {
        for(int i = 0; i < count; i++)
        {
            rules.removeAt(row);
        }
    }
    endRemoveRows();

    return true;
}

void RuleModel::insertRule(const QModelIndexList indexList)
{
    int row = indexList.count() > 0 ?
                indexList[0].row() : rules.count();
    insertRows(row, 1, QModelIndex());
}

void RuleModel::removeRule(const QModelIndexList indexList)
{
    int row = indexList.count() > 0 ?
                indexList[0].row() : rules.count() - 1;
    removeRows(row, 1, QModelIndex());
}

QList<Rule> RuleModel::getRules()
{
    return rules;
}

void RuleModel::setRules(QList<Rule> newRules)
{
    if(newRules.count() <= 0)
        return;

    beginRemoveRows(QModelIndex(), 0, rules.count()-1);
    rules.clear();
    endRemoveRows();
    beginInsertRows(QModelIndex(), 0, newRules.count()-1);
    rules = newRules;
    endInsertRows();
}
