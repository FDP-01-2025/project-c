#include "Utilities.h"
#include "UI.h"
#include "Player.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;


//Auxiliar functions

//Ranodom number generator
int randomNum(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

//timer
void timer(int secs) {
#ifdef _WIN32
    Sleep(secs * 1000); // ms
#else
    sleep(secs); // s
#endif
}

//Save game
void save(Player& player)
{
    ofstream temp("temp.txt");
    bool saved = false;

    if (temp.is_open())
    {
        temp<<player.life<<" "<<player.lifeMax<<" "<<player.damage<<" "<<player.items<<" "<<player.lvl<<endl;
        saved = true;
    }

    temp.close();

    if (saved)
    {
        remove("data.txt");
        rename("temp.txt", "data.txt");
        utilitesTxt(1);
    }
    else
    {
        utilitesTxt(2);
    }
}

//Load game
void load(Player& player)
{
    ifstream file("data.txt");

    if (file.is_open())
    {
        int life, lifeMax, damage, items, lvl;

        if (file >> life >> lifeMax >> damage >> items >> lvl)
        {
            player = {life, lifeMax, damage, items, lvl};
            
                loadingScreen();
        }
        else
        {
            utilitesTxt(3);
        }

        file.close();
    }
    else
    {
        save(player);
    }
}

//Save in infinite mode
void infiniteSave(Player& player)
{
    ofstream temp("temp.txt");
    bool saved = false;

    if (temp.is_open())
    {
        temp<<player.life<<" "<<player.lifeMax<<" "<<player.damage<<" "<<player.items<<" "<<player.lvl<<" "<<player.infinite<<endl;
        saved = true;
    }

    temp.close();

    if (saved)
    {
        remove("infiniteData.txt");
        rename("temp.txt", "infiniteData.txt");
        utilitesTxt(1);
    }
    else
    {
        utilitesTxt(2);
    }
}

//Load in infinite game
void infiniteLoad(Player& player)
{
    ifstream file("infiniteData.txt");

    if (file.is_open())
    {
        int life, lifeMax, damage, items, lvl, infinite;

        if (file >> life >> lifeMax >> damage >> items >> lvl >> infinite)
        {
            player = {life, lifeMax, damage, items, lvl, infinite};
            
                utilitesTxt(4);
        }
        else
        {
            utilitesTxt(3);
        }

        file.close();
    }
    else
    {
        infiniteSave(player);
    }
}

//Control in case imput != number
bool cinControl(){
    if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            invalid();
            return true;
        }
    else return false;
}

