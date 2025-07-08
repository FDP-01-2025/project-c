#include "Items.h"
#include "UI.h"
#include <iostream>
using namespace std;

//this happens every time you defeat an enemy
//couts says what happn in every case
void prizes(Player& player, bool shortcut){
    int win;
    //if you're in the second shortcut you've better probabilities
    if (shortcut)
    {
        do
        {
            win = 0;        
            if (randomNum(1,2) == 1)
            {
                itemsText(1);
                player.lifeMax += 1;
                win++;
            }
            if (randomNum(1,4) == 1)
            {
                itemsText(2);
                player.damage += 1;
                win++;
            }
                itemsText(3);
            player.items += 1;
            win++;
        } while (randomNum(1,2) == 1 && win != 3);
        
        //if you're lucky you can win the game of this way
        if (win == 3)
        {
            itemsText(4);
            itemsText(5);
            player.lvl = 100;
        }
    }
    //Same up but whit normal probabilities
    else
    {
        do
        {
            win = 0;
            if (randomNum(1,3) == 1)
            {
                itemsText(1);
                player.lifeMax += 1;
                win++;
            }
            if (randomNum(1,7) == 1)
            {
                itemsText(2);
                player.damage += 1;
                win++;
            }
            if (randomNum(1,2) == 1)
            {
                itemsText(3);
                player.items += 1;
                win++;
            }
        } while (randomNum(1,3) == 1 && win != 3);

        //You've to be very lucky if you win ts .___.
        if (win == 3)
        {
            itemsText(4);
            itemsText(5);
            player.lvl = 100;
        }
    }
    timer(2);
}

void infinitePrizes(Player& player){
    
    do
    {
        if (randomNum(1,3) == 1 && player.life < 10)
        {
            itemsText(1);
            player.lifeMax += 1;
        }
        if (randomNum(1,5) == 1 && player.damage < 10)
        {
            itemsText(2);
            player.damage += 1;
        }
        itemsText(3);
        player.items += 1;
    } while (randomNum(1,3) == 1);

    timer(2);
}