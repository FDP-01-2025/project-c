#include "EnemiesMecanic.h"
#include "Game.h"
#include <iostream>
using namespace std;

void numCombat(int max, Player& player, Enemy& enemy){
    int num[2] = {0}, playerNum;
        firstGame(1);
    if (max == 3){
        firstGame(2);
        num[1] = randomNum(1, max);
    } 
    else{
        firstGame(3);
        num[0] = randomNum(1, max);
        num[1] = randomNum(1, max);
    }

    cin>>playerNum;

    if (playerNum < 0 || playerNum > max)
    {
        firstGame(4);
        numCombat(max, player, enemy);
        return;
    }
    else
    {
        if (num[0] == playerNum || num[1] == playerNum)
        {
            firstGame(5);
            player.getDamage(enemy);
        }
        else
        {
            firstGame(6);
            enemy.getDamage(player);
        }
    }
}

void numsMemo(int max, int goal, int attempts, Player& player, Enemy& enemy) {
    int nums[10] = {0}, fails = 0, successes = 0;
    string code, playerCode;

    do {
        code = "";
        secondGame(1);

        for (int i = 0; i < max; i++) {
            nums[i] = randomNum(1, 9);
            code += to_string(nums[i]);
        }
        cout << code << endl;

        secondGame(2);
        for (int j = 5; j >= 0; j--) {
            cout << j << " " << flush;
            timer(1);
        }

        system("clear");
        secondGame(3);
        cin >> playerCode;

        if (code == playerCode) {
            secondGame(4);
            successes++;
            if (max < 10) max++;
        } else {
            secondGame(5);
            fails++;
        }

    } while (fails < attempts && successes < goal);

    if (fails == attempts) {
        secondGame(6);
        player.getDamage(enemy);
    } 
    else if (successes == goal) {
        secondGame(7);
        enemy.getDamage(player);
    }
}


void rockPaperScisors(Player& player, Enemy& enemy){
    int enemyAction, action;

    enemyAction = randomNum(1, 3);
    
    switch (enemyAction)
    {
    case 1:
        thirdGame(1);
        break;
    case 2:
        thirdGame(2);
        break;
    case 3:
        thirdGame(3);
        break;
    }

    timer(1);
    system("clear");

    thirdGame(4);
    cin>>action;

    if (action < 1 || action > 3) {
        thirdGame(5);
        rockPaperScisors(player, enemy);
        return;
    }

    switch(action){

    case 1: 
        if (enemyAction == 1){
            thirdGame(6);
        }
        else if (enemyAction == 2){
            thirdGame(7);
             enemy.getDamage(player);
        }

        else {
            thirdGame(8);
            player.getDamage(enemy);
        }
    break;

    case 2: 
        if (enemyAction == 2){
            thirdGame(6);
        }
        else if (enemyAction == 3){
            thirdGame(7);
             enemy.getDamage(player);
        }

        else {
            thirdGame(8);
            player.getDamage(enemy);
        }
    break;

    case 3: 
        if (enemyAction == 3){
            thirdGame(6);
        }
        else if (enemyAction == 1){
            thirdGame(7);
             enemy.getDamage(player);
        }

        else {
            thirdGame(8);
            player.getDamage(enemy);
        }
    break;

    }
}
