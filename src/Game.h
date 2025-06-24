#pragma once
#include "Player.h"
#include "Enemy.h"
#include "EnemiesMechanic.h"
#include "Level.h"
#include "Items.h"
#include "UI.h"
using namespace std;

void game(){
    Player player;
    Enemy enemy = generateEnemy(1, 10000000, 1);
    numsMemo(5, 3, 10, player, enemy);
}

//Auxiliar functions declarations and completes
void Enemy::getDamage(const Player& player){
    life -= player.attack();
}

int randomNum(int min, int max);