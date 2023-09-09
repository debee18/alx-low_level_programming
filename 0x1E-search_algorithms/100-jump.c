#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array using Jump Search.
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index where 'value' is located, or -1 if 'value' is not found
 *         or 'array' is NULL.
 */
int jump_search(int *array, size_t size, int value)
{
    size_t step = sqrt(size);
    size_t prev = 0;

    if (array == NULL)
        return (-1);

    while (array[prev] < value && prev < size)
    {
        printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);

        prev += step;
    }

    size_t min = prev - step;
    size_t max = prev < size ? prev : size - 1;

    printf("Value found between indexes [%lu] and [%lu]\n", min, max);

    for (size_t i = min; i <= max; i++)
    {
        printf("Value checked array[%lu] = [%d]\n", i, array[i]);

        if (array[i] == value)
            return (i);
    }

    return (-1);  // Value not found
}

