#include <gamesound.h>
GameSound::GameSound(){
    game_music.loadFromFile("game_music.ogg");
    game_sound.setBuffer(game_music);
    game_sound.setLoop(true);

    bullet_music.loadFromFile("bullet.ogg");
    bullet_sound.setBuffer(bullet_music);

    over_music.loadFromFile("game_over.ogg");
    game_over.setBuffer(over_music);

    enemy1_down.loadFromFile("enemy1_down.ogg");
    enemy2_down.loadFromFile("enemy2_down.ogg");
    enemy3_down.loadFromFile("enemy3_down.ogg");
}

GameSound::~GameSound(){}

bool GameSound::changeSound(){}

void GameSound::addSound(int mark){
    if(mark==1){
        bullet_sound.play();
    }
    if(mark==2){
        enemy_down.setBuffer(enemy1_down);
        enemy_down.play();
    }
    if(mark==3){
        enemy_down.setBuffer(enemy2_down);
        enemy_down.play();
    }
    if(mark==4){
        enemy_down.setBuffer(enemy3_down);
        enemy_down.play();
    }
}

void GameSound::soundPlay(){
   // if(game_sound)
    game_sound.play();
}

void GameSound::soundPause(){
    game_sound.pause();
}

