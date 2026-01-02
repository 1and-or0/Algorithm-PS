#ifndef BJ_2805_CPP
#define BJ_2805_CPP
#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
#endif // !BJ_2805_CPP

// height of saw
long long myFunction(const int h, const int* p_a, int len)
{
	long long result = 0;
	for (int i = 0; i < len; ++i)
	{
		result += (h < p_a[i]) ? (p_a[i] - h) : 0;
	}
	return result;
}

int main()
{
	fastio;
	int n, m;
	cin >> n >> m;
	int* p_arr = new int[n];
	int hi = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> p_arr[i];
		hi = hi < p_arr[i] ? p_arr[i] : hi;
	}

	int lo = 0;
	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;

		if (myFunction(mid, p_arr, n) >= m)
			lo = mid;
		else
			hi = mid;
	}

	cout << lo;

	return EXIT_SUCCESS;
}