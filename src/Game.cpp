#include "Game.h"

void game(){   
    Player player;
    load(player);
    levelSelector(player.lvl, player);
}

void infiniteMode(){
    Player player;
    infiniteLoad(player);
    infiniteLevels(player.lvl, player);
}
