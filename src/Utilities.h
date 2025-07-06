#pragma once
#include <iostream>
#include <random>
#include <thread>
#include <chrono>
#include <fstream>

struct Player;
//Auxiliar functions
int randomNum(int min, int max);

void timer(int secs);

void save(const Player& player);

void load(const Player& player);