#include "Level.h"
#include "EnemiesMecanic.h"
#include <iostream>
using namespace std;

void combatMenu(int parameters[], int size, Player& player, Enemy& enemy);
void fight(int parameters[], int size, Player& player, Enemy& enemy);
void useItem(Player& player);
void exxit();

void playEnemyAttack(int mecanic, int parameters[], int size, Player& player, Enemy& enemy);