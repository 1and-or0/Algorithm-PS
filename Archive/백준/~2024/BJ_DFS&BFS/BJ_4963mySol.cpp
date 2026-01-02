#include <bits/stdc++.h>
using namespace std;
#define SIZE 8

int n, m; 

int dx[SIZE] = {-1, -1, 0, 1, 1,  1,  0, -1};
int dy[SIZE] = { 0,  1, 1, 1, 0, -1, -1, -1};

stack<pair<int, int>> st;

// (x, y) = Number
void dfs(int x, int y, vector<vector<int>>& graph)
{
	st.emplace(x, y);
	while (!st.empty())
	{
		pair<int, int> now_pos = st.top(); st.pop();
		for (int i = 0; i < SIZE; i++)
		{
			int nx = now_pos.first + dx[i];
			int ny = now_pos.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n)
				continue;

			if (graph[nx][ny] == 1)
			{
				st.emplace(nx, ny);
				graph[nx][ny] = 0;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

	while (1)
	{	// n: width, m: height
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		vector<vector<int>> graph(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> graph[i][j];
		}

		// <알고리즘 ~>
		int ans = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (graph[i][j] == 1) 
				{
					dfs(i, j, graph);
					ans += 1;
				}
			}
		}
		
		// 정답 출력
		cout << ans << "\n";
	}

	return 0;
}
