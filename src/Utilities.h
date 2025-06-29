#include <random>
#include <thread>
#include <chrono>
#include "Player.h"
#include "Enemy.h"
#include <iostream>
using namespace std;

//Auxiliar function declaration in Game.h completes here
int randomNum(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

void timer(int secs){
    this_thread::sleep_for(chrono::seconds(secs));
}

