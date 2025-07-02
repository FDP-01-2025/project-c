#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Combat.h"
#include "EnemiesMecanic.h"

struct Level
{
    int num;
    Enemy enemy;
};

Level levelGenerator(int num, Enemy& enemy);

void nextLevel(bool playerAlive, bool enemyAlive, Player& player);

void useShortcut(Player& player, int shortcut);

void levelSelector(int lvl, Player& player);