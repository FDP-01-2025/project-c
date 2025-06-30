#pragma once
#include <iostream>
#include "Utilities.h"
using namespace std;

struct Player;
//Enemies struct
struct Enemy
{
    int life = 0;
    int damage = 0;
    int mechanic = 0;

    //Enemies function
    void getDamage(const Player& player);
    int attack() const;
    bool alive() const;
};

//Enemies generator
Enemy generateEnemy(int life, int attack, int mechanic);