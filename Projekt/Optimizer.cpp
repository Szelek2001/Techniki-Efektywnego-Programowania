//
// Created by Rafał on 08.01.2022.
//

#include "Optimizer.h"
#include "Random.h"

using namespace std;

void Optimizer::initialize() {
    for (int i = 0; i < POPULATION_SIZE; ++i) {
        Individual *newIndividual = new Individual(problem.getNumberOfVariables());
        bool *newGenotype = new bool[problem.getNumberOfVariables()];
        for (int k = 0; k < problem.getNumberOfVariables(); ++k) {
            newGenotype[k] = Random::generateRandomBool();
        }
        newIndividual->setGenotype(newGenotype);
        newIndividual->calculateFitness(problem.compute(newGenotype), problem.getNumberOfClauses());
        population.push_back(newIndividual);
    }
    findBestSolution();
}

void Optimizer::runIteration() {
    vector < Individual * > newPopulation;
    while (newPopulation.size() < population.size()) {
        Individual *parent1 = chooseParent();
        Individual *parent2 = chooseParent();
        Individual *child1 = parent1->crossover(parent2,CROSSOVER_PROBABILITY);
        Individual *child2 = parent2->crossover(parent1,CROSSOVER_PROBABILITY);
        child1->mutation(MUTATION_PROBABILITY);
        child2->mutation(MUTATION_PROBABILITY);
        newPopulation.push_back(child1);
        newPopulation.push_back(child2);
    }

    population = newPopulation;
    for (int i = 0; i < population.size(); i++) {
        population.at(i)->calculateFitness(problem.compute(population.at(i)->getGenotype()), problem.getNumberOfClauses());
    }
    findBestSolution();
}

void Optimizer::findBestSolution() {
    bestFound = population.at(0);
    for (int i = 1; i < population.size(); i++) {
        if (population.at(i)->getFitness() > bestFound->getFitness()) {
            bestFound = population.at(i);
        }
    }
}

Individual *Optimizer::chooseParent() {
    vector <Individual *> tournament;
    //losowanie zawodników
    for (int i = 0; i < TOURNAMENT_SIZE; ++i) {
        int pickedIndex = Random::generateRandomInt(0, population.size());
        tournament.push_back(population.at(pickedIndex));
    }

    //Wybor najlepszego osobnika
    Individual * tournamentWinner = tournament.at(0);

    for (int i = 0; i < TOURNAMENT_SIZE; ++i){
        if (tournamentWinner->getFitness() < tournament.at(i)->getFitness()){
            tournamentWinner = tournament.at(i);
        }
    }
    
    return tournamentWinner;
}

void Optimizer::crossoverAndFitness(Individual *individual1, Individual *individual2) {

}

void Optimizer::mutationAndFitness(Individual *individual1) {

}

void Optimizer::print() {
    for (int i = 0; i < population.size(); ++i) {
        cout << "nr: " << i << " : genotyp: ";
        for (int j = 0; j < population.at(i)->getGenotypeSize(); ++j) {
            cout << population.at(i)->getGenotype()[j];
        }
        cout << "\n" << "fitness: " << population.at(i)->getFitness() << endl;
    }
    cout << "Najlepszy osobnik: " << getBestFound()->getFitness();
}

