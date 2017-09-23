/*
 * permutation.c
 *
 * Generate a permutation of array (of integers) using recursion.
 */
#include <stdio.h>

int arr_data[] = { 1, 2, 3, 4 };
int arr_size = 4;

void print(int arr_data[], int arr_size) {
	int i;

	for (i = 0; i < arr_size; i++)
		printf("%d ", arr_data[i]);
	printf("\n");
}

void swap(int arr_data[], int idx_a, int idx_b) {
	int temp;

	temp = arr_data[idx_a];
	arr_data[idx_a] = arr_data[idx_b];
	arr_data[idx_b] = temp;
}

void handle(int arr_data[], int arr_size, int idx) {
	int i;

	/*
	 * When the swapped element reaches the end of array (which
	 * means swapped with itself), exit the recursion.
	 */
	if (idx == arr_size - 1) {
		print(arr_data, arr_size);
		return;
	}

	/*
	 * Swap arr_data[idx] with elements whose index is not smaller
	 * than idx. Operate in this way recursively.
	 */
	for (i = idx; i < arr_size; i++) {
		/* swap */
		swap(arr_data, idx, i);
		idx++;
		handle(arr_data, arr_size, idx);
		idx--;
		/* restore */
		swap(arr_data, idx, i);
	}
}

int main()
{
	int idx = 0;

	handle(arr_data, arr_size, idx);
	return 0;
}
