#include "binarysearch.h"

BinarySearch::BinarySearch(int size) : ArraySearch(size)
{

}

BinarySearch::~BinarySearch()
{

}

/**
 * Conducts a binary search for the specified key.
 * @brief BinarySearch::search
 * @param key
 * @return
 */
int BinarySearch::search(unsigned int key)
{
    return binarySearch(array, key, 0, arraySize);
}

/**
 * Iterative binary search.
 * @brief binarySearch
 * @param array
 * @param key
 * @param minIndex
 * @param maxIndex
 * @return
 */
int BinarySearch::binarySearch(unsigned int * array, unsigned int key, unsigned int minIndex, unsigned int maxIndex)
{
    while (minIndex < maxIndex)
    {
        int midIndex = minIndex + ((maxIndex - minIndex) / 2);
        if (array[midIndex] == key)
        {
            return midIndex;
        }
        else if (array[midIndex] < key)
        {
            minIndex = midIndex + 1;
        }
        else
        {
            maxIndex = midIndex - 1;
        }
    }
    return KEY_NOT_FOUND;

}

