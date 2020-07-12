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

#ifndef IMPAUDIO_H
#define IMPAUDIO_H

#include <QFile>
#include <QMap>
#include <QObject>
#include <QVector>
#include <QMediaPlayer>     // Qt engine
#include <QSoundEffect>     // Qt engine
#include <SFML/Audio.hpp>   // SFML engine

enum AudioEngine { AE_SFML, AE_Qt };
Q_DECLARE_METATYPE(AudioEngine)

class ImpAudio : public QObject
{
    Q_OBJECT
public:
    explicit ImpAudio(QObject *parent = 0);

    AudioEngine getEngine();

    void playLocalMedia(const QString& fileName, float volume = 1.0);
    void stopMusic();

    void setVolume(int i);

signals:

public slots:
    void playLocalFile(const QString& fileName, float volume = 1.0);
    void changeAudio(AudioEngine);

private:
    void playLocalFileSFML(const QString& fileName, float volume);
    void playLocalFileQt(const QString& fileName, float volume);

    QVector<sf::Sound>::iterator allocateSound(const QString& fileName);
    bool cacheEffect(const QString& fileName);

    AudioEngine engine = AudioEngine::AE_SFML;
    qreal m_volume = static_cast<qreal>(1.0f);

    QMediaPlayer* player;
    QMap<QString, QSoundEffect*> effects;

    // SFML sound structures
    QMap<QString, sf::SoundBuffer> buffers;
    QVector<sf::Sound> sounds;

    sf::Music music;
};

#endif // AUDIO_H
