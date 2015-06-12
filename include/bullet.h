#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include <SFML/Graphics.hpp>
class Bullet
{
private:
    int speed;
    sf::Texture bullet1;//
    sf::Texture bullet2;//
public:
    sf::Sprite bullet;

    Bullet(int speed,sf::Vector2f bullet_x_y,int bullet_mark);
    ~Bullet();
    int bullet_mark;
    sf::Vector2f bullet_x_y;
    bool moveUp();
    bool moveDown();
    void hit();
};

#endif // BULLET_H_INCLUDED
