#include "EnemiesMecanic.h"
#include "Game.h"
#include <iostream>
using namespace std;

void numCombat(int max, Player& player, Enemy& enemy){
    int num[2] = {0}, playerNum;
        selectNumber();
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
        invalidNumber();
        numCombat(max, player, enemy);
        return;
    }
    else
    {
        if (num[0] == playerNum || num[1] == playerNum)
        {
            enemyAttacks();
            player.getDamage(enemy);
        }
        else
        {
            youAttacks();
            enemy.getDamage(player);
        }
    }
}

void numsMemo(int max, int attempts, int goal, Player& player, Enemy& enemy){
    int nums[10] = {0}, playerNums[10] = {0}, fails = 0, successes = 0;
    string code, playerCode;

    do {
        bool areSimilar = true;
        code = "";

        memorizeNumber();
        for (int i = 0; i < max; i++) {
            nums[i] = randomNum(1, 9);
            code += to_string(nums[i]);
        }
        cout << code<<endl;

        numberDisappear();
        for (int j = 5; j >= 0; j--) {
            cout << j << " " << flush;
            timer(1);
        }

        system("clear");

        writeNumber();
        cin>>playerCode;

        if (code != playerCode) {
            areSimilar = false;
        }        

        if (areSimilar) {
            correct();
            successes++;
            if (max < 10) max++;
        } else {
            wrong();
            fails++;
        }

    } while (fails < attempts && successes < goal);
    
    if (fails == attempts) {
        enemyKill();
        player.getDamage(enemy);
    } 
    else if (successes == goal){
        youKill();
        enemy.getDamage(player);
    }
}

void rockPaperScisors(Player& player, Enemy& enemy){
    int enemyAction, action;

    enemyAction = randomNum(1, 3);
    
    switch (enemyAction)
    {
    case 1:
        weakAttck();
        break;
    case 2:
        strongAttack();
        break;
    case 3:
        protection();
        break;
    }

    timer(1);
    system("clear");

    chooseAction();
    cin>>action;

    if (action < 1 || action > 3) {
        invalidNumber();
        rockPaperScisors(player, enemy);
        return;
    }

    switch(action){

    case 1: 
        if (enemyAction == 1){
            sameAction();
        }
        else if (enemyAction == 2){
            youAttacks();
             enemy.getDamage(player);
        }

        else {
            enemyAttacks();
            player.getDamage(enemy);
        }
    break;

    case 2: 
        if (enemyAction == 2){
            sameAction();
        }
        else if (enemyAction == 3){
            youAttacks();
             enemy.getDamage(player);
        }

        else {
            enemyAttacks();
            player.getDamage(enemy);
        }
    break;

    case 3: 
        if (enemyAction == 3){
            sameAction();
        }
        else if (enemyAction == 1){
            youAttacks();
             enemy.getDamage(player);
        }

        else {
            enemyAttacks();
            player.getDamage(enemy);
        }
    break;

    }
}
