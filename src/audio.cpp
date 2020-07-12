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

#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QStandardPaths>

ImpAudio::ImpAudio(QObject *parent) : QObject(parent)
{
}

bool ImpAudio::cacheEffect(const QString& fileName)
{
    if(!buffers.contains(fileName))
    {
        QString fullPath = appFilesPath() + "/audio/" + fileName;

        qDebug() << "   Sound not in buffer, caching" << fullPath;

        if(!buffers[fileName].loadFromFile(fullPath.toStdString()))
            return false;
    }

    return true;
}

QVector<sf::Sound>::iterator ImpAudio::allocateSound(const QString& fileName)
{
    QVector<sf::Sound>::iterator i = sounds.end();
    if(sounds.count() > 0)
    {
        for(i = sounds.begin(); i < sounds.end(); i++)
        {
            // Reuse a sound if a previous one is free
            if((*i).getStatus() != sf::Sound::Playing)
            {
                qDebug() << "   Reusing existing sf::Sound.";
                (*i).setBuffer(buffers[fileName]);
                break;
            }
        }
    }

    if(i == sounds.end())
    {
        // No free sound in the set, add a new one.
        qDebug() << "   Adding new sound to set.";
        sounds.append(sf::Sound(buffers[fileName]));

        // Reinitialize iterator to point to last item in set.
        i = sounds.end();
        --i;
    }

    return i;
}

void ImpAudio::changeAudio(AudioEngine ae)
{
    engine = ae;
    qDebug() << "ImpAudio::changeAudio(" << ae << ")";
}

AudioEngine ImpAudio::getEngine()
{
    return engine;
}

void ImpAudio::playLocalFile(const QString& fileName, float volume)
{
    switch(engine)
    {
    case AudioEngine::AE_Qt:
        playLocalFileQt(fileName, volume);
        break;
    default:    // case AudioEngine::AE_SFML:
        playLocalFileSFML(fileName, volume);
    }
}

void ImpAudio::playLocalFileSFML(const QString& fileName, float volume)
{
    qDebug() << "ImpAudio::playLocalFileSFML(" << fileName << "," << volume << ")";
    if(!cacheEffect(fileName))
    {
        qDebug() << "   Caching failed for " << fileName;
        return;
    }

    qDebug() << "   Setting buffer and playing.";
    QVector<sf::Sound>::iterator i = allocateSound(fileName);
    (*i).setVolume(volume * 100);
    (*i).play();
}


void ImpAudio::playLocalFileQt(const QString& fileName, float volume)
{
    qDebug() << "ImpAudio::playLocalFileQt(" << fileName << "," << volume << ")";
    if(!effects.contains(fileName))
    {
        QString path = appFilesPath() + "/audio/" + fileName;
        QSoundEffect* effect = new QSoundEffect(this);
        effect->setSource(QUrl::fromLocalFile(path));
        effects.insert(fileName, effect);
    }

    effects[fileName]->setVolume(static_cast<qreal>(volume));
    effects[fileName]->play();
}

void ImpAudio::playLocalMedia(const QString& fileName, float volume)
{
    QString path = appFilesPath() + "/audio/" + fileName;

    qDebug() << "Playing " << path;

    switch(engine) {
        case AudioEngine::AE_Qt:
            player = new QMediaPlayer;
            player->setMedia(QUrl::fromLocalFile(path));
            player->setVolume(50);
            player->play();
            break;

        default:
            if (!music.openFromFile(path.toStdString()))
                return; // error

            music.setVolume(volume*100);
            music.play();
            break;
    }
}

void ImpAudio::stopMusic()
{
    switch(engine) {
        case AudioEngine::AE_Qt:
            if(player != NULL && player->state() == player->PlayingState)
            {
                player->stop();
            }
        break;

        case AudioEngine::AE_SFML:
            music.stop();
        break;
    }
}
