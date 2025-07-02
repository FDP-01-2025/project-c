#include "Items.h"
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
            if (randomNum(1,3) == 1)
            {
                cout<<"You win a max life increase"<<endl;
                player.lifeMax += 1;
                win++;
            }
            if (randomNum(1,4) == 1)
            {
                cout<<"You win a damage increase"<<endl;
                player.damage += 1;
                win++;
            }
            cout<<"You win a life potion"<<endl;
            player.items += 1;
            win++;
        } while (randomNum(1,2) == 1);
        
        //if you're lucky you can win the game of this way
        if (win == 3)
        {
            cout<<"You've win the great jackpot"<<endl;
            cout<<"You've win the game"<<endl;
        }
        
    }
    //Same up but whit normal probabilities
    else
    {
        do
        {
            win = 0;
            if (randomNum(1,5) == 1)
            {
                cout<<"You win a max life increase"<<endl;
                player.lifeMax += 1;
            }
            if (randomNum(1,10) == 1)
            {
                cout<<"You win a damage increase"<<endl;
                player.damage += 1;
            }
            if (randomNum(1,3) == 1)
            {
                cout<<"You win a life potion"<<endl;
                player.items += 1;
            }
        } while (randomNum(1,5) == 1);

        //You've to be very lucky if you win ts .___.
        if (win == 3)
        {
            cout<<"You've win the great jackpot"<<endl;
            cout<<"You've win the game"<<endl;
        }
    }
}