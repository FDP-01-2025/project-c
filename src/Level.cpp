#include "Level.h"

Level levelGenerator(int num, Enemy& enemy){
    Level level = {num, enemy};
    return level;
}

void nextLevel(bool playerAlive, bool enemyAlive, Player& player){
        if (!playerAlive)
    {
        //game over
    }
    else if (!enemyAlive)
    {
        cout<<"You win"<<endl;
        player.lvl++;
        levelSelector(player.lvl, player);
    }
}

void useShortcut(Player& player, int shortcut){
    int option;

    if (player.alive())
    {
        cout<<"Do you want to take a shortcut?"<<endl;
        cout<<"Enemies gona be more dangerous"<<endl;
        cout<<"1. Yes\n2. No"<<endl;
        cin>>option;
        
        switch (option)
        {
        case 1:
            player.lvl = shortcut;
            cout<<"Entering the shortcut >:)"<<endl;
            levelSelector(player.lvl, player);
            break;
        case 2:
            cout<<"Continuing normal path"<<endl;
            break;
        default:
            cout<<"It isn't a valid option"<<endl;
            useShortcut(player, shortcut);
            break;
        }
    }
}

void levelSelector(int lvl, Player& player){
    int parameters[3];
    Enemy enemy;
    int shortcut;  

    switch (lvl)
    {
    //normal path 1-6
    case 1:
        parameters[0] = 3;
        enemy = generateEnemy(3, 1, 1);
        levelGenerator(1, enemy);
        combatMenu(parameters, 1, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player);
        break;
    case 2:
        shortcut = 7;
        parameters[0] = 3;
        parameters[1] = 7;
        parameters[2] = 4;
        enemy = generateEnemy(1, 10000, 2);
        levelGenerator(2, enemy);
        combatMenu(parameters, 3, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player);
        useShortcut(player, shortcut);
        
        break;
    case 3:
        shortcut = 9;
        enemy = generateEnemy(5, 1, 3);
        levelGenerator(3, enemy);
        combatMenu(parameters, 0, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player);
        useShortcut(player, shortcut);
        break;
    case 4:
        parameters[0] = 5;
        enemy = generateEnemy(6, 1, 1);
        levelGenerator(4, enemy);
        break;
    case 5:
        parameters[0] = 5;
        parameters[1] = 12;
        parameters[2] = 5;
        enemy = generateEnemy(1, 10000, 2);
        levelGenerator(5, enemy);
        break;
    case 6:
        enemy = generateEnemy(10, 5, 3);
        levelGenerator(6, enemy);
        break;
    //Shortcut 7, 8. After lvl 2. skip 3-5
    case 7:
        enemy = generateEnemy(4, 2, 3);
        levelGenerator(7, enemy);
        break;
    case 8:
        parameters[0] = 4;
        parameters[1] = 9;
        parameters[2] = 4;
        enemy = generateEnemy(1, 10000, 2);
        levelGenerator(8, enemy);
        break;
    //Alter path 9, 10. After lvl 3. Better rewards
    case 9:
        parameters[0] = 5;
        enemy = generateEnemy(7, 2, 1);
        levelGenerator(9, enemy);
        break;
    case 10:
        enemy = generateEnemy(8, 3, 3);
        levelGenerator(10, enemy);
        break;

    default:
        break;
    }
}
