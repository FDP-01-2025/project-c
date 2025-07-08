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

void firstGame(int option, Player& player);

void secondGame(int option, Player& player);

void thirdGame(int option, Player& player);

void showEnemy(int playerLevel);

void clearScreen();

void UTF8Config();

void loadingScreen();

void secondMenu(int option, Player& player, Enemy& enemy);

void invalid();

void itemsText(int option);

void levelTxt(int option);

void playerTxt();

void utilitesTxt(int option);

