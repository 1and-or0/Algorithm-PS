#ifndef BJ_10773_CPP
#define BJ_10773_CPP
#include <bits/stdc++.h>
using namespace std;
#endif // !BJ_10773_CPP

int main_BJ_10773_CPP()
{
	int k;
	cin >> k;
	vector<int> v;
	for (int i = 0; i < k; ++i)
	{
		int now;
		cin >> now;
		if (now != 0)
		{
			v.push_back(now);
		}
		else
		{
			v.pop_back();
		}

	}
	long long result = 0;
	for (int i = 0; i < v.size(); ++i)
		result += v[i];
	cout << result << endl;

	return EXIT_SUCCESS;
}