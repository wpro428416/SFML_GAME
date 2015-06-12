#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

#include <SFML/Graphics.hpp>
class BackGround
{
private:
    int score;
    int i;
    char temp[30];

    sf::Texture main;
    sf::Texture copyright;
    sf::Sprite mainSprite;


    sf::Texture game_pause_pressed;
    sf::Texture game_pause_nor;
    sf::Texture game_resume_nor;
    sf::Texture game_resume_pressed;
    sf::Sprite game_pauseSprite;
    sf::Sprite game_resumeSprite;

    sf::Texture gameover;
    sf::Sprite gameoverSprite;

    sf::Texture heart3;
    sf::Texture heart2;
    sf::Texture heart1;
    sf::Sprite bloodSprite;

    sf::Font font;
    sf::Text scoreText;

    sf::Texture game_loading1;
    sf::Texture game_loading2;
    sf::Texture game_loading3;
    sf::Texture game_loading4;
    sf::Sprite load_game;
public:
    BackGround();
    ~BackGround();
    sf::Sprite load();
    sf::Sprite over();
    void changeBlood(int life);
    void changeScore(int mark);
    bool changePicture();
    sf::Sprite mainplay();
    sf::Sprite bloodplay();
    sf::Text textplay();
    sf::Sprite pause_resume(int mark);
};


#endif // BACKGROUND_H_INCLUDED
