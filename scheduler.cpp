#include "scheduler.h"
#include "calculations.h"
#include <iostream>
#include <future>
#include <chrono>

using namespace std;

void work()
{
    using namespace chrono;
    steady_clock::time_point start = steady_clock::now();

    future<void> futureA = async(launch::async, taskA);
    future<void> futureC = async(launch::async, taskC);

    taskB();
    taskD2();
    taskF2();

    futureA.get();
    futureC.get();

    taskD1();
    taskF1();

    steady_clock::time_point finish = steady_clock::now();
    auto elapsed = duration_cast<seconds>(finish - start).count();

    cout << "Total elapsed time: " << elapsed << " seconds" << endl;
    cout << "Work is done!" << endl;
}
