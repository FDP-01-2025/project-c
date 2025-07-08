#include "Player.h"
#include "UI.h"
#include <iostream>
using namespace std;

//Player functions 
void Player::getDamage(const Enemy& enemy){
    life -= enemy.attack();
}

void Player::useItem(){
    if (items != 0)
    {
        life++;
        if (life > lifeMax) life = lifeMax;        
        items--;
    }
    else playerTxt();
}

void Player::addItem(){
    items++;
}

void Player::increaseAttack() {
    damage++;
}

int Player::attack() const{
    return damage;
}

bool Player::alive() const{
    return life > 0;
}

