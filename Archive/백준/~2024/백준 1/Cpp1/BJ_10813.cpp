#ifndef BITS_STDC_H10813
#define BITS_STDC_H10813
#include <bits/stdc++.h>
using namespace std;

#endif // !BITS_STDC_H10813


int main_bj_10813()
{
	int n, m;
	cin >> n >> m;

	int* p_a = new int[n];

	for (int i = 0; i < n; ++i)
	{
		p_a[i] = i+1;
	}
	
	int n1, n2;
	for (int j = 0; j < m; ++j)
	{
		cin >> n1 >> n2;
		swap(p_a[n1-1], p_a[n2-1]);
	}

	for (int i = 0; i < n; ++i)
	{
		cout << p_a[i] << ' ';
	}

	delete[] p_a;

	return EXIT_SUCCESS;
}