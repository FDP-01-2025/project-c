#include "Game.h"

void game(){   
    Player player;
    load(player);
    levelSelector(player.lvl, player);
}

void infiniteMode(){
    Player player;
    infiniteLoad(player);
    player.lvl = randomNum(1,10);
    infiniteLevels(player.lvl, player);
}
