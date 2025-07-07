#include "Level.h"

void nextLevel(bool playerAlive, bool enemyAlive, Player& player, bool isInShortcut, bool infinite){
    if (!playerAlive)
    {
        player = {3,3,1,0,1,0};
        cout<<"GAME OVER"<<endl;
        if (infinite)
        {
            infiniteSave(player);
        }
        else
        {
            save(player);
        }
        timer(3);
        principalMenu();
    }
    else if (!enemyAlive)
    {
        cout<<"You win"<<endl;
        if (infinite)
        {
            player.lvl = randomNum(1,10);
            player.infinite++;
            cout<<"Enemies defeated: "<<player.infinite<<endl;
            infinitePrizes(player);
            infiniteSave(player);
        }
        else
        {        
            player.lvl++;
            prizes(player, isInShortcut);
            save(player);
        }
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

//Levels operation/ Normal game
void levelSelector(int lvl, Player& player){
    int parameters[3], shortcut, restart;
    Enemy enemy;
    bool isInShortcut = false;

    switch (lvl)
    {
    //normal path 1-6
    case 1:
        parameters[0] = 3;
        enemy = generateEnemy(3, 1, 1);
        combatMenu(parameters, 1, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, isInShortcut, false);
        break;
    case 2:
        shortcut = 7;
        parameters[0] = 3;
        parameters[1] = 7;
        parameters[2] = 4;
        enemy = generateEnemy(1, 10000, 2);
        combatMenu(parameters, 3, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, isInShortcut, false);
        useShortcut(player, shortcut);
        break;
    case 3:
        shortcut = 9;
        enemy = generateEnemy(5, 1, 3);
        combatMenu(parameters, 0, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, isInShortcut, false);
        useShortcut(player, shortcut);
        break;
    case 4:
        parameters[0] = 5;
        enemy = generateEnemy(6, 1, 1);
        combatMenu(parameters, 1, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, isInShortcut, false);
        break;
    case 5:
        parameters[0] = 5;
        parameters[1] = 12;
        parameters[2] = 5;
        enemy = generateEnemy(1, 10000, 2);
        combatMenu(parameters, 3, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, isInShortcut, false);
        break;
    case 6:
        enemy = generateEnemy(10, 5, 3);
        combatMenu(parameters, 0, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, isInShortcut, false);
        player.lvl = 100;
        break;
    //Shortcut 7, 8. After lvl 2. skip 3-5
    case 7:
        enemy = generateEnemy(4, 2, 3);
        combatMenu(parameters, 0, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, isInShortcut, false);
        break;
    case 8:
        parameters[0] = 4;
        parameters[1] = 9;
        parameters[2] = 4;
        enemy = generateEnemy(1, 10000, 2);
        combatMenu(parameters, 3, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, isInShortcut, false);
        player.lvl = 6;
        break;
    //Alter path 9, 10. After lvl 3. Better rewards
    case 9:
        isInShortcut = true;
        parameters[0] = 5;
        enemy = generateEnemy(7, 2, 1);
        combatMenu(parameters, 1, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, isInShortcut, false);
        break;
    case 10:
        isInShortcut = true;
        enemy = generateEnemy(8, 3, 3);
        combatMenu(parameters, 0, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, isInShortcut, false);
        player.lvl = 6;
        break;
    
    case 100:
        save(player);
        cout<<"You've win the game"<<endl;
        cout<<"Do you want to reset your progress?"<<endl;
        cout<<"1. Yes\n2. No"<<endl;
        cin>>restart;
        switch (restart)
        {
        case 1:
            cout<<"Restarting"<<endl;
            timer(2);
            player = {3, 3, 1, 0, 1};
            principalMenu();
            break;
        case 2:
            save(player);
            cout<<"Leaving the game"<<endl;
            timer(2);
            exit(0);        
        default:
            cout<<"It isn't a valid option"<<endl;
            break;
        }
        
        
        break;

    default:
        cout<<"DATA ERROR"<<endl;
        cout<<"Restarting progress"<<endl;
        timer(2);
        player = {3, 3, 1, 0, 1};
        break;
    }
    if (player.alive())
    {
        levelSelector(player.lvl, player);
    }
}

void infiniteLevels(int lvl, Player& player){
    int parameters[3];
    Enemy enemy;
    infiniteSave(player);

    switch (lvl)
    {
    case 1:
        parameters[0] = 3;        
        if (randomNum(1,2) == 1)
        {
            parameters[0] = 5;
        }
        enemy = generateEnemy(randomNum(1,12), randomNum(1,9), 1);
        combatMenu(parameters, 1, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, false, true);
        break;
    case 2:
        parameters[0] = randomNum(1,5);
        parameters[1] = randomNum(1, 10);
        parameters[2] = randomNum(1,4);
        enemy = generateEnemy(1, 10000, 2);
        combatMenu(parameters, 3, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, false, true);
        break;
    case 3:
        enemy = generateEnemy(randomNum(1,15), randomNum(1,9), 3);
        combatMenu(parameters, 0, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, false, true);
        break;
    case 4:
        parameters[0] = 3;        
        if (randomNum(1,2) == 1)
        {
            parameters[0] = 5;
        }
        enemy = generateEnemy(randomNum(1,12), randomNum(1,9), 1);
        combatMenu(parameters, 1, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, false, true);
        break;
    case 5:
        parameters[0] = randomNum(1,6);
        parameters[1] = randomNum(1, 10);
        parameters[2] = randomNum(1,4);
        enemy = generateEnemy(1, 10000, 2);
        combatMenu(parameters, 3, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, false, true);
        break;
    case 6:
        enemy = generateEnemy(randomNum(1,15), randomNum(1,9), 3);
        combatMenu(parameters, 0, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, false, true);
        break;
    case 7:
        enemy = generateEnemy(randomNum(1,15), randomNum(1,9), 3);
        combatMenu(parameters, 0, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, false, true);
        break;
    case 8:
        parameters[0] = randomNum(1,7);
        parameters[1] = randomNum(1, 10);
        parameters[2] = randomNum(1,4);
        enemy = generateEnemy(1, 10000, 2);
        combatMenu(parameters, 3, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, false, true);
        break;
    case 9:
        parameters[0] = 3;        
        if (randomNum(1,2) == 1)
        {
            parameters[0] = 5;
        }
        enemy = generateEnemy(randomNum(1,12), randomNum(1,9), 1);
        nextLevel(player.alive(), enemy.alive(), player, false, true);
        break;
    case 10:
        enemy = generateEnemy(randomNum(1,15), randomNum(1,9), 3);
        combatMenu(parameters, 0, player, enemy);
        nextLevel(player.alive(), enemy.alive(), player, false, true);
        break;
        
    default:
        cout<<"DATA ERROR"<<endl;
        cout<<"Restarting progress"<<endl;
        timer(2);
        player = {3, 3, 1, 0, 1};
        break;
    }
    if (player.alive())
    {
        infiniteLevels(player.lvl, player);
    }
}