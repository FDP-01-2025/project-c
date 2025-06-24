#pragma once
#include <iostream>
#include "Enemy.h"
using namespace std;


//Player struct
struct Player
{
    int life = 3;
    int lifeMax = 3;
    int damage = 1;
    int items = 0;

    //Player functions 
    void getDamage(const Enemy& enemy){
        life -= enemy.attack();
    }

    void useItem(){
        if (items != 0)
        {
            life++;
            if (life > lifeMax) life = lifeMax;        
            items--;
        }
        else cout<<"You haven't items to use"<<endl;
    }

    void addItem(){
        items++;
    }

    void increaseAttack() {
        damage++;
    }

    int attack() const{
        return damage;
    }

    bool alive() const{
        return life > 0;
    }
};