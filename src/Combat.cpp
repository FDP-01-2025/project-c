#include "Combat.h"

void combatMenu(int parameters[], int size, Player& player, Enemy& enemy){
    int option;
    cout<<"Select an option"<<endl;
    cout<<"1. Fight\n2. Use Item"<<player.items<<"\n3. Exit"<<endl;
    cin>>option;

    switch (option)
    {
    case 1:
        fight(parameters, size, player, enemy);
        break;
    case 2:
        useItem();
        break;
    case 3:
        exit();
        break;
    default:
        cout<<"It isn't a valid option"<<endl;
        break;
    }
}
void fight(int parameters[], int size, Player& player, Enemy& enemy);
void useItem();
void exit();

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