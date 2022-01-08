//
// Created by Rafał on 30.12.2021.
//

#include <string>
#include <iostream>
#include <unistd.h>
#include <thread>
#include "Max3SatProblem.h"
#include "Individual.h"
#include "Random.h"

using namespace std;

int main() {
    Max3SatProblem problem;


    problem.load("m3s_100_2.txt");
    Optimizer *optimizer = new Optimizer(problem);
    optimizer->initialize();
    optimizer->print();
    cout << "\n";
    cout << "\n";
    for (int i = 0; i < 10000; i++) {
//        cout << "\n";
        optimizer->runIteration();
//        optimizer->print();
    }
    optimizer->print();

}
