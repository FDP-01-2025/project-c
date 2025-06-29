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

void numsMemo(int max, int attempts, int goal, Player& player, Enemy& enemy){
    int nums[10] = {0}, playerNums[10] = {0}, fails = 0, successes = 0;

    do {
        bool areSimilar = true;

        cout << "Memorize the numbers:" << endl;
        for (int i = 0; i < max; i++) {
            nums[i] = randomNum(1, 9);
            cout << nums[i];
        }
        cout << endl;

        cout << "Numbers disappear in: ";
        for (int j = 5; j >= 0; j--) {
            cout << j << " " << flush;
            timer(1);
        }

        system("clear");

        cout << "Write the numbers:" << endl;
        for (int k = 0; k < max; k++) {
            cin >> playerNums[k];
        }

        for (int l = 0; l < max; l++) {
            if (nums[l] != playerNums[l]) {
                areSimilar = false;
                break;
            }        
        }

        if (areSimilar) {
            cout << "*CORRECT!*" << endl;
            successes++;
            if (max < 10) max++;
        } else {
            cout << "*WRONG!*" << endl;
            fails++;
        }

    } while (fails < attempts && successes < goal);
    
    if (fails == attempts) {
        cout << "Enemy is gonna kill you" << endl;
        player.getDamage(enemy);
    } else {
        cout << "You've defeated the enemy!" << endl;
        enemy.getDamage(player);
    }
}

