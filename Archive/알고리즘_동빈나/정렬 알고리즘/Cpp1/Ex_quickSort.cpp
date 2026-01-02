#ifndef BITS_STD_H
#define BITS_STD_H
#include <bits/stdc++.h>
using namespace std;

#endif // !BITS_STD_H
static void quickSort(int arr[], int start, int end);

int main_ex_quick_sort()
{
	const int len = 10;
	int arr[len] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

	quickSort(arr, 0, len - 1);

	for (int i = 0; i < len; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	return EXIT_SUCCESS;
}

static void quickSort(int arr[], int start, int end)
{
	if (start >= end)
		return;

	int pivot_i = start;
	int left_i = start + 1;
	int right_i = end;

	while (left_i <= right_i)
	{

		while (arr[left_i] < arr[pivot_i])
			left_i += 1;

		while (arr[right_i] > arr[pivot_i])
			right_i -= 1;

		if (left_i <= right_i)
		{
			swap(arr[left_i], arr[right_i]);
		}
		else
		{
			swap(arr[pivot_i], arr[right_i]);
		}
	}

	quickSort(arr, start, right_i - 1);
	quickSort(arr, right_i + 1, end);
}