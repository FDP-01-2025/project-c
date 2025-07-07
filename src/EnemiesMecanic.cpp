#include "EnemiesMecanic.h"
#include "Game.h"
#include <iostream>
using namespace std;

void numCombat(int max, Player& player, Enemy& enemy){
    int num[2] = {0}, playerNum;
        firstGame(1, player);
    if (max == 3){
        firstGame(2, player);
        num[1] = randomNum(1, max);
    } 
    else{
        firstGame(3, player);
        num[0] = randomNum(1, max);
        num[1] = randomNum(1, max);
    }

    cin>>playerNum;
    if (cinControl())
    {
        numCombat(max, player, enemy);
        return;
    }
    

    if (playerNum < 0 || playerNum > max)
    {
        firstGame(4, player);
        numCombat(max, player, enemy);
        return;
    }
    else
    {
        if (num[0] == playerNum || num[1] == playerNum)
        {
            firstGame(5, player);
            player.getDamage(enemy);
        }
        else
        {
            firstGame(6, player);
            enemy.getDamage(player);
        }
    }
}

void numsMemo(int max, int goal, int attempts, Player& player, Enemy& enemy) {
    int nums[10] = {0}, fails = 0, successes = 0;
    string code, playerCode;

    do {
        code = "";
        secondGame(1, player);

        for (int i = 0; i < max; i++) {
            nums[i] = randomNum(1, 9);
            code += to_string(nums[i]);
        }
        cout << code << endl;

        secondGame(2, player);
        for (int j = 5; j >= 0; j--) {
            cout << j << " " << flush;
            timer(1);
        }
        clearScreen();
        secondGame(3, player);
        cin >> playerCode;

        if (code == playerCode) {
            secondGame(4, player);
            successes++;
            if (max < 10) max++;
        } else {
            secondGame(5, player);
            fails++;
        }

    } while (fails < attempts && successes < goal);

    if (fails == attempts) {
        secondGame(6, player);
        player.getDamage(enemy);
    } 
    else if (successes == goal) {
        secondGame(7, player);
        enemy.getDamage(player);
    }
}

void rockPaperScisors(Player& player, Enemy& enemy){
    int enemyAction, action;

    enemyAction = randomNum(1, 3);

    switch (enemyAction)
    {
    case 1:
        if (randomNum(1,2) == 1)
        {
            clearScreen();
            showEnemy(player.lvl);
            thirdGame(1, player);
            thirdGame(randomNum(1,3), player);
        }
        else
        {
            clearScreen();
            showEnemy(player.lvl);
            thirdGame(randomNum(1,3), player);
            thirdGame(1, player);
        }
        break;
    case 2:
        if (randomNum(1,2) == 1)
        {
            clearScreen();
            showEnemy(player.lvl);
            thirdGame(2, player);
            thirdGame(randomNum(1,3), player);
        }
        else
        {
            clearScreen();
            showEnemy(player.lvl);
            thirdGame(randomNum(1,3), player);
            thirdGame(2, player);
        }
        break;
    case 3:
        if (randomNum(1,2) == 1)
        {
            clearScreen();
            showEnemy(player.lvl);
            thirdGame(3, player);
            thirdGame(randomNum(1,3), player);
        }
        else
        {
            clearScreen();
            showEnemy(player.lvl);
            thirdGame(randomNum(1,3), player);
            thirdGame(3, player);
        }
        break;
    }

    timer(1);
    clearScreen();

    thirdGame(4, player);
    cin>>action;
    if (cinControl())
    {
        rockPaperScisors(player, enemy);
        return;
    }
    

    if (action < 1 || action > 3) {
        thirdGame(5, player);
        rockPaperScisors(player, enemy);
        return;
    }

    switch(action){

    case 1: 
        if (enemyAction == 1){
            thirdGame(6, player);
        }
        else if (enemyAction == 2){
            thirdGame(7, player);
             enemy.getDamage(player);
        }

        else {
            thirdGame(8, player);
            player.getDamage(enemy);
        }
    break;

    case 2: 
        if (enemyAction == 2){
            thirdGame(6, player);
        }
        else if (enemyAction == 3){
            thirdGame(7, player);
             enemy.getDamage(player);
        }

        else {
            thirdGame(8, player);
            player.getDamage(enemy);
        }
    break;

    case 3: 
        if (enemyAction == 3){
            thirdGame(6, player);
        }
        else if (enemyAction == 1){
            thirdGame(7, player);
             enemy.getDamage(player);
        }

        else {
            thirdGame(8, player);
            player.getDamage(enemy);
        }
    break;

    }
}
