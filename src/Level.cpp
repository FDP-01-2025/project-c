#include "Level.h"

Level levelGenerator(int num, Enemy& enemy){
    Level level = {num, enemy};
    return level;
}

void nextLevel(bool playerAlive, bool enemyAlive, Player& player, bool isInShortcut){
    if (!playerAlive)
    {
        //game over
    }
    else if (!enemyAlive)
    {
        cout<<"You win"<<endl;
        player.lvl++;
        prizes(player, isInShortcut);
    }
}

void useShortcut(Player& player, int shortcut){
    int option;

    if (player.alive())
    {
        if (shortcut == 7)
        {
            cout<<"Do you want to take a shortcut?"<<endl;
        }
        else
        {
            cout<<"Do you want to take an alter path?"<<endl;
            cout<<"You could win better rewards >;D"<<endl;
        }
        cout<<"Enemies gona be more dangerous"<<endl;
        cout<<"1. Yes\n2. No"<<endl;
        cin>>option;
        
        switch (option)
        {
        case 1:
            player.lvl = shortcut;
            cout<<"Entering the shortcut >:)"<<endl;
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

//Levels operation
void levelSelector(int lvl, Player& player){
    int parameters[3], shortcut;
    Enemy enemy;
    bool isInShortcut = false;

    switch (lvl)
    {
    //normal path 1-6
    case 1:
        parameters[0] = 3;
        enemy = generateEnemy(3, 1, 1);
        levelGenerator(1, enemy);
        combatMenu(parameters, 1, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, isInShortcut);
        break;
    case 2:
        shortcut = 7;
        parameters[0] = 3;
        parameters[1] = 7;
        parameters[2] = 4;
        enemy = generateEnemy(1, 10000, 2);
        levelGenerator(2, enemy);
        combatMenu(parameters, 3, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, isInShortcut);
        useShortcut(player, shortcut);
        break;
    case 3:
        shortcut = 9;
        enemy = generateEnemy(5, 1, 3);
        levelGenerator(3, enemy);
        combatMenu(parameters, 0, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, isInShortcut);
        useShortcut(player, shortcut);
        break;
    case 4:
        parameters[0] = 5;
        enemy = generateEnemy(6, 1, 1);
        levelGenerator(4, enemy);
        combatMenu(parameters, 1, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, isInShortcut);
        break;
    case 5:
        parameters[0] = 5;
        parameters[1] = 12;
        parameters[2] = 5;
        enemy = generateEnemy(1, 10000, 2);
        levelGenerator(5, enemy);
        combatMenu(parameters, 3, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, isInShortcut);
        break;
    case 6:
        //arregla esto para que no avance al atajo
        enemy = generateEnemy(10, 5, 3);
        levelGenerator(6, enemy);
        combatMenu(parameters, 0, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, isInShortcut);
        break;
    //Shortcut 7, 8. After lvl 2. skip 3-5
    case 7:
        enemy = generateEnemy(4, 2, 3);
        levelGenerator(7, enemy);
        combatMenu(parameters, 0, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, isInShortcut);
        break;
    case 8:
        parameters[0] = 4;
        parameters[1] = 9;
        parameters[2] = 4;
        enemy = generateEnemy(1, 10000, 2);
        levelGenerator(8, enemy);
        combatMenu(parameters, 3, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, isInShortcut);
        player.lvl = 6;
        break;
    //Alter path 9, 10. After lvl 3. Better rewards
    case 9:
        isInShortcut = true;
        parameters[0] = 5;
        enemy = generateEnemy(7, 2, 1);
        levelGenerator(9, enemy);
        combatMenu(parameters, 1, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, isInShortcut);
        break;
    case 10:
        isInShortcut = true;
        enemy = generateEnemy(8, 3, 3);
        levelGenerator(10, enemy);
        combatMenu(parameters, 0, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, isInShortcut);
        player.lvl = 6;
        break;

    default:
        break;
    }
    levelSelector(player.lvl, player);
}
