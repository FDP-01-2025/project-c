#include "Utilities.h"
#include "Player.h"
using namespace std;

//Auxiliar functions
int randomNum(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

void timer(int secs){
    this_thread::sleep_for(chrono::seconds(secs));
}

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
        cout<<"SAVED"<<endl;
    }
    else
    {
        cout<<"SAVE ERROR"<<endl;
    }
}

void load(Player& player)
{
    ifstream file("data.txt");

    if (file.is_open())
    {
        int life, lifeMax, damage, items, lvl;

        if (file >> life >> lifeMax >> damage >> items >> lvl)
        {
            player = {life, lifeMax, damage, items, lvl};
            cout<<"LOAD"<<endl;
        }
        else
        {
            cout << "LOAD ERROR: Invalid file format" << endl;
        }

        file.close();
    }
    else
    {
        save(player);
    }
}


