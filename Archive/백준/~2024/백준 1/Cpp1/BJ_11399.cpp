#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;
	int arr[1000] = { 0 };

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	sort(arr, arr+n);

	int temp = 0;
	int sum_result = 0;
	int result[1000] = { 0 };
	for (int i = 0; i < n; ++i)
	{
		temp += arr[i];
		result[i] = temp;
		sum_result += result[i];
	}

	cout << sum_result;
	return 0;
}