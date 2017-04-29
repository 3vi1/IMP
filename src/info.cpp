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

#include "info.h"
#include "ui_info.h"

#include "meta.h"

Info::Info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Info)
{
    // ToDo:  Figure out why QDialog doesn't draw background at all with
    //        translucency set.

    //setAttribute(Qt::WA_TranslucentBackground);
    //setAttribute(Qt::WA_NoSystemBackground);
    ui->setupUi(this);
    ui->versionInfo->setText(meta.versionInfo);
}

Info::~Info()
{
    delete ui;
}

void Info::on_okayButton_accepted()
{
    hide();
    if(m_audio != NULL)
        m_audio->stopMusic();
}

void Info::reject()
{
    hide();
    if(m_audio != NULL)
        m_audio->stopMusic();
}

void Info::startMusic(ImpAudio *audio)
{
    m_audio = audio;
    audio->playLocalMedia("info/1 dont kn0w.m4a");
}
