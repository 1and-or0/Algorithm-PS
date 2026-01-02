#ifndef BITS_STD_H
#define BITS_STD_H
#include <bits/stdc++.h>

using namespace std;
#endif // !BITS_STD_H

static int binary_search_iterative(int arr[], int target, int start, int end);

static int binary_search_recursive(int arr[], int target, int start, int end);


int main() //_ex_binary_search
{
	const int len = 13;
	int arr[len] = { 1, 3, 4, 5, 7, 8, 9, 11, 12, 14, 16, 18, 20 };

	int n;
	cin >> n;

	int result = 0;
	result = binary_search_iterative(arr, n, 0, len - 1);
	if (result == -1)
		cout << n << "이 리스트에 없습니다" << endl;
	else
		cout << n << "이 리스트에 있습니다" << endl;

	result = binary_search_recursive(arr, n, 0, len - 1);
	if (result == -1)
		cout << n << "이 리스트에 없습니다" << endl;
	else
		cout << n << "이 리스트에 있습니다" << endl;

	return EXIT_SUCCESS;
}

static int binary_search_iterative(int arr[], int target, int start, int end)
{
	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (arr[mid] == target)
			return mid;
		else if (arr[mid] > target)
			end = mid - 1;
		else if (arr[mid] < target)
			start = mid + 1;
	}

	return -1;
}

static int binary_search_recursive(int arr[], int target, int start, int end)
{
	if (start > end)
		return -1;

	int mid = (start + end) / 2;

	if (arr[mid] == target)
		return mid;
	else if (arr[mid] > target)
		return binary_search_recursive(arr, target, start, mid - 1);
	else if (arr[mid] < target)
		return binary_search_recursive(arr, target, mid + 1, end);

	return -1;
}
