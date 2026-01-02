// 선택 정렬 시간복잡도: O(N^2)
#ifndef BITS_STDC_H
#define BITS_STDC_H
#include <bits/stdc++.h>
#define LEN 10

using namespace std;
#endif // !BITS_STDC_H

int main_ex_selec_sort()
{
	int arr[LEN] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

	for (int i = 0; i < LEN; ++i)
	{
		int min_index = i;
		for (int j = i + 1; j < LEN; ++j)
		{
			if (arr[min_index] > arr[j])
			{
				min_index = j;
			}
		}

		int temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;

		// swap(arr[i], arr[min_index])
	}
	
	for (int i = 0; i < LEN; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	return EXIT_SUCCESS;
}