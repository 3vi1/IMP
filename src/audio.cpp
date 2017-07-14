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
#include <QDir>
#include <QFileInfo>
#include <QStandardPaths>

ImpAudio::ImpAudio(QObject *parent) : QObject(parent)
{
    cacheSounds();
}

void ImpAudio::cacheSounds()
{
    QString path = appFilesPath() + "/audio/";

    QDir audioDir(path);
    audioDir.setFilter(QDir::Files);

    // Load up style combo
    foreach(QFileInfo fileInfo, audioDir.entryInfoList())
    {
        if(fileInfo.fileName().endsWith(".dll"))
            continue;

        QSoundEffect* effect = new QSoundEffect(this);
        effect->setSource(QUrl::fromLocalFile(fileInfo.absoluteFilePath()));

        if(!effects.contains(fileInfo.fileName()))
            effects.insert(fileInfo.fileName(), effect);
    }
}

void ImpAudio::playLocalFile(const QString& fileName)
{
    if(!effects.contains(fileName))
    {
        QString path = appFilesPath() + "/audio/" + fileName;
        QSoundEffect* effect = new QSoundEffect(this);
        effect->setSource(QUrl::fromLocalFile(path));
        effects.insert(fileName, effect);
    }

    effects[fileName]->setVolume(m_volume);
    effects[fileName]->play();
}

void ImpAudio::playLocalFile(const QString& fileName, float volume)
{
    if(!effects.contains(fileName))
    {
        QString path = appFilesPath() + "/audio/" + fileName;
        QSoundEffect* effect = new QSoundEffect(this);
        effect->setSource(QUrl::fromLocalFile(path));
        effects.insert(fileName, effect);
    }

    effects[fileName]->setVolume(volume);
    effects[fileName]->play();
}

/*
QSoundEffect* ImpAudio::oldPlayLocalFile(const QString& fileName)
{
    QString path = appFilesPath() + "/audio/" + fileName;

    qDebug() << "ImpAudio::playLocalFile - Playing " << path;


    QSoundEffect* effect = new QSoundEffect(this);
    effect->setSource(QUrl::fromLocalFile(path));

    qDebug() << "ImpAudio::playLocalFile - Setting volume on effect to " << QString::number(volume, 'g', 2);
    effect->setVolume(volume);
    connect(effect, &QSoundEffect::playingChanged, this, &ImpAudio::playingChanged);
    effect->play();

    qDebug() << "ImpAudio::playLocalFile - played " << &effect;
    return effect;
}
*/
void ImpAudio::playingChanged()
{
    QSoundEffect *s = qobject_cast<QSoundEffect *> (sender());
    if (!s->isPlaying())
    {
        qDebug() << "ImpAudio::playingChanged - cleaning up " << &s;
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
    m_volume = i / qreal(100.0);
    qDebug() << "Volume changed to " << QString::number(m_volume, 'g', 2);
}

void ImpAudio::playLocalMedia(const QString& fileName)
{
    QString path = appFilesPath() + "/audio/" + fileName;

    qDebug() << "Playing " << path;

    player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile(path));
    player->setVolume(50);
    player->play();
}

void ImpAudio::stopMusic()
{
    if(player != NULL && player->state() == player->PlayingState)
    {
        player->stop();
    }
}
