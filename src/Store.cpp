#include "Store.h"
#include <iostream>
using namespace std;
Store::Store(GameSound& sound,BackGround& background):sound(sound),background(background)
{
    head_e=new E_Node;
    head_e->link=NULL;

    head_b=new B_Node;
    head_b->link=NULL;
}

Store::~Store(){
    if(!isEmpty(1)){
    E_Node * p;
    while(head_e->link!=NULL){
        p=head_e->link;
        head_e->link=p->link;
        delete p;
    }
    }
    if(!isEmpty(2)){
    E_Node * p;
    while(head_e->link!=NULL){
        p=head_e->link;
        head_e->link=p->link;
        delete p;
    }
    }
}

bool Store::isEmpty(int flag){
    if(flag==1){
        return (head_e->link==NULL);
    }
    if(flag==2){
        return (head_b->link==NULL);
    }
    return false;
}

void Store::append_enemy(int type,int rate,int speed,sf::Vector2f x_y,sf::Vector2f _size,sf::Vector2f bullet_adjust){
    E_Node *p=new E_Node;
    p->enemy=new Enemy(rate,speed,x_y,_size,bullet_adjust,type);
    p->link=NULL;
    E_Node* q=head_e;
    while(q->link!=NULL){
        q=q->link;
    }
    q->link=p;
    q=q->link;
}

void Store::append_bullet(sf::Vector2f bullet_x_y,int bullet_mark,int speed){

        B_Node *p=new B_Node;
        p->bullet=new Bullet(speed,bullet_x_y,bullet_mark);
        p->link=NULL;
        B_Node* q=head_b;
        while(q->link!=NULL){
            q=q->link;
        }
        q->link=p;
        q=q->link;


}

void Store::get_for_each_enemy(sf::Vector2f x_y_1[],sf::Vector2f x_y_2[],int enemy1_death[],int enemy2_death[],int & i,int & j){
    E_Node * p=head_e->link;
    i=0;
    j=0;


    while(p!=NULL){
        if(p->enemy->type==1){
            enemy1_death[i]=p->enemy->death;
            x_y_1[i++]=p->enemy->x_y;
            enemy_launch(*(p->enemy));
        }
        if(p->enemy->type==2){
            enemy2_death[j]=p->enemy->death;
            x_y_2[j++]=p->enemy->x_y;
            enemy_launch(*(p->enemy));
        }
        p=p->link;
    }
    enemy_move();
}

void Store::get_for_each_bullet(sf::Vector2f hero_x_y[],sf::Vector2f enemy_x_y[],int & i,int & j){
    B_Node * p=head_b->link;
    j=0;
    i=0;

    while(p!=NULL){
        if(p->bullet->bullet_mark==1){
            hero_x_y[i++]=p->bullet->bullet_x_y;
        }
        if(p->bullet->bullet_mark==2){
            enemy_x_y[j++]=p->bullet->bullet_x_y;
        }
        p=p->link;
    }
    bullet_move();
}

void Store::enemy_move(){
    E_Node * p=head_e;
    while(p->link!=NULL){
           if(!p->link->enemy->moveDown()){
                disappear(p);
                    continue;
            }
        p=p->link;
    }
}

void Store::enemy_launch(Enemy & enemy){
    if(enemy.type==1){
       if((int)enemy.x_y.y%85==0){
       append_bullet(enemy.x_y+enemy.bullet2_adjust,2,15);
    }
    }

    if(enemy.type==2){
       if((int)enemy.x_y.y%75==0){
            sf::Vector2f temp;
            temp.x=30;
            temp.y=0;
            append_bullet(enemy.x_y+enemy.bullet2_adjust+temp,2,15);
            append_bullet(enemy.x_y+enemy.bullet2_adjust,2,15);
            append_bullet(enemy.x_y+enemy.bullet2_adjust-temp,2,15);
    }
    }

}

void Store::bullet_move(){
    B_Node * p=head_b;
     while(p->link!=NULL){
        if(p->link->bullet->bullet_mark==1){
            if(!p->link->bullet->moveUp()||bullet_hit(1,p->link->bullet->bullet)){
               disappear(p);
                    continue;

            }
        }
        if(p->link->bullet->bullet_mark==2){
            if(!p->link->bullet->moveDown()){
               disappear(p);
                    continue;

            }
        }
        p=p->link;
    }
}

bool Store::bullet_hit(int mark,sf::Sprite bullet){
    if(mark==1){
        E_Node * p=head_e;
    while(p->link!=NULL){
           if(p->link->enemy->plane.getGlobalBounds().intersects(bullet.getGlobalBounds())){
                p->link->enemy->death++;
                background.changeScore(p->link->enemy->type);
                if(p->link->enemy->type==1){
                    sound.addSound(2);
                }
                if(p->link->enemy->type==2){
                    sound.addSound(3);
                }
                return true;
           }
        p=p->link;
    }
    }
    return false;
}

void Store::disappear(E_Node * p){
        E_Node * q = p->link;
        p->link=q->link;
        delete q;
}

void Store::disappear(B_Node * p){
    B_Node * q = p->link;
    p->link=q->link;
    delete q;
}
