#include "sort.h"

/**
* lomuto_partition - Partitions the array using Lomuto scheme
* @array: Array to sort
* @low: Starting index of the partition
* @high: Ending index of the partition (pivot)
* @size: Size of the array
*
* Return: The index of the pivot after partition
*/
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];

	ssize_t i = low - 1;
	ssize_t j;
	int tmp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
* quick_sort_rec - Recursively sorts the array using Quick sort
* @array: Array to sort
* @low: Starting index
* @high: Ending index
* @size: Size of the array
*/
void quick_sort_rec(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		quick_sort_rec(array, low, p - 1, size);
		quick_sort_rec(array, p + 1, high, size);
	}
}

/**
* quick_sort - Sorts an array of integers in ascending order
*              using the Quick sort algorithm (Lomuto scheme)
* @array: Array to sort
* @size: Number of elements in array
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}
