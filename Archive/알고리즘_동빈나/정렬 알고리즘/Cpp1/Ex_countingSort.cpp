#ifndef BITS_STD_H
#define BITS_STD_H
#include <bits/stdc++.h>
using namespace std;

#endif // !BITS_STD_H

int main_ex_counting_sort()
{
	const int len = 15;
	const int max_val = 9;
	int arr[len] = { 7, 5, 9, 0, 3, 1, 6, 2, 9, 1, 4, 8, 0, 5, 2 };

	int count[max_val + 1] = {};

	for (int i = 0; i < len; ++i)
	{
		count[arr[i]] += 1;
	}
	
	// count의 모든 인덱스에 접근
	for (int i = 0; i < max_val + 1; ++i)
	{
		for (int j = 0; j < count[i]; ++j)
		{
			cout << i << ' ';
		}
	}

	return EXIT_SUCCESS;
}