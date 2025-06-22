//Principal program
#include <iostream>
using namespace std;

struct Player
{
    int life = 0;
    int maxLife = 0;
    int atack = 0;
    int potions = 0;
    int lvl = 0;
};


int main(){
    Player player = {3, 3, 1, 0, 1};

    return 0;
}