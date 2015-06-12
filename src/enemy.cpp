#include <enemy.h>


Enemy::Enemy(int rate,int speed,sf::Vector2f x_y,sf::Vector2f _size,sf::Vector2f bullet_adjust,int type):Plane(rate,speed,x_y,_size),bullet2_adjust(bullet_adjust),type(type)
{
    enemy1.loadFromFile("enemy1.png");
    enemy1_down1.loadFromFile("enemy1_down1.png");
    enemy1_down2.loadFromFile("enemy1_down2.png");
    enemy1_down3.loadFromFile("enemy1_down3.png");
    enemy1_down4.loadFromFile("enemy1_down4.png");

    enemy2.loadFromFile("enemy2.png");
    if(type==1){
        plane.setTexture(enemy1);
    }
    if(type==2){
        plane.setTexture(enemy2);
    }
    plane.setPosition(x_y);
}

Enemy::~Enemy(){}

bool Enemy::moveUp(){
    if(x_y.y>10){
        x_y.y-=speed;
        plane.setPosition(x_y);
        return true;
    }
    return false;
}

bool Enemy::moveDown(){
    if(x_y.y<800){
        if(dead()){
            x_y.y+=speed;
            plane.setPosition(x_y);
            return true;
        }
    }
    return false;
}

void Enemy::launch(){
    if(rate++%200==0){

    }
}

bool Enemy::dead(){
    if(death==0){
        return true;
    }
    if(death==1){
        death++;
        return true;
    }
    if(death==2){
        death++;
        return true;
    }
    if(death==3){
        death++;
        return true;
    }
    if(death==4){
        death++;
        return true;
    }
    if(death>4){
        return false;
    }
}

void Enemy::hit_test(){

}



