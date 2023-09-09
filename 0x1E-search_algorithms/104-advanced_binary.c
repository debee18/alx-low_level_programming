<<<<<<< HEAD
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

=======
#include "search_algos.h"

int binary_search_recursion(int *array, int value,
			    size_t low, size_t high);

/**
 * binary_search_recursion - helper to `advanced_binary`, recursively searches
 * for a value in an integer array
 * @array: pointer to first element of array to seach
 * @value: value to search for
 * @low: starting index in array
 * @high: ending index in array
 *
 * Return: index containing `value`, or -1 if `value` not found or
 * `array` is NULL
 */
int binary_search_recursion(int *array, int value,
			    size_t low, size_t high)
{
	size_t mid, i;

	if (!array)
		return (-1);

	mid = (low + high) / 2;
	printf("Searching in array: ");
	for (i = low; i <= high; i++)
		printf("%i%s", array[i], i == high ? "\n" : ", ");

	if (array[low] == value)
		return ((int)low);

	if (array[low] != array[high])
	{
		if (array[mid] < value)
			return (binary_search_recursion(array, value,
							mid + 1, high));
		if (array[mid] >= value)
			return (binary_search_recursion(array, value,
							low, mid));
	}

	return (-1);
}

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * using a binary search algorithm. Unlike `binary_search`, consistently
 * returns first appearance of `value` in array
 * @array: pointer to first element of array to search
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: first index containing `value`, or -1 if `value` not found or
 * `array` is NULL
 */

int advanced_binary(int *array, size_t size, int value)
{
	size_t low = 0;
	size_t high = size - 1;

	if (!array)
		return (-1);

	return (binary_search_recursion(array, value, low, high));
}
>>>>>>> 0e4e3df08bd28979b0a7f582336ecb9372b62c19
