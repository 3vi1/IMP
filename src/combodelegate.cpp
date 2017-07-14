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

#include "combodelegate.h"

#include <QComboBox>
#include <QDialog>
#include <QMouseEvent>
#include <QPainter>
#include <QVariant>

ComboDelegate::ComboDelegate(QObject *parent) : QStyledItemDelegate(parent)
{

}

QWidget* ComboDelegate::createEditor(QWidget *parent,
                                  const QStyleOptionViewItem& /*option*/,
                                  const QModelIndex& /*index*/) const
{
    QComboBox* editor = new QComboBox(parent);
    editor->clear();
    foreach(QString item, comboItems)
    {
        editor->addItem(item);
    }
    return editor;
}

void ComboDelegate::setItems(QStringList items)
{
    comboItems.clear();
    comboItems.append(items);
}

// Gets the data from Model and feeds the data to delegate Editor
void ComboDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString currentText = index.model()->data(index, Qt::EditRole).toString();

    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    comboBox->setCurrentText(currentText);
}

 // When we modify data, this model reflect the change
 // Data from the delegate to the model
 void ComboDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
 {
     QComboBox *comboBox = static_cast<QComboBox*>(editor);
     QString text = comboBox->itemText(0);
     model->setData(index, comboBox->currentText(), Qt::EditRole);
 }

// Give the info on size and location
void ComboDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex & /*index*/) const
{
    editor->setGeometry(option.rect);
}
