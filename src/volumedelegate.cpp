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

#include "volumedelegate.h"

//#include <QApplication>
#include <QDebug>
#include <QPainter>
#include <QPaintDevice>
#include <QSlider>

VolumeDelegate::VolumeDelegate(QObject *parent) : QStyledItemDelegate(parent)
{

}

QWidget* VolumeDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                      const QModelIndex &index) const
{
    QSlider* editor = new QSlider(parent);
    editor->setOrientation(Qt::Orientation::Horizontal);
    editor->setGeometry(option.rect);
    //editor->setAutoFillBackground(true);

    editor->setMinimum(0);
    editor->setMaximum(100);
    editor->setValue(index.data().toFloat() * 100);

    return editor;
}

void VolumeDelegate::paint(QPainter *painter,
                         const QStyleOptionViewItem &option,
                         const QModelIndex &index) const
{
    QSlider slider;
    //slider.setAutoFillBackground(false);
    slider.setOrientation(Qt::Orientation::Horizontal);
    slider.setMinimum(0);
    slider.setMaximum(100);

    slider.setValue(index.model()->data(index, Qt::DisplayRole).toFloat() * 100);
    slider.setGeometry(option.rect);

    QRect ourRect = option.rect;

    ourRect.setTopLeft(ourRect.topLeft() - painter->clipBoundingRect().topLeft().toPoint());
    slider.render(painter, ourRect.topLeft());

    /*
    QStyleOptionSlider sliderOption;
    sliderOption.rect = option.rect;
    sliderOption.state = option.state | QStyle::State_Enabled;
    QApplication::style()->drawComplexControl(QStyle::CC_Slider, &sliderOption, painter, &slider);
    */
}

void VolumeDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = (index.model()->data(index, Qt::EditRole).toFloat() * 100);

    QSlider* slider = static_cast<QSlider*>(editor);
    slider->setValue(value);
}

void VolumeDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                  const QModelIndex &index) const
{
    QSlider* slider = static_cast<QSlider*>(editor);
    float value = (slider->value()/100.0);

    model->setData(index, value, Qt::EditRole);
}

QSize VolumeDelegate::sizeHint(const QStyleOptionViewItem &option,
               const QModelIndex &/*index*/) const
{
    return QSize(option.rect.width(), option.rect.height());
}

void VolumeDelegate::commitAndCloseEditor()
{

}

void VolumeDelegate::updateEditorGeometry(QWidget *editor,
                                          const QStyleOptionViewItem &option,
                                          const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}
