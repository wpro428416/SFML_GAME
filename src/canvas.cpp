#include "canvas.h"


#include <iostream>
using namespace std;
Canvas::Canvas(sf::RenderWindow &window,Ctrl & ctrl):window(window),ctrl(ctrl)
{

    tag=0;
    pause=true;
    ////////////≥ı º‘§…Ë////////////////////////

    bullet1.loadFromFile("bullet1.png");
    bullet2.loadFromFile("bullet2.png");

    enemy1.loadFromFile("enemy1.png");
    enemy1_down1.loadFromFile("enemy1_down1.png");
    enemy1_down2.loadFromFile("enemy1_down2.png");
    enemy1_down3.loadFromFile("enemy1_down3.png");
    enemy1_down4.loadFromFile("enemy1_down4.png");

    enemy2.loadFromFile("enemy2.png");
    enemy2_hit.loadFromFile("enemy2_hit.png");
    enemy2_down1.loadFromFile("enemy2_down1.png");
    enemy2_down2.loadFromFile("enemy2_down2.png");
    enemy2_down3.loadFromFile("enemy2_down3.png");
    enemy2_down4.loadFromFile("enemy2_down4.png");

    hero1.loadFromFile("hero1.png");
    hero2.loadFromFile("hero2.png");
    hero_blowup_n1.loadFromFile("hero_blowup_n1.png");
    hero_blowup_n2.loadFromFile("hero_blowup_n2.png");
    hero_blowup_n3.loadFromFile("hero_blowup_n3.png");
    hero_blowup_n4.loadFromFile("hero_blowup_n4.png");
//************************///////////////
    for(int k=0;k<30;k++){
       hero_x_y[k].x=0;
       enemy_x_y[k].x=0;
       hero_x_y[k].y=0;
       enemy_x_y[k].y=0;
       hero_bullet[k].setTexture(bullet1);
       enemy_bullet[k].setTexture(bullet2);
    }
    for(int k=0;k<30;k++){
       enemy1_x_y[k].x=0;
       enemy2_x_y[k].x=0;
       enemy1_x_y[k].y=0;
       enemy2_x_y[k].y=0;
       enemy1_sprite[k].setTexture(enemy1);
       enemy2_sprite[k].setTexture(enemy2);
       enemy1_death[k]=0;
       enemy2_death[k]=0;
    }
}

Canvas::~Canvas(){}

void Canvas::bullet_draw(){
    ctrl.store->get_for_each_bullet(hero_x_y,enemy_x_y,bullet_i,bullet_j);
    for(int k=0;k<bullet_i;k++){
        hero_bullet[k].setPosition(hero_x_y[k]);
        window.draw(hero_bullet[k]);
    }
    for(int k=0;k<bullet_j;k++){
        enemy_bullet[k].setPosition(enemy_x_y[k]);
        window.draw(enemy_bullet[k]);
    }
}

void Canvas::enemy_draw(){
    ctrl.store->get_for_each_enemy(enemy1_x_y,enemy2_x_y,enemy1_death,enemy2_death,enemy_i,enemy_j);
    for(int k=0;k<enemy_i;k++){
        if(enemy1_death[k]==1){
            enemy1_sprite[k].setTexture(enemy1_down1);
        }
        if(enemy1_death[k]==2){
            enemy1_sprite[k].setTexture(enemy1_down2);
        }
        if(enemy1_death[k]==3){
            enemy1_sprite[k].setTexture(enemy1_down3);
        }
        if(enemy1_death[k]==4){
            enemy1_sprite[k].setTexture(enemy1_down4);
        }
        if(enemy1_death[k]==0){
            enemy1_sprite[k].setTexture(enemy1);
        }
        enemy1_sprite[k].setPosition(enemy1_x_y[k]);
        window.draw(enemy1_sprite[k]);
    }
    for(int k=0;k<enemy_j;k++){
        if(enemy2_death[k]==1){
            enemy2_sprite[k].setTexture(enemy2_down1);
        }
        if(enemy2_death[k]==2){
            enemy2_sprite[k].setTexture(enemy2_down2);
        }
        if(enemy2_death[k]==3){
            enemy2_sprite[k].setTexture(enemy2_down3);
        }
        if(enemy2_death[k]==4){
            enemy2_sprite[k].setTexture(enemy2_down4);
        }
        if(enemy2_death[k]==0){
            enemy2_sprite[k].setTexture(enemy2);
        }
        enemy2_sprite[k].setPosition(enemy2_x_y[k]);
        window.draw(enemy2_sprite[k]);
    }
}

void Canvas::draw(){
    window.clear();
    if(tag<160){
        window.draw(ctrl.background.mainplay());
        window.draw(ctrl.background.load());
        tag++;
    }
    else{
        if(ctrl.hero->life>0){
                if(pause){
                    window.draw(ctrl.background.mainplay());
                    window.draw(ctrl.background.textplay());
                    window.draw(ctrl.background.bloodplay());
                    window.draw(ctrl.background.pause_resume(1));

                    enemy_draw();
                    bullet_draw();
                    window.draw(ctrl.hero->plane);
                }
                else{
                    window.draw(ctrl.background.mainplay());
                }

        }
        else{
            window.draw(ctrl.background.mainplay());
            window.draw(ctrl.background.over());
            ctrl.background.changeScore(3);
            window.draw(ctrl.background.textplay());
        }
    }
    window.display();
}


