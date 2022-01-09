
//
// Created by Rafał on 30.12.2021.
//


#include <iostream>

#include "Max3SatProblem.h"
#include "Optimizer.h"
#include "Timer.h"



using namespace std;

#define dMAX_TIME 1 * 60

void vRunExperiment(Max3SatProblem* pcProblem)
{
    try
    {
        TimeCounters::CTimeCounter c_time_counter;

        double d_time_passed;

        Optimizer optimizer(pcProblem);

        c_time_counter.vSetStartNow();


        optimizer.initialize();

        c_time_counter.bGetTimePassed(&d_time_passed);
        int s10s = 0;

        while (d_time_passed <= dMAX_TIME)
        {
            optimizer.runIteration();
            optimizer.getBestFound();

            c_time_counter.bGetTimePassed(&d_time_passed);

            if(d_time_passed>s10s){
               optimizer.printbest();
               std::cout<<" Po: " << s10s<<"\n";
            s10s+=10;
            }

        }
        optimizer.print();

        //while (d_time_passed <= MAX_TIME)
    }//try
    catch (exception& c_exception)
    {
        cout << c_exception.what() << endl;
    }//catch (exception &c_exception)
}

int main() {
    Max3SatProblem problem;


    problem.load("m3s_350_0.txt");

    vRunExperiment(&problem);



}
