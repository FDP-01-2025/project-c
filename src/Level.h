#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Combat.h"
#include "EnemiesMecanic.h"
#include "Items.h"
#include "UI.h"

void nextLevel(bool playerAlive, bool enemyAlive, Player& player);

void useShortcut(Player& player, int shortcut);

void levelSelector(int lvl, Player& player);

void infiniteLevels(int lvl, Player& player);