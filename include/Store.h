#ifndef ENEMY_STORE_H_INCLUDED
#define ENEMY_STORE_H_INCLUDED

#include "enemy.h"
#include "bullet.h"
#include "gamesound.h"
#include "backGround.h"
typedef struct B_Node{
    Bullet * bullet;
    struct B_Node * link;
}B_Node;
typedef struct E_Node{
    Enemy * enemy;
    struct E_Node * link;
}E_Node;
class Store
{
private:
    GameSound& sound;
    BackGround& background;
public:
    Store(GameSound& sound,BackGround& background);
    ~Store();
    B_Node * head_b;
    E_Node * head_e;
    bool isEmpty(int flag);
    int Length();
    void append_enemy(int type,int rate,int speed,sf::Vector2f x_y,sf::Vector2f _size,sf::Vector2f bullet_adjust);
    void append_bullet(sf::Vector2f bullet_x_y,int bullet_mark,int speed);
    void get_for_each_enemy(sf::Vector2f enemy1_x_y[],sf::Vector2f enemy2_x_y[],int enemy1_death[],int enemy2_death[],int & i,int & j);
    void get_for_each_bullet(sf::Vector2f hero_x_y[],sf::Vector2f enemy_x_y[],int & i,int & j);
    void enemy_move();
    void enemy_launch(Enemy & enemy);
    void bullet_move();
    bool bullet_hit(int mark,sf::Sprite bullet);
    void disappear(E_Node * p);
    void disappear(B_Node * p);
};

#endif // ENEMY_STORE_H_INCLUDED
