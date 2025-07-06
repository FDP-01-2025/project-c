#pragma once
#include "Game.h"
#include <iostream>
using namespace std;

void setColor(int color);

void clearScreen();

void worm();

void wormDamage();

void spider();

void spiderDamage();

void dragon();

void dragonDamage();

void knight();

void knightDamage();

void slime();

void slimeDamage();

void orc();

void orcDamage();

void snake();

void snakeDamage();

void mouse();

void mouseDamage();

void principalMenu();

void animationDamage(void (*normal)(int), void (*damage)(int), int nivel);

void firstGame(int opcion, Player& player);

void secondGame(int opcion, Player& player);

void thirdGame(int opcion, Player& player);

void showEnemy(int playerLevel);

void clearScreen();