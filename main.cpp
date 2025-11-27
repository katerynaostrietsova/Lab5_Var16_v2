#include <iostream>
#include "scheduler.h"

using namespace std;

int main()
{
   
    cout << "Starting computations for project (variant #16)..." << endl;

    try
    {
        work();
    }
    catch (const exception& ex)
    {
        cerr << "Unhandled exception: " << ex.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "Unknown error occurred." << endl;
        return 1;
    }

    return 0;
}
