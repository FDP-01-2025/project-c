#pragma once
#include "Enemy.h"

//Player struct
struct Player
{
    int life = 3;
    int lifeMax = 3;
    int damage = 1;
    int items = 0;

    //Player functions 
    void getDamage(const Enemy& enemy);

    void useItem();

    void addItem();

    void increaseAttack();

    int attack() const;

    bool alive() const;
};