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

#ifndef ALARMMODEL_H
#define ALARMMODEL_H

#include <QComboBox>
#include <QAbstractTableModel>

struct Alarm
{
    uint    jumps;
    QString file;
    float   volume;
};

class AlarmModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit AlarmModel(QObject *parent = 0);

    const Alarm& at(int distance) {return alarms[distance];}
    int count() {return alarms.count();}

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    // Add data:
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    void insertAlarm(QString filename, float volume);
    //void removeAlarm(const QModelIndexList indexList);
    QList<Alarm> getAlarms();
    void setAlarms(QList<Alarm> newAlarms);

    QList<QComboBox> alarmCombos;

private:
    QList<Alarm> alarms;
};

#endif // AlarmModel_H
