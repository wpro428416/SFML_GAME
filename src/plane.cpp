#include "plane.h"

Plane::Plane(int rate,int speed,sf::Vector2f x_y,sf::Vector2f _size):rate(rate),speed(speed),x_y(x_y),_size(_size)
{
    plane.setPosition(x_y);
    death=0;
}

Plane::~Plane(){}

void Plane::moveUp(){
    if(x_y.y>10){
        x_y.y-=speed;
        plane.setPosition(x_y);
    }
}

void Plane::moveDown(){
    if(x_y.y<650-_size.y){
        x_y.y+=speed;
        plane.setPosition(x_y);
    }
}

void Plane::moveLeft(){
    if(x_y.x>0){
    x_y.x-=speed;
    plane.setPosition(x_y);
    }
}

void Plane::moveRight(){
    if(x_y.x<450-_size.x){
    x_y.x+=speed;
    plane.setPosition(x_y);
    }
}

void Plane::launch(){

}

void Plane::dead(){

}

void Plane::hit_test(){

}

