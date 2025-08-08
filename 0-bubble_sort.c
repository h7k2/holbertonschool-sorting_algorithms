#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - Sorts an array using Bubble Sort
 * @array: pointer to the array
 * @size: number of elements
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
    int i, j;
    int tmp;
    int swapped = 0;

    if (size <= 1)
        return;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;

                print_array(array, size);
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}
