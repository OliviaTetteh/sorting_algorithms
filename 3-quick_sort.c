#include "sort.h"

void int_swap(int *o, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * int_swap - it swaps two integers.
 * @o: first integer to swap.
 * @b: second integer to swap.
 */
void int_swap(int *o, int *b)
{
	int tmp;

	tmp = *o;
	*o = *b;
	*b = tmp;
}

/**
 * lomuto_partition - subset of integers according to
 *                    the lomuto partition scheme.
 * @array: array of integers.
 * @size: size of the array.
 * @start: starting index.
 * @end: ending index.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int start, int end)
{
	int *pivot, top, down;

	pivot = array + end;
	for (top = down = start; down < end; down++)
	{
		if (array[down] < *pivot)
		{
			if (top < down)
			{
				int_swap(array + down, array + top);
				print_array(array, size);
			}
			top++;
		}
	}

	if (array[top] > *pivot)
	{
		int_swap(array + top, pivot);
		print_array(array, size);
	}

	return (top);
}

/**
 * lomuto_sort - sorting algorithm through recursion.
 * @array: array of integers.
 * @size: ize of the array.
 * @start: starting of the array to order.
 * @end: ending of the array to order.
 *
 * Description: The Lomuto partition scheme is implemented.
 */
void lomuto_sort(int *array, size_t size, int start, int end)
{
	int half;

	if (end - right > 0)
	{
		half = lomuto_partition(array, size, start, end);
		lomuto_sort(array, size, start, half - 1);
		lomuto_sort(array, size, half + 1, end);
	}
}

/**
 * quick_sort - This sorts integers in ascending
 *              order by using the quicksort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: It Prints the array by using lomuto partition.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
