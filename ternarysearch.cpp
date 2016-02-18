#include "ternarysearch.h"

TernarySearch::TernarySearch(int size) : ArraySearch(size)
{

}

TernarySearch::~TernarySearch()
{

}

/**
 * Conducts a ternary search for the specified key.
 * @brief TernarySearch::search
 * @param key
 * @return
 */
int TernarySearch::search(unsigned int key)
{
    return ternarySearch(array, key, 0, arraySize);
}

/**
 * Iterative ternary search.
 * @brief TernarySearch::ternarySearch
 * @param array
 * @param leftIndex
 * @param rightIndex
 * @param absolutePrecision
 * @return
 */
int TernarySearch::ternarySearch(unsigned int * array, unsigned int key, unsigned int minIndex, unsigned int maxIndex)
{
   while (minIndex <= maxIndex)
   {
        int lowerThirdMax = minIndex + (maxIndex - minIndex)/3;
        int upperThirdMin = minIndex + (2 * (maxIndex - minIndex))/3;

        if (array[lowerThirdMax] == key)
        {
            return lowerThirdMax;
        }
        else if (array[upperThirdMin] == key)
        {
            return upperThirdMin;
        }
        else if (key < array[lowerThirdMax])
        {
            maxIndex = lowerThirdMax - 1;
        }
        else if (key > array[upperThirdMin])
        {
            minIndex = upperThirdMin + 1;
        }
        else
        {
            minIndex = lowerThirdMax + 1;
            maxIndex = upperThirdMin - 1;
        }
   }
   return -1;
}

