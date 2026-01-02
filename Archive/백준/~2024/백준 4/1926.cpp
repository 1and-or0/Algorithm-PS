#include <iostream>
#include <queue>
#define endl "\n"
using namespace std;

const int max_ = 500;
int n, m;
bool map[max_][max_] = { 0 };
bool is_visited[max_][max_] = { 0 };

const int dx[] = {0, 1, 0, -1};
const int dy[] = { 1, 0, -1, 0 };

struct Pos
{
	int x, y;
};
queue<Pos> q;

int nums_area = 0;
int max_area = 0;

bool is_out_of(Pos pos1)
{
	return (pos1.x < 0 || pos1.y < 0 || pos1.x >= n || pos1.y >= m);
}

void BFS(int x, int y)
{
	is_visited[x][y] = true;
	q.push({ x, y });
	int temp = 0;
	while (!q.empty())
	{
		temp += 1;
		Pos now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Pos next = { now.x + dx[i], now.y + dy[i] };
			if (is_out_of(next))
				continue;
			
			if (!map[next.x][next.y])
				continue;

			if (is_visited[next.x][next.y])
				continue;

			is_visited[next.x][next.y] = true;
			q.push(next);
		}
	}
	if (max_area < temp)
		max_area = temp;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m; y++)
		{
			cin >> map[x][y];
		}
	}

	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m; y++)
		{
			if (!map[x][y])
				continue;
			
			if (is_visited[x][y])
				continue;

			nums_area += 1;
			BFS(x, y);
		}
	}

	cout << nums_area << endl;
	cout << max_area << endl;

	return 0;
}