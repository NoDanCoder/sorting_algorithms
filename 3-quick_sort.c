#include <stdio.h>
#include "sort.h"


/**
 * swap - swap to values
 * @array: buffer where is stored the value
 * @i: first value
 * @j: second one
 * @size: size of partition to print
 *
 * Return: nothing
 * On error: nothing
 */
void swap(int *array, int i, int j, int size)
{
	int tmp;

	if (array[i] != array[j])
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
}


/**
 * partition - sorts a partition
 * @array: array to be sorted
 * @min: start position of partition
 * @max: max position of partition
 * @size: size of partition
 *
 * Return: new Pivot to make a partition
 * On error: nothing
 */
int partition(int *array, int min, int max, size_t size)
{
	int i = min, j, pivot  = array[max];

	for (j = min; j <= max; j++)
		if (array[j] < pivot)
			swap(array, i, j, size), i++;

	swap(array, i, max, size);
	return (i);
}


/**
 * callerSort - this makes a call to sort on every partition
 * @array: array to be sorted
 * @min: start position of partition
 * @max: max position of partition
 * @size: size of partition
 *
 * Return: nothing
 * On error: nothing
 */
void callerSort(int *array, int min, int max, size_t size)
{
	int p;

	if (min < max)
	{
		p = partition(array, min, max, size);
		callerSort(array, min, p - 1, size);
		callerSort(array, p + 1, max, size);
	}
}


/**
 * quick_sort -  sorts an array of integers in ascending order using the
 * Quick sort algorithm Lomuto partition scheme
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 * On error: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (size >= 2)
		callerSort(array, 0, size - 1, size);
}
