#include<stdio.h>
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
 * bubble_sort - sorts an array of integers in ascending order using the
 * Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 * On error: doesn't modify nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	int isSwapped = 0;

	if (!array)
		return;

	for (; i < (size - 1); i++)
		if (array[i] > array[i + 1])
		{
			swap(array + i, array + (i + 1));
			isSwapped = 1;
			print_array(array, size);
		}

	if (isSwapped)
		bubble_sort(array, size);
}
