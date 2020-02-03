#include <stdio.h>
#include "sort.h"


/**
 * swap - swap between two integer ponter values
 * @v1: first int pointer
 * @v2: second int pointer
 *
 * Return: nothing
 * On error: nothing
 */
void swap(int *v1, int *v2)
{
	int dum = *v1;
	*v1 = *v2;
	*v2 = dum;
}


/**
 * selection_sort - sorts an array of integers in ascending order using
 * the Selection sort algorithm
 * @array: array to sort
 * @size: size of the array
 *
 * Return: nothing
 * On error: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, k = 0, low = 1;
	int *org = array;

	if (!array || !*array)
		return;

	for (; k < size; k++)
	{
		for (i = k, low = k; i < size; i++)
			if (array[i] < array[low])
				low = i;

		if (k != low)
		{
			swap(&array[k], &array[low]);
			print_array(org, size);
		}
	}
}
