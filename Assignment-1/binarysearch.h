#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include "arraysearch.h"

class BinarySearch : public ArraySearch
{
public:
    BinarySearch(int size);
    virtual ~BinarySearch();
    virtual int search(unsigned int key);
    int binarySearch(unsigned int * array, unsigned int key, unsigned int minIndex, unsigned int maxIndex);
};

#endif // BINARYSEARCH_H
