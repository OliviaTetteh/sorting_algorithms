#include "sort.h"

/**
 * int_swap - It swaps two integers in an array.
 * @o: first integer to be swapped.
 * @b: second integer to be swapped.
 */
void int_swap(int *o, int *b)
{
	int tmp;

	tmp = *o;
	*o = *b;
	*b = tmp;
}

/**
 * bubble_sort - This sorts array of integers in ascending order.
 * @array: The array of integers to be sorted.
 * @size: size of array.
 *
 * Description: Array after each swap is printed.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubblesort = false;

	if (array == NULL || size < 2)
		return;

	while (bubblesort == false)
	{
		bubblesort = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				int_swap(array + i, array + i + 1);
				print_array(array, size);
				bubblesort = false;
			}
		}
		len--;
	}
}
