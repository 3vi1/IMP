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

#ifndef FINDMESSAGESDIALOG_H
#define FINDMESSAGESDIALOG_H

#include <QDialog>

namespace Ui {
class FindMessagesDialog;
}

class FindMessagesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindMessagesDialog(QWidget *parent = 0);
    ~FindMessagesDialog();

    QString input();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::FindMessagesDialog *ui;
};

#endif // FINDMESSAGESDIALOG_H
