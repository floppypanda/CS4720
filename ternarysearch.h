#ifndef TERNARYSEARCH_H
#define TERNARYSEARCH_H

#include "arraysearch.h"

class TernarySearch : public ArraySearch
{
public:
    TernarySearch(int size);
    virtual ~TernarySearch();
    virtual int search(unsigned int key);
    int ternarySearch(unsigned int * array, unsigned int key, unsigned int minIndex, unsigned int maxIndex);
};

#endif // TERNARYSEARCH_H
