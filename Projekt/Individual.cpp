//
// Created by Rafał on 07.01.2022.
//

#include "Individual.h"
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>


void Individual::calculateFitness(int computed, int numberOfClauses) {
    this->fitness = static_cast< double > (computed) / static_cast< double > (numberOfClauses);
}

Individual* Individual::crossover(Individual* other, double crossoverProbability) {

    // losowa liczba miedzy 0 a 1
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    double decision = dis(gen);

    cout << decision << endl;
    if (decision < crossoverProbability) {
        // dokonujemy krzyzowania

        Individual* newInd = new Individual(this->genotypeSize);
        int crossPoint = rand() % this->genotypeSize;
        cout << "punkt krzyzowania: " << crossPoint << endl;
        bool* crossedGenotype = new bool[this->genotypeSize];

        // czesc genotypu this od 0 do punktu krzyzowania
        for (int i = 0; i < crossPoint; ++i) {
            crossedGenotype[i] = this->genotype[i];
        }

        // czesc genotypu other od punktu krzyzowania do konca
        for (int i = crossPoint; i < this->genotypeSize-1; ++i) {
            crossedGenotype[i] = other->genotype[i];
        }

        newInd->setGenotype(crossedGenotype);

        return newInd;
        // pamietac aby po dokonaniu krzyzowania, policzyc fitness
    }
    else {
        // nie dokonujemy krzyzowania, zwracamy lepszego rodzica bez zmian
        if (this->fitness > other->getFitness()) {
            return this;
        }
        else {
            return other;
        }
    }
}

void Individual::mutation(double mutationProbability) {
    srand( time( NULL ) );

    // generujemy liczbe wartosci ktore zostana zamienione z true na false lub z false na true
    int numToMutate = floor(static_cast< double > ( static_cast< double >(  rand() % (static_cast< int >(genotypeSize *mutationProbability) + 1))));

    for (int i = 0; i < numToMutate; i++) {

        int indexToSwap = rand() % genotypeSize;

        // zmieniamy wartosc boolowska na przeciwna
        if (genotype[indexToSwap]) {
            genotype[indexToSwap] = false;
        } else {
            genotype[indexToSwap] = true;
        }
    }
    // pamietac aby po dokonaniu mutacji, policzyc fitness
}
