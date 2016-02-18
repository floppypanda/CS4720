#include <QCoreApplication>
#include <iostream>
#include <chrono>
#include "binarysearch.h"
#include "ternarysearch.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    BinarySearch * binarySearch = NULL;
    TernarySearch * ternarySearch = NULL;
    unsigned int numArrayElements = 5000;
    unsigned int numTests = 10000000;

    for (numArrayElements; numArrayElements <= 100000; numArrayElements += 5000)
    {
        cout << "Test - Number of Array Elements: " << numArrayElements << endl;

        /*Releasing binary search from
         *previous iteration.*/
        if (binarySearch != NULL)
        {
            delete binarySearch;
        }

        /*Releasing ternary search object
         * from previous iteration.*/
        if (ternarySearch != NULL)
        {
            delete ternarySearch;
        }

        /*Initializing objects.*/
        binarySearch = new BinarySearch(numArrayElements);
        ternarySearch = new TernarySearch(numArrayElements);

        /*Running binary search test.*/

        cout << "Binary Search Test: " << endl;

        auto start = chrono::steady_clock::now();

        for (unsigned int index = 0; index < numTests; ++index)
        {
            //Retrieving a test value.
            int testValue = binarySearch->getArrayTestValue();

            //Running binary search.
            binarySearch->search(testValue);

            //Refreshing randomness.
            if (index % 100 == 0)
            {
                binarySearch->resetRandomness();
            }
        }

        auto end = chrono::steady_clock::now();
        auto diff = (end - start);

        cout << "Time Taken: " << chrono::duration <double, milli> (diff).count() << " ms" << endl;

        /*Running ternary search test.*/

        cout << "Ternary Search Test: " << endl;

        start = chrono::steady_clock::now();

        for (unsigned int index = 0; index < numTests; ++index)
        {
            //Retrieving a test value.
            int testValue = ternarySearch->getArrayTestValue();

            //Running ternary search.
            ternarySearch->search(testValue);

            //Refreshing randomness
            if (index % 100 == 0)
            {
                ternarySearch->resetRandomness();
            }

        }

        end = chrono::steady_clock::now();
        diff = (end - start);

        cout << "Time Taken: " << chrono::duration <double, milli> (diff).count() << " ms" << endl;

    }

    /*Pausing so that all output may be viewed.*/
    cin.get();

    return a.exec();
}

