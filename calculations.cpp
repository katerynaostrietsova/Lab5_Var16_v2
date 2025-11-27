#include "calculations.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <syncstream>

using namespace std;

static void simulate_work(const string& name, chrono::seconds duration)
{
    
    this_thread::sleep_for(duration);

    osyncstream out(cout);
    out << name << endl;
}

void slow(const string& name)
{
    simulate_work(name, chrono::seconds(7));
}

void quick(const string& name)
{
    simulate_work(name, chrono::seconds(1));
}

void taskA()
{
    slow("A");
}

void taskB()
{
    quick("B");
}

void taskC()
{
    slow("C");
}

void taskD1()
{
    quick("D1");
}

void taskD2()
{
    quick("D2");
}

void taskF1()
{
    quick("F1");
}

void taskF2()
{
    quick("F2");
}
