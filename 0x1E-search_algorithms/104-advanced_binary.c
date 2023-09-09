#include <stdio.h>
#include "search_algos.h"

/**
 * advanced_binary_recursive - Recursively search for the value in the array.
 * @array: A pointer to the first element of the array to search in.
 * @start: The starting index of the subarray.
 * @end: The ending index of the subarray.
 * @value: The value to search for.
 *
 * Return: The index where 'value' is located within the subarray,
 *         or -1 if 'value' is not found.
 */
int advanced_binary_recursive(int *array, size_t start, size_t end, int value)
{
    size_t mid;

    if (start > end)
        return (-1);

    mid = (start + end) / 2;

    printf("Searching in array: ");
    for (size_t i = start; i <= end; i++)
    {
        printf("%d", array[i]);
        if (i < end)
            printf(", ");
    }
    printf("\n");

    if (array[mid] == value)
    {
        if (mid == start || array[mid - 1] != value)
            return (mid);
        else
            return advanced_binary_recursive(array, start, mid, value);
    }
    else if (array[mid] < value)
        return advanced_binary_recursive(array, mid + 1, end, value);
    else
        return advanced_binary_recursive(array, start, mid - 1, value);
}

/**
 * advanced_binary - Searches for a value in a sorted array using
 *                   advanced binary search.
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index where 'value' is located, or -1 if 'value' is not found
 *         or 'array' is NULL.
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return (-1);

    return advanced_binary_recursive(array, 0, size - 1, value);
}

