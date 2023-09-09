#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list using Linear Skip Search.
 * @list: A pointer to the head of the skip list to search in.
 * @value: The value to search for.
 *
 * Return: A pointer to the first node where 'value' is located, or NULL if
 *         'value' is not found or 'list' is NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *current = list, *prev = NULL;

    if (list == NULL)
        return (NULL);

    while (current->express != NULL && current->express->n < value)
    {
        prev = current;
        current = current->express;
        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev->index, current->index);

    while (prev != NULL && prev->index <= current->index)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
        if (prev->n == value)
            return (prev);
        prev = prev->next;
    }

    return (NULL);  // Value not found
}

