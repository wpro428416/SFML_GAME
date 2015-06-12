#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "backGround.h"
#include "gameSound.h"

#include "Canvas.h"
#include "control.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(450,650),"PLA");
    window.setFramerateLimit(60);

    //设置背景
    BackGround background;
    //设置音乐
    GameSound sound;
    sound.soundPlay();
    //控制台
    Ctrl ctrl(background,sound);

    Canvas can(window,ctrl);
    //设置主循环
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type==sf::Event::Closed)
                window.close();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            if(can.pause){
                can.pause=false;
            }
            else{
                can.pause=true;
            }

        }
        if(event.type==sf::Event::LostFocus){
            can.pause=false;
        }
        if(event.type==sf::Event::GainedFocus){
            can.pause=true;
        }
        if(can.pause){
           if(event.type==sf::Event::KeyPressed&&sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                ctrl.hero_move(1);
            }
            if(event.type==sf::Event::KeyPressed&&sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                ctrl.hero_move(2);
            }
            if(event.type==sf::Event::KeyPressed&&sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                ctrl.hero_move(3);
            }
            if(event.type==sf::Event::KeyPressed&&sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                ctrl.hero_move(4);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                ctrl.hero_launch();
            }
            ctrl.enemy_out();
            if(ctrl.hero_safe_time++>100){
                ctrl.hero_hit_test();
            }

        }
        can.draw();
    }


    return 0;
}
