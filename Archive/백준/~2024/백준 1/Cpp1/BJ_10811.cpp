#ifndef BITS_STDC_H10811
#define BITS_STDC_H10811
#include <bits/stdc++.h>
using namespace std;
#endif // !BITS_STDC_H10811

int main_bj_10811()
{
	int n, m;
	cin >> n >> m;

	int* p_a = new int[n];

	for (int i = 0; i < n; ++i)
	{
		p_a[i] = i + 1;
	}
	
	float i1, i2;
	for (int i = 0; i < m; ++i)
	{
		cin >> i1 >> i2;
		i1 -= 1;  // 0 2   
		i2 -= 1;  // 3 3   2.5
		for (int j = i1; j < i1 + (i2 - i1)/2; ++j)
		{
			swap(p_a[j], p_a[(int)i1 + (int)i2 - j]);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << p_a[i] << ' ';
	}
	delete[] p_a;

	return EXIT_SUCCESS;
}