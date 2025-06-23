#include <random>
#include <iostream>
using namespace std;

int randomNum(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd()); // Motor de generación
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}