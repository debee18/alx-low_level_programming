#include <stdio.h>
#include "search_algos.h"

/**
 * exponential_search - Searches for a value in a sorted array using
 *                      Exponential Search.
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index where 'value' is located, or -1 if 'value' is not found
 *         or 'array' is NULL.
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t bound = 1;
    size_t prev = 0;

    if (array == NULL)
        return (-1);

    while (bound < size && array[bound] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
        prev = bound;
        bound *= 2;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev, bound);

    if (bound < size)
        return binary_search(array, prev, bound, value);

    return binary_search(array, prev, size, value);
}

/**
 * binary_search - Searches for a value in a sorted array using Binary Search.
 * @array: A pointer to the first element of the array to search in.
 * @start: The starting index of the subarray.
 * @end: The ending index of the subarray.
 * @value: The value to search for.
 *
 * Return: The index where 'value' is located within the subarray,
 *         or -1 if 'value' is not found.
 */
int binary_search(int *array, size_t start, size_t end, int value)
{
    size_t left = start, right = end - 1, mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
        printf("Searching in array: ");
        for (size_t i = left; i <= right; i++)
        {
            printf("%d", array[i]);
            if (i < right)
                printf(", ");
        }
        printf("\n");

        if (array[mid] == value)
            return (mid);
        else if (array[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return (-1);  // Value not found
}

