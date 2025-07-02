#include "Items.h"

void prizes(Player& player, bool shortcut){
    if (shortcut)
    {
        if (randomNum(1,3) == 1)
        {
            cout<<"You win a max life increase"<<endl;
            player.lifeMax += 1;
        }
        if (randomNum(1,4) == 1)
        {
            cout<<"You win a damage increase"<<endl;
            player.damage += 1;
        }
        do
        {
            cout<<"You win a life potion"<<endl;
            player.items += 1;
        } while (randomNum(1,2) == 1);
        
    }
    else
    {
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
        do
        {
            if (randomNum(1,3) == 1)
            {
                cout<<"You win a life potion"<<endl;
                player.items += 1;
            }
        } while (randomNum(1,5) == 1);
        
    }
}