#ifndef BITS_STD_H
#define BITS_STD_DH
#include <bits/stdc++.h>
using namespace std;

#endif // !BITS_STD_H
static bool compare(int a, int b)
{
	return a > b;
}
int main()
{
	srand(time(NULL));
	int n, k;
	cin >> n >> k;

	vector<int> a, b;

	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}

	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		b.push_back(x);
	}

	sort(a.begin(), a.end());
	sort(a.begin(), a.end(), compare);

	for (int i = 0; i < k; ++i)
	{
		if (a[i] < b[i])
			swap(a[i], b[i]);
		else
			break;
	}

	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += a[i];
	}
	cout << sum << endl;

	return EXIT_SUCCESS;
}