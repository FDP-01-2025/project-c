#include "Utilities.h"
#include <windows.h>
using namespace std;

//Auxiliar functions
int randomNum(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

void timer(int millis){
    Sleep(millis * 1000);
}

