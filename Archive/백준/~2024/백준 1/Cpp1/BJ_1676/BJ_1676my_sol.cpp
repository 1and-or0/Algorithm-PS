#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;
	int num_tow = 0, num_five = 0;

	for (int i = 1; i < n + 1; ++i)
	{
		int temp = i;
		while (temp % 2 == 0)
		{
			temp = temp / 2;
			num_tow += 1;
		}

		while (temp % 5 == 0)
		{
			temp = temp / 5;
			num_five += 1;
		}
	}

	cout << num_five;

	return 0;
}