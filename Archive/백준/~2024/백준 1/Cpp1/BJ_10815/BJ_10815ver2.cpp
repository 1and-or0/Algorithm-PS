#ifndef BJ_10815_CPP_VER2
#define BJ_10815_CPP_VER2
#include <bits/stdc++.h>
using namespace std;
#endif // !BJ_10815_CPP_VER2

int main()
{
	int n, m;

	int* arr1 = new int[10000001];
	int* arr2 = new int[10000000];
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		if (temp < 0)
		{
			arr2[10000000 + temp] = 1;
		}
		else
		{
			arr1[temp] = 1;
		}
	}

	cin >> m;
	int* inputs = new int[m];
	for (int i = 0; i < m; ++i)
		cin >> inputs[i];

	for (int i = 0; i < m; ++i)
	{
		if (inputs[i] < 0)
			cout << ((arr2[10000000 + inputs[i]]) == 1) << ' ';
		else
			cout << (arr1[inputs[i]] == 1) << ' ';
	}
	
	delete[] arr1;
	delete[] arr2;
	delete[] inputs;
	return EXIT_SUCCESS;
}