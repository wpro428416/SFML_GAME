#ifndef MYPLANE_H_INCLUDED
#define MYPLANE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "plane.h"
#include "heatTest.h"
#include "store.h"
#include "gamesound.h"
class Hero:public Plane
{
private:
    sf::Texture hero1;
    sf::Texture hero2;
    sf::Texture hero_blowup_n1;
    sf::Texture hero_blowup_n2;
    sf::Texture hero_blowup_n3;
    sf::Texture hero_blowup_n4;
    sf::Vector2f bullet1_adjust;
    Store & store;
    GameSound & sound;
public:
    static int life;
    Hero(int rate,int speed,sf::Vector2f x_y,sf::Vector2f _size,sf::Vector2f bullet1_adjust,Store & store,GameSound& sound);
    ~Hero();
    void hit_test();
    void launch();
    bool dead();
};


#endif // MYPLANE_H_INCLUDED
