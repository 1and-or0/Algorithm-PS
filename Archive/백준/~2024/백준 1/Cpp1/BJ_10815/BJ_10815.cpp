#ifndef BJ_10815_CPP
#define BJ_10815_CPP
#include <bits/stdc++.h>
using namespace std;
#endif // !BJ_10815_CPP

int main_BJ_10815_CPP()
{
	int n, m;

	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr, arr + n);
	
	cin >> m;
	int* inputs = new int[m];
	for (int i = 0; i < m; ++i)
		cin >> inputs[i];

	int* result = new int[m];
	for (int i = 0; i < m; ++i)
	{
		int left = 0;
		int right = n - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (arr[mid] == inputs[i])
			{
				result[i] = 1;
				break;
			}
			else if (arr[mid] < inputs[i])
				left = mid + 1;
			else if (arr[mid] > inputs[i])
				right = mid - 1;
		}
		
		if (result[i] != 1)
			result[i] = 0;
		
	}

	for (int i = 0; i < m; ++i)
		cout << result[i] << ' ';

	delete[] arr;
	delete[] inputs;
	delete[] result;
	return EXIT_SUCCESS;
}