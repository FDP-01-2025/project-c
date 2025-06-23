#include <iostream>
#include "Player.h"
using namespace std;

//Enemies struct
struct Enemy
{
    int life = 0;
    int damage = 0;
    int mechanic = 0;

    //Enemies function
    void getDamage(const Player& player){
        life -= player.attack();
    }lskdjsldkjs

    int attack() const{
        return damage;
    }
    bool alive() const{
        return life > 0;
    };
};

//Enemies generator
Enemy generateEnemy(int life, int attack, int mechanic){
    Enemy enemy = {life, attack, mechanic};
    return enemy;
}