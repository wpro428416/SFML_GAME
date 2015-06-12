#include "control.h"

#include <iostream>
using namespace std;
Ctrl::Ctrl(BackGround& background,GameSound& sound):background(background),sound(sound)
{
    ini();
    store=new Store(sound,background);
    hero=new Hero(5,15,hero_pos,hero_size,bullet1_adjust,*store,sound);
    enemy_rate=0;
    hero_safe_time=0;
}

Ctrl::~Ctrl(){

}

void Ctrl::ini(){
    bullet1.loadFromFile("bullet1.png");
    bullet2.loadFromFile("bullet2.png");
    hero1.loadFromFile("hero1.png");
    hero2.loadFromFile("hero2.png");
    enemy1.loadFromFile("enemy1.png");
    enemy2.loadFromFile("enemy2.png");

    hero_size=(sf::Vector2f)hero1.getSize();
    bullet1_size=(sf::Vector2f)bullet1.getSize();
    bullet2_size=(sf::Vector2f)bullet2.getSize();
    enemy1_size=(sf::Vector2f)enemy1.getSize();
    enemy2_size=(sf::Vector2f)enemy2.getSize();

    hero_pos.x=(450-hero_size.x)/2;
    hero_pos.y=650-hero_size.y;

    bullet1_adjust.x=(hero_size.x-bullet1_size.x)/2;
    bullet1_adjust.y=-bullet1_size.y;
    bullet2_adjust.x=(enemy1_size.x-bullet2_size.x)/2;
    bullet2_adjust.y=enemy1_size.y;
    bullet3_adjust.x=(enemy2_size.x-bullet2_size.x)/2;
    bullet3_adjust.y=enemy2_size.y;
}

void Ctrl::hero_move(int dir){
    switch (dir){
        case 1:hero->moveUp();break;
        case 2:hero->moveDown();break;
        case 3:hero->moveLeft();break;
        case 4:hero->moveRight();break;
        default:break;
    }
}

void Ctrl::hero_launch(){
    hero->launch();
}

void Ctrl::enemy_out(){
    while(++enemy_rate%80==0){
        sf::Vector2f x_y;
        srand(time(0)*time(0));
        x_y.x=rand()%300;
        x_y.y=0;

        store->append_enemy(1,200,6,x_y,enemy1_size,bullet2_adjust);
    }
    while(++enemy_rate%240==0){
        sf::Vector2f x_y;
        srand(time(0)*time(0)*time(0));
        x_y.x=rand()%300;
        x_y.y=0;

        store->append_enemy(2,200,4,x_y,enemy2_size,bullet3_adjust);
    }
}

void Ctrl::hero_hit_test(){
    E_Node * h_e=store->head_e;
    while(h_e->link!=NULL){
        if(check(hero->plane,h_e->link->enemy->plane)){
            h_e->link->enemy->death++;
            hero->death++;
            if(h_e->link->enemy->type==1){
                sound.addSound(2);
            }
            if(h_e->link->enemy->type==2){
                sound.addSound(3);
            }
        }
        h_e=h_e->link;
    }

    B_Node * h_b=store->head_b;
    while(h_b->link!=NULL&&h_b->link->bullet->bullet_mark==2){
           if(check(hero->plane,h_b->link->bullet->bullet)){
                store->disappear(h_b);
                    hero->death++;
                    continue;
            }
        h_b=h_b->link;
    }

    if(hero->dead()){
            hero->x_y=hero_pos;
            background.changeBlood(hero->life);
            hero_safe_time=0;
    }

}
