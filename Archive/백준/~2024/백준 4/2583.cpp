#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define endl "\n"
using namespace std;

int m, n, k;
const int _max = 100;
bool is_unvalid[_max][_max] = { 0 };  // 이 배열은 여전히 행(row)과 열(column)로 처리
bool is_visited[_max][_max] = { 0 };
vector<int> n_area;

struct Pos
{
	int x, y;  // x는 행(row), y는 열(column)
};

bool is_out_of(int x, int y)
{
	if (x < 0 || y < 0 || x >= m || y >= n)  // x는 행(row), y는 열(column)
		return true;
	return false;
}

void set_unvaild(Pos left_top, Pos right_bottom)
{
	for (int nx = left_top.x; nx < right_bottom.x; nx++)  // 행에 대해 반복
	{
		for (int ny = left_top.y; ny < right_bottom.y; ny++)  // 열에 대해 반복
		{
			is_unvalid[nx][ny] = true;  // 영역을 '유효하지 않음'으로 설정
		}
	}
}

const int dx[] = { 0, 1, 0, -1 };  // 상하좌우 이동
const int dy[] = { 1, 0, -1, 0 };

queue<Pos> q;

int nums_area = 0;
int BFS_cnt(int x, int y)
{
	int area = 0;
	is_visited[x][y] = true;
	q.push({ x, y });

	while (!q.empty())
	{
		Pos now = q.front();
		q.pop();
		area += 1;
		for (int i = 0; i < 4; i++)  // 상하좌우로 탐색
		{
			Pos next = { now.x + dx[i], now.y + dy[i] };

			if (is_out_of(next.x, next.y))
				continue;

			if (is_unvalid[next.x][next.y])
				continue;

			if (is_visited[next.x][next.y])
				continue;

			is_visited[next.x][next.y] = true;
			q.push(next);
		}
	}
	return area;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> m >> n >> k;

	for (int t = 0; t < k; t++)
	{
		Pos left_top;
		Pos right_bottom;
		cin >> left_top.y >> left_top.x;  // y는 열(column), x는 행(row)
		cin >> right_bottom.y >> right_bottom.x;

		set_unvaild(left_top, right_bottom);
	}

	for (int x = 0; x < m; x++)  // 행(row) 순회
	{
		for (int y = 0; y < n; y++)  // 열(column) 순회
		{
			if (is_unvalid[x][y])
				continue;

			if (is_visited[x][y])
				continue;

			n_area.push_back(BFS_cnt(x, y));
			nums_area += 1;
		}
	}

	cout << nums_area << endl;
	sort(begin(n_area), end(n_area));
	for (int area : n_area)
	{
		cout << area << " ";
	}
	cout << endl;

	return 0;
}
