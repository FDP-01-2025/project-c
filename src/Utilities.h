#pragma once
#include <iostream>
#include <random>
#include <thread>
#include <chrono>
#include <fstream>

void UTF8Config();

struct Player;
//Auxiliar functions
int randomNum(int min, int max);

void timer(int secs);

void save(Player& player);

void load(Player& player);

bool cinControl();