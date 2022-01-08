//
// Created by Rafał on 07.01.2022.
//

#include "Individual.h"
#include "Random.h"
#include <iostream>

using namespace std;

void Individual::calculateFitness(int computed, int numberOfClauses) {
    this->fitness = static_cast< double > (computed) / static_cast< double > (numberOfClauses);
}

Individual* Individual::crossover(Individual* other, double crossoverProbability) {

    double decision = Random::generateRandomDouble(0.0, 1.0);

    if (decision < crossoverProbability) {
        // dokonujemy krzyzowania

        Individual* newInd = new Individual(this->genotypeSize);
        int crossPoint = Random::generateRandomDouble(0.0, this->genotypeSize);
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

    // generujemy liczbe wartosci ktore zostana zamienione z true na false lub z false na true
    int numToMutate = floor(Random::generateRandomDouble(0.0, genotypeSize * mutationProbability + 1));

    for (int i = 0; i < numToMutate; i++) {
            int indexToSwap = Random::generateRandomDouble(0, genotypeSize);

        // zmieniamy wartosc boolowska na przeciwna
        if (genotype[indexToSwap]) {
            genotype[indexToSwap] = false;
        } else {
            genotype[indexToSwap] = true;
        }
    }
    // pamietac aby po dokonaniu mutacji, policzyc fitness
}
