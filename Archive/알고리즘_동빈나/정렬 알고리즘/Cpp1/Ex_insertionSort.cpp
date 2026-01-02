// 삽입 정렬 시간복잡도: O(N^2), 선택 정렬보다 효율적
#ifndef BITS_STD_H
#define BITS_STD_H
#include <bits/stdc++.h>
using namespace std;
#endif // !BITS_STD_H

int main_ex_insert_sort()
{
	const int len = 10;
	int arr[len] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

	for (int i = 1; i < len; ++i)
	{
		for (int j = i; j > 0; --j)
		{
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
			else
				break;
		}
	}


	for (int i = 0; i < len; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;


	return EXIT_SUCCESS;
}