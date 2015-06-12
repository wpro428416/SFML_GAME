#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <SFML/Graphics.hpp>
typedef struct Node{
    sf::Vector2f bullet_x_y;
    sf::Sprite bullet;//
    int bullet_mark;
    int speed;
    struct Node * link;
}Node;


    class Bullet_store
{
private:
    void moveUp();
    void moveDown();
    void bullet_move();
    sf::Texture bullet1;//
    sf::Texture bullet2;//
public:
    Node * first;
    void get_for_each(sf::Vector2f hero_x_y[],sf::Vector2f enemy_x_y[],int & i,int & j);
    Bullet_store();
    ~Bullet_store();
    bool isEmpty();
    int Length();
    void append(sf::Vector2f bullet_x_y,int bullet_mark,int speed);
    void disappear(Node * p);
};


#endif // QUEUE_H_INCLUDED
