#include "sort.h"

/**
 * swap_ints - function to swap two integers in an array.
 * @o: first integer.
 * @b: second integer.
 */
void swap_ints(int *o, int *b)
{
	int tmp;

	tmp = *o;
	*o = *b;
	*b = tmp;
}

/**
 * shell_sort - function to Sort an array of integers in ascending
 *              order by shell sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, c, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (c = gap; c < size; c++)
		{
			j = c;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ints(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
