#include <bits/stdc++.h>
using namespace std;
#define N_BORDER 15

int main()
{
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	
	int dp[N_BORDER + 1] = { 0 };
	dp[0] = 2;

	int result[N_BORDER + 1] = { 0 };
	result[0] = pow(dp[0], 2);

	for (int i = 1; i < n+1; i++)
	{
		dp[i] = 2 * dp[i - 1] - 1;
		result[i] = pow(dp[i], 2);
	}

	cout << result[n] << "\n";

	return 0;
}