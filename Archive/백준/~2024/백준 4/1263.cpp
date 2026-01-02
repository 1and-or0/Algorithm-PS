#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

const int n_max = 1000, max_s_i = 1000000;
int n, ans = max_s_i + 1;
vector<pair<int, int>> t_s(n_max, {0, 0});

bool MyComp(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
}

bool get_ans(int index)
{
	int t_i = t_s[index].first;
	int s_i = t_s[index].second;

	ans = min(ans, s_i) - t_i;
	
	if (ans < 0)
		return false;

	return true;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n; 
	for (int i = 0; i < n; i++)
	{
		int temp_t_i, temp_s_i;
		cin >> temp_t_i >> temp_s_i;
		t_s[i].first = temp_t_i, t_s[i].second = temp_s_i;
	}

	sort(t_s.begin(), t_s.end(), MyComp);
	ans = max_s_i;

	//for (int i = 0; i < n; i++)
	//{
	//	cout << t_s[i].first << " " << t_s[i].second << endl;
	//}
	
	for (int i = 0; i < n; i++)
	{
		if (not get_ans(i))
		{
			cout << -1 << endl;
			break;
		}
	}

	if (ans >= 0)
		cout << ans << endl;

	return 0;
}