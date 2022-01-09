//
// Created by Rafał on 08.01.2022.
//

#ifndef TECHNIKI_EFEKTYWNEGO_PROGRAMOWANIAA_OPTIMIZER_H
#define TECHNIKI_EFEKTYWNEGO_PROGRAMOWANIAA_OPTIMIZER_H

#include <vector>
#include <random>
#include <string>
#include <iostream>
#include "Individual.h"
#include "Max3SatProblem.h"

using namespace std;
const int POPULATION_SIZE = 20;
const int TOURNAMENT_SIZE = 4;
const double CROSSOVER_PROBABILITY = 0.7;
const double MUTATION_PROBABILITY = 0.005;


class Optimizer {
public:
    Optimizer(Max3SatProblem* newProblem) { problem = newProblem; };
    ~Optimizer();
    void initialize();
    void runIteration();

    void findBestSolution();
    Individual* chooseParent();
    void printbest();
    void print();
    Individual* getBestFound() { return bestFound; };
private:
    vector<Individual*> population;
    Individual* bestFound;
    Max3SatProblem* problem;


};


#endif //TECHNIKI_EFEKTYWNEGO_PROGRAMOWANIAA_OPTIMIZER_H
