#pragma once
#include <iostream>
#include "Utilities.h"
#include "EnemiesMecanic.h"
using namespace std;

struct Player;
//Enemies struct
struct Enemy
{
    int life = 0;
    int damage = 0;
    int mecanic = 0;

    //Enemies function
    void getDamage(const Player& player);
    int attack() const;
    bool alive() const;
    void playEnemyMecanic(int mecanic);
};

//Enemies generator
Enemy generateEnemy(int life, int attack, int mecanic);