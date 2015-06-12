#ifndef PLANE_H_INCLUDED
#define PLANE_H_INCLUDED


#include <SFML/Graphics.hpp>
class Plane
{
protected:
    int rate;   //launch_rate
    int speed;

    sf::Vector2f _size;
public:
    int death;  //death_range
    sf::Sprite plane;
    sf::Vector2f x_y;

    Plane(int rate,int speed,sf::Vector2f x_y,sf::Vector2f _size);
    ~Plane();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void launch();
    void hit_test();
    void dead();
};

#endif // PLANE_H_INCLUDED
