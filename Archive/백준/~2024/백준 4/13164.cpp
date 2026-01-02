#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

int n, k;
vector<int> v(300000, -1);
vector<pair<int, int>> cost;

bool MyComp(const pair<int,int> &a, const pair<int,int> &b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		if (i != 0)
		{
			cost.push_back({ i - 1, v[i] - v[i - 1] });
		}
	}
	sort(cost.begin(), cost.end(), MyComp);

	int ans = 0;
	for (int i = --k; i < cost.size(); i++)
	{
		ans += cost[i].second;
	}
	cout << ans << endl;

	return 0;
}