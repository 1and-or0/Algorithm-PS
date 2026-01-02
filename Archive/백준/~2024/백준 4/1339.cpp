#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#define endl "\n"
using namespace std;

int value_of_num['Z' - 'A' + 1] = {0};
const int max_n = 10;
char input[max_n][8+2] = {0};
int n;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int ii = 0; ii < strlen(input[i]); ii++)
		{
			value_of_num[(input[i][ii]-'A')] += pow(10, strlen(input[i]) - 1 - ii);
		}
	}

	sort(begin(value_of_num), end(value_of_num), greater<int>());
	
	int ans = 0, temp = 9;
	int i = 0;
	for (int i = 0; i < size(value_of_num); i++)
	{
		//cout << value_of_num[i] << endl;
		ans += value_of_num[i] * temp--;
	}
	cout << ans << endl;
	
	return 0;
}