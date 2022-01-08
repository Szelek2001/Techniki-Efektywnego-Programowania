//
// Created by Rafał on 08.01.2022.
//

#ifndef TECHNIKI_EFEKTYWNEGO_PROGRAMOWANIAA_RANDOM_H
#define TECHNIKI_EFEKTYWNEGO_PROGRAMOWANIAA_RANDOM_H
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

class Random {
public:
    static double generateRandomDouble(double min, double max);
    static int generateRandomInt(int min, int max);
    static bool generateRandomBool();

private:

};


#endif //TECHNIKI_EFEKTYWNEGO_PROGRAMOWANIAA_RANDOM_H
