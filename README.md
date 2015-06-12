## “飞机大战”实验报告 ##

**作者信息** 王炜 （2014060102022）

### **规定完成的任务** ###

----------
•	任务：（规定动作，2周4次课完成，剩余2周自选动作）  
◦	完成SFML配置，显示“SFML works”  
◦	显示一架静止的飞机于屏幕底部  
◦	背景音乐  
◦	左右键，控制移动飞机  
◦	限制左右边界  
◦	空格键开炮，显示运动的炮弹  
◦	炮弹飞出边界处理  
◦	随机产生敌机，并向下运动
◦	敌机飞出边界处理  
◦	碰撞处理（敌机与炮弹碰撞）  
◦	显示敌机爆炸过程  
◦	爆炸声音  
◦	计分及显示  
◦	敌机炮弹处理  
◦	被敌机击中处理（炸毁、3条命）  
◦	过关控制（过关需要计分、游戏速度控制）




### 额外添加的任务 ###

----------
无



### 完成情况 ###

----------
完成SFML配置，显示“SFML works”  
◦	显示一架静止的飞机于屏幕底部  
◦	背景音乐  
◦	左右键，控制移动飞机  
◦	限制左右边界  
◦	空格键开炮，显示运动的炮弹  
◦	炮弹飞出边界处理  
◦	随机产生敌机，并向下运动
◦	敌机飞出边界处理  
◦	碰撞处理（敌机与炮弹碰撞）  
◦	显示敌机爆炸过程  
◦	爆炸声音  
◦	计分及显示  
◦	敌机炮弹处理  
◦	被敌机击中处理（炸毁、3条命）

Main代码：
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
`

游戏截图：

----------


!![](http://pica.nipic.com/2007-11-09/2007119124513598_2.jpg)
### 评价 ###

啦啦啦啦。。终于可以不用做啦。。功能差不多就好。。不可以玩就算了。。