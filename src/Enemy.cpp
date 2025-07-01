#include <iostream>
#include "Enemy.h"
#include "Player.h"

//Enemies function
void Enemy::getDamage(const Player& player){
life -= player.attack();
}
int Enemy::attack() const{
    return damage;
}
bool Enemy::alive() const{
    return life > 0;
};

//Enemies generator
Enemy generateEnemy(int life, int attack, int mechanic){
    Enemy enemy = {life, attack, mechanic};
    return enemy;
}