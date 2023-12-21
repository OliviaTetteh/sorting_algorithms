#include "sort.h"

/**
 * int_swap - This swaps two integers.
 * @o: first integer to be swapped.
 * @b: second integer to be swapped.
 */
void swap_ints(int *o, int *b)
{
	int tmp;

	tmp = *o;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - It sorts integers in ascending order by using
 *                  the selection sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: It prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *sec;
	size_t c, k;

	if (array == NULL || size < 2)
		return;

	for (c = 0; c < size - 1; c++)
	{
		sec = array + c;
		for (k = c + 1; k < size; k++)
			sec = (array[k] < *sec) ? (array + k) : sec;

		if ((array + c) != sec)
		{
			int_swap(array + c, sec);
			print_array(array, size);
		}
	}
}
