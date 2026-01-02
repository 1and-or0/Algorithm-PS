#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p_q;
	
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		if(temp != 0)
			p_q.emplace(abs(temp), temp);
		else
		{
			if (!p_q.empty())
			{
				cout << p_q.top().second << "\n";
				p_q.pop();
			}
			else
				cout << 0 << "\n";
		}
	}


	return 0;
}