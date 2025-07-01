#include "Game.h"

void game(){
    Player player;
    Enemy enemy = generateEnemy(1, 1000, 2);
    numsMemo(3, 4, 10, player, enemy);
}