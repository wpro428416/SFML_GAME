#include "bullet.h"

Bullet::Bullet(int speed,sf::Vector2f bullet_x_y,int bullet_mark):speed(speed),bullet_x_y(bullet_x_y),bullet_mark(bullet_mark){
    bullet1.loadFromFile("bullet1.png");
    bullet2.loadFromFile("bullet2.png");
    if(bullet_mark==1){
        bullet.setTexture(bullet1);
    }
    if(bullet_mark==2){
      bullet.setTexture(bullet2);
    }
    bullet.setPosition(bullet_x_y);
}

Bullet::~Bullet(){

}

bool Bullet::moveUp(){
    if(bullet_x_y.y>-10){
        bullet_x_y.y-=speed/2;
        bullet.setPosition(bullet_x_y);
        return true;
    }
    return false;
}

bool Bullet::moveDown(){
    if(bullet_x_y.y<620){
        bullet_x_y.y+=speed/2;
        bullet.setPosition(bullet_x_y);
        return true;
    }
    return false;
}
