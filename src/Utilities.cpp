#include "Utilities.h"
using namespace std;

//Auxiliar functions
int randomNum(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

void timer(int secs){
    this_thread::sleep_for(chrono::seconds(secs));
}

