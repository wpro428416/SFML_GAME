#ifndef CONTROL_H_INCLUDED
#define CONTROL_H_INCLUDED

#include "backGround.h"
#include "gamesound.h"
#include "hero.h"
#include "Store.h"
#include "heatTest.h"
class Ctrl
{
private:
    sf::Texture hero1;
    sf::Texture hero2;
    sf::Texture bullet1;
    sf::Texture bullet2;
    sf::Texture enemy1;
    sf::Texture enemy2;

    sf::Vector2f hero_size;
    sf::Vector2f enemy1_size;
    sf::Vector2f enemy2_size;
    sf::Vector2f enemy3_size;
    sf::Vector2f bullet1_size;
    sf::Vector2f bullet2_size;

    sf::Vector2f hero_pos;
    sf::Vector2f bullet1_adjust;
    sf::Vector2f bullet2_adjust;
    sf::Vector2f bullet3_adjust;
public:
    Hero * hero;
    int hero_safe_time;
    int enemy_rate;
    Store * store;
    BackGround & background;
    GameSound & sound;

    Ctrl(BackGround& background,GameSound& sound);
    ~Ctrl();
    void ini();
    void hero_move(int dir);
    void hero_launch();
    void enemy_out();
    void hero_hit_test();
};

#endif // CONTROL_H_INCLUDED
