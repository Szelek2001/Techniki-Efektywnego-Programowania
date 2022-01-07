//
// Created by Rafał on 30.12.2021.
//

#include <string>
#include <iostream>
#include "Max3SatProblem.h"
#include "Individual.h"

int main() {
    Max3SatProblem problem;

    problem.load("m3s_100_2.txt");
    // std::cout << "\nLiczba zmiennych: " << problem.getNumberOfVariables();

    bool *testSolution{new bool[18]{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    bool *testSolution1{new bool[18]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    //problem.printInputNumbers();
    //std::cout << "\nOstateczny wynik compute: " << problem.compute(testSolution);



    Individual ind1(testSolution, 18);
    Individual ind2(testSolution1,18);
    // cout << ind1.calculateFitness(problem.compute(testSolution), problem.getNumberOfClauses());

//    for (int i = 0; i < 18; i++) {
//        cout << testSolution[i];
//    }
//    cout << "\n";
//    ind1.mutation(0.1);
//
//    for (int i = 0; i < 18; i++) {
//        cout << testSolution[i];
//    }
    Individual* ind3 = ind1.crossover(&ind2,0.005);
    for (int i = 0; i < 18; i++) {
        cout << testSolution[i];
    }
    cout << endl;
    for (int i = 0; i < 18; i++) {
        cout << testSolution1[i];
    }
    cout << endl;
    for (int i = 0; i < 18; i++) {
        cout << ind3->getGenotype()[i];
    }



    delete[] testSolution;
    delete[] testSolution1;
}
