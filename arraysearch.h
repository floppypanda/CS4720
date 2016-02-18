#ifndef ARRAYSEARCH_H
#define ARRAYSEARCH_H

#ifndef CSTDLIB_H
#define CSTDLIB_H
#include <cstdlib>
#endif

#ifndef TIME_H
#define TIME_H
#include <time.h>
#endif

#define KEY_NOT_FOUND -1

class ArraySearch
{
protected:
    unsigned int * array;
    unsigned int arraySize;
    unsigned int * generateRandomizedArray(unsigned int arraySize);
    static int quickSortCompare(const void * first, const void * second);
public:
    virtual int search(unsigned int key) = 0;
    unsigned int getArrayTestValue();
    void resetRandomness();
    ArraySearch(unsigned int size);
    ~ArraySearch();
};

#endif // ARRAYSEARCH_H
