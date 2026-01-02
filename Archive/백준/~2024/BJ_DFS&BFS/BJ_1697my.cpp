#include <bits/stdc++.h>
using namespace std;

bool inBounds(int n)
{
	return (n >= 0 && n <= 100000);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	bool visit[100001] = { 0 };

	queue<pair<int, int>> que;
	que.emplace(n, 0);
	while (!que.empty())
	{
		int now = que.front().first;
		int time = que.front().second;
		que.pop();

		if (!inBounds(now))
		{
			continue;
		}
		
		visit[now] = true;

		if (now != k)
		{
			if (inBounds(now -1) && !visit[now - 1])
			{
				que.emplace(now - 1, time + 1);
			}

			if (inBounds(now + 1) && !visit[now + 1])
			{
				que.emplace(now + 1, time + 1);
			}

			if (inBounds(now * 2) && !visit[now * 2])
			{
				que.emplace(now * 2, time + 1);
			}
		}
		else
		{
			cout << time;
			break;
		}
	}

	return 0;
}