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

#include "audio.h"
#include "abstract_os.h"

//#include <QAudio>
#include <QCoreApplication>
#include <QDebug>
#include <QStandardPaths>

ImpAudio::ImpAudio(QObject *parent) : QObject(parent)
{
}

QSoundEffect* ImpAudio::playLocalFile(const QString& fileName)
{
    QString path = appFilesPath() + "/audio/" + fileName;

    qDebug() << "Playing " << path;


    QSoundEffect* effect = new QSoundEffect(this);
    effect->setSource(QUrl::fromLocalFile(path));

    qDebug() << "Setting volume on effect to " << QString::number(volume, 'g', 2);
    effect->setVolume(volume);
    effect->play();

    connect(effect, SIGNAL(playingChanged()), this, SLOT(playingChanged()));

    return effect;
}

void ImpAudio::playingChanged()
{
    QSoundEffect *s = qobject_cast<QSoundEffect *> (sender());
    if (!s->isPlaying())
    {
          s->deleteLater();
    }
}

void ImpAudio::setVolume(int i)
{
    // Docs said Qt supports logarithmic volume scale...
    // but doesn't appear implemented.

/*    volume = QAudio::convertVolume(i / qreal(100.0),
                                   QAudio::LogarithmicVolumeScale,
                                   QAudio::LinearVolumeScale);
*/
    volume = i / qreal(100.0);
    qDebug() << "Volume changed to " << QString::number(volume, 'g', 2);
}

