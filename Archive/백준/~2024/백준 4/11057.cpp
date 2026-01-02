#include <iostream>
#include <cmath>
#include <string>
#define endl "\n"
using namespace std;

int n;
const int n_max = 1000;
int ans[n_max + 1][10] = {0};
const int mod_ = 10007;

int main()
{
	cin >> n;
	for (int i = 0; i < 10; i++)
	{
		ans[1][i] = 1;
	}

	for (int a_n = 2; a_n < n_max+1; a_n++)
	{
		ans[a_n][0] = ans[a_n - 1][0];
		for (int i = 1; i < 10; i++)
		{
			ans[a_n][i] = ans[a_n][i - 1] + ans[a_n - 1][i];
			ans[a_n][i] %= mod_;
		}
	}

	int ans_n = 0;
	for (int i = 0; i < 10; i++)
	{	
		ans_n += ans[n][i];
		ans_n %= mod_;
	}
	cout << ans_n << endl;

	return 0;
}