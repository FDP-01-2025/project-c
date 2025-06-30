#include "Game.h"

void game(){
    Player player;
    Enemy enemy = generateEnemy(1, 10000000, 1);
    rockPaperScisors(player, enemy);
}
