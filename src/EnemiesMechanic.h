#pragma once
#include <iostream>
#include "Game.h"
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
        cout<<"1   2   3   4   5"<<endl;
        num[0] = randomNum(1, max);
        num[1] = randomNum(1, max);
    }

    cin>>playerNum;

    if (playerNum < 0 || playerNum > max)
    {
        cout<<"It isn't a valid number"<<endl;
        numCombat(max, player, enemy);
        return;
    }
    else
    {
        if (num[0] == playerNum || num[1] == playerNum)
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

void patternMemo(int max, Player& Player, Enemy& enemy){
    int pattern[10] = {0}, playerPattern[10] = {0};
    
    for (int i = 0; i < max; i++)
    {
        pattern[i] = randomNum(1,9);
    }
    
}

void rockPaperScisors(){

}