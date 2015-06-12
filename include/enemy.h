#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "plane.h"
class Enemy:public Plane
{
private:
    sf::Texture enemy1;
    sf::Texture enemy1_down1;
    sf::Texture enemy1_down2;
    sf::Texture enemy1_down3;
    sf::Texture enemy1_down4;

    sf::Texture enemy2;

public:
    Enemy(int rate,int speed,sf::Vector2f x_y,sf::Vector2f _size,sf::Vector2f bullet_adjust,int type);//1Ϊenemy1,2Ϊenemy2,3Ϊenemy3
    ~Enemy();
    bool moveUp();
    bool moveDown();
    void hit_test();
    void launch();
    bool dead();

    int type;
    sf::Vector2f bullet2_adjust;
};


#endif // ENEMY_H_INCLUDED
