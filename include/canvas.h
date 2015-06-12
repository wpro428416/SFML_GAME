#ifndef CANVAS_H_INCLUDED
#define CANVAS_H_INCLUDED

#include "control.h"
#include "heatTest.h"
#include <SFML/Graphics.hpp>


class Canvas
{
private:
    int tag;


    sf::RenderWindow & window;
    Ctrl & ctrl;

    sf::Vector2f hero_x_y[30];
    sf::Vector2f enemy_x_y[30];
    sf::Sprite hero_bullet[30];
    sf::Sprite enemy_bullet[30];
    int bullet_i;
    int bullet_j;

    sf::Vector2f enemy1_x_y[30];
    sf::Vector2f enemy2_x_y[30];
    sf::Sprite enemy1_sprite[30];
    sf::Sprite enemy2_sprite[30];
    int enemy1_death[30];
    int enemy2_death[30];

    int enemy_i;
    int enemy_j;

    sf::Texture bullet1;
    sf::Texture bullet2;

    sf::Texture enemy1;
    sf::Texture enemy1_down1;
    sf::Texture enemy1_down2;
    sf::Texture enemy1_down3;
    sf::Texture enemy1_down4;

    sf::Texture enemy2;
    sf::Texture enemy2_hit;
    sf::Texture enemy2_down1;
    sf::Texture enemy2_down2;
    sf::Texture enemy2_down3;
    sf::Texture enemy2_down4;

    sf::Texture hero1;
    sf::Texture hero2;
    sf::Texture hero_blowup_n1;
    sf::Texture hero_blowup_n2;
    sf::Texture hero_blowup_n3;
    sf::Texture hero_blowup_n4;
public:
    bool pause;
    Canvas(sf::RenderWindow & window,Ctrl & ctrl);
    ~Canvas();
    void bullet_draw();
    void enemy_draw();
    void draw();
};


#endif // CANVAS_H_INCLUDED
