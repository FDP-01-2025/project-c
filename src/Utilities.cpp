#include "Utilities.h"
#include "Player.h"
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
void timer(int secs){
    this_thread::sleep_for(chrono::seconds(secs));
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
        cout<<"SAVED"<<endl;
    }
    else
    {
        cout<<"SAVE ERROR"<<endl;
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

//Control in case imput != number
bool cinControl(){
    if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "It isn't a valid option"<<endl;
            return true;
        }
    else return false;
}
