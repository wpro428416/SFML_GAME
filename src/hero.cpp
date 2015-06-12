#include "hero.h"

#ifndef heroMark
#define heroMark 1
#endif

Hero::Hero(int rate,int speed,sf::Vector2f x_y,sf::Vector2f _size,sf::Vector2f bullet1_adjust,Store & store,GameSound& sound):Plane(rate,speed,x_y,_size),bullet1_adjust(bullet1_adjust),store(store),sound(sound)
{
    hero1.loadFromFile("hero1.png");
    hero_blowup_n1.loadFromFile("hero_blowup_n1.png");
    hero_blowup_n2.loadFromFile("hero_blowup_n2.png");
    hero_blowup_n3.loadFromFile("hero_blowup_n3.png");
    hero_blowup_n4.loadFromFile("hero_blowup_n4.png");

    plane.setTexture(hero1);
    plane.setPosition(x_y);
}

Hero::~Hero(){}



void Hero::launch(){
    if(rate++%5==0){
        store.append_bullet(x_y+bullet1_adjust,1,30);
        sound.addSound(1);
    }
}

bool Hero::dead(){
    if(death==1){
        death++;
        plane.setTexture(hero_blowup_n1);
        return false;
    }
    if(death==2){
        death++;
        plane.setTexture(hero_blowup_n2);
        return false;
    }
    if(death==3){
        death++;
        plane.setTexture(hero_blowup_n3);
        return false;
    }
    if(death==4){
        death++;
        plane.setTexture(hero_blowup_n4);
        return false;
    }
    if(death>4){
        plane.setTexture(hero1);
        death=0;
        life--;
        return true;
    }
    return false;

}

void Hero::hit_test(){
}


int Hero::life=3;
