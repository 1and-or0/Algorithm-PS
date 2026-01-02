#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int n, k;
const int n_max = 10000, k_max = 1000, pos_max = 1000000;
vector<int> sensor(10000, -1);
vector<int> dist;

int main() // 1 6 9 3 6 7   -    5    - 1 3  6 7
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> sensor[i];
	}
	sort(sensor.begin(), sensor.begin()+n);
	
	for (int i = 1; i < n; i++)
	{
		if (sensor[i] == sensor[i - 1])
			continue;

		dist.push_back(sensor[i] - sensor[i - 1]);
	}

	sort(dist.begin(), dist.end(), greater<int>());
	int ans = 0;
	for (int i = --k; i < dist.size(); i++)
	{
		ans += dist[i];
	}

	cout << ans << endl;

	return 0;
}
