#include "Combat.h"

//This menu apears when you enter in a room
void combatMenu(int parameters[], int size, Player& player, Enemy& enemy){
    int option;
    do
    {   
        timer(1);
        clearScreen();
        secondMenu(2, player, enemy);
        secondMenu(3, player, enemy);
        secondMenu(1, player, enemy);
        cin>>option;
        cinControl();

        switch (option)
        {
        case 1:
            playEnemyAttack(enemy.mecanic, parameters, size, player, enemy);
            break;
        case 2:
            player.useItem();
            break;
        case 3:
            exit(0);
            break;
        default:
            invalid();
            break;
        }
    }while (player.alive() && enemy.alive());    
}

//This select the mecanic of the enemy
void playEnemyAttack(int mecanic, int parameters[], int size, Player& player, Enemy& enemy){
    switch (mecanic)
    {
    case 1:
        numCombat(parameters[0], player, enemy);
        break;
    case 2:
        numsMemo(parameters[0], parameters[1], parameters[2], player, enemy);
        break;
    case 3:
        rockPaperScisors(player, enemy);
        break;    
    default:
        break;
    }
}
