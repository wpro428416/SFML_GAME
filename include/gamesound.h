#ifndef SOUND_H_INCLUDED
#define SOUND_H_INCLUDED

#include <SFML/Audio.hpp>
class GameSound
{
private:
    sf::SoundBuffer game_music;
    sf::SoundBuffer bullet_music;
    sf::SoundBuffer over_music;
    sf::Sound bullet_sound;
    sf::Sound game_sound;
    sf::Sound game_over;

    sf::SoundBuffer enemy1_down;
    sf::SoundBuffer enemy2_down;
    sf::SoundBuffer enemy3_down;
    sf::Sound enemy_down;
public:
    GameSound();
    ~GameSound();
    void addSound(int mark);
    bool changeSound();
    void soundPlay();
    void soundPause();
};


#endif // SOUND_H_INCLUDED
