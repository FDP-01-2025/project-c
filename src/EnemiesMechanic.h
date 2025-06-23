#include <iostream>
#include "Utilities.h"
#include "Player.h"
#include "Enemy.h"
using namespace std;

void numCombat(int max, Player& player, Enemy& enemy){
    int num[2] = {0}, playerNum;
    cout<<"Selecciona un número"<<endl;
    if (max == 3){
        cout<<"1    2   3"<<endl;
        num[1] = randomNum(1, max);
    } 
    else{
        cout<<"1   2   3   4   5";
        num[1] = randomNum(1, max);
        num[2] = randomNum(1, max);
    }

    cin>>playerNum;

    if (playerNum < 0 && playerNum > max)
    {
        cout<<"It isn't a valid number"<<endl;
        numCombat(max, player, enemy)
        return;
    }
    else
    {
        if (num[1] == playerNum || num[2] == playerNum)
        {
            cout<<"*ENEMY ATTACKS YOU*"<<endl;
            player.getDamage(enemy);
        }
        else
        {
            cout<<"*YOU ATTACK ENEMY*"<<endl;
            enemy.getDamage(player);
        }
    }
}

void patternMemo(){

}

void rockPaperScisors(){

}