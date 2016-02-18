#include "arraysearch.h"

/*Public Methods*/

/*Constructor*/

ArraySearch::ArraySearch(unsigned int size)
{
    /*Generating an array of the specified
     * size with randomized data.*/
    array = generateRandomizedArray(size);
    arraySize = size;
}

/*Deconstructor*/

ArraySearch::~ArraySearch()
{
    delete[] array;
}

/*Private Methods*/

/**
 * Generates a randomized array of the specified size.
 * @brief ArraySearch::generateRandomizedArray
 * @param arraySize
 * @return int *
 */
unsigned int * ArraySearch::generateRandomizedArray(unsigned int arraySize)
{
    unsigned int * generatedArray = NULL;
    int (*sortFunc)(const void*,const void*) = &quickSortCompare;

    //Seeding the random number generator.
    srand(time(NULL));

    //Allocate memory for the array.
    generatedArray = new unsigned int[arraySize];

    /*Looping through the array and filling it
     * with randomized values.*/
    for (unsigned int index = 0; index < arraySize; ++index)
    {
        /*We want a range of values larger than the size
         * of the array but not too large.*/
        generatedArray[index] = (rand() % (arraySize * 2));
    }

    //After the array has been initialized, it must be sorted.
    qsort((void *) generatedArray, (size_t) arraySize, sizeof(unsigned int), sortFunc);

    return generatedArray;
}

/**
 * Comparison function for quicksort.
 * @brief ArraySearch::quickSortCompare
 * @param first
 * @param second
 */
int ArraySearch::quickSortCompare(const void * first, const void * second)
{
    unsigned int firstValue = *((unsigned int *) first);
    unsigned int secondValue = *((unsigned int *) second);

    if (firstValue < secondValue)
    {
        return -1;
    }
    else if (firstValue == secondValue)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}

/**
 * Returns an existing value from the array
 * for testing successful retrieval time.
 * @brief ArraySearch::getArrayTestValue
 * @return
 */
unsigned int ArraySearch::getArrayTestValue()
{
    //Selects a random test value from the array.
    return array[(rand() % arraySize) - 1];
}

/**
 * Allows the random number generator to
 * be reseeding in order to preserve randomness.
 * @brief ArraySearch::resetRandomness
 */
void ArraySearch::resetRandomness()
{
    srand(time(NULL) + 123);
}
