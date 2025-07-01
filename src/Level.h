#include "Enemy.h"
#include "Player.h"
#include "EnemiesMecanic.h"

struct Level
{
    int num;
    Enemy enemy;
};

Level levelGenerator(int num, Enemy& enemy);

void levelSelector(int lvl, Player& player);
