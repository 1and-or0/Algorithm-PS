#ifndef BJ_15829_CPP
#define BJ_15829_CPP
#include <bits/stdc++.h>
using namespace std;
#endif // !BJ_15829_CPP

int main_BJ_15829_CPP()
{
	const long long r = 31;
	long long rate = 1;
	const long long m = 1234567891;
	int n;
	cin >> n;
	char st[51];
	cin >> st;

	long long result = 0;
	for (int i = 0; i < n; ++i)
	{
		result += (long long)(st[i] - '`') * rate;
		result %= m;
		rate *= r;
		rate %= m;
	}
	cout << result << endl;
	return EXIT_SUCCESS;
}