#include <bits/stdc++.h>
using namespace std;
#define DIRECTION 6
#define BORDER 100

int m, n, h;
int graph[BORDER + 1][BORDER + 1][BORDER + 1] = { NULL };

// z, y, x
struct pos {
	int z, y, x;
	pos(const int& zz, const int& yy, const int& xx) : z(zz), y(yy), x(xx) { }

	pos operator+(const pos& a);
	void operator+=(const pos& a);
};

queue<pos> que;
// 토마토 bfs로 익었나 확인
void bfs();
bool isInside(const pos& a);

int main()
{
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	// 입력받기
	// n행m열이 총 h개 만큼 있음
	cin >> m >> n >> h;

	for (int z = 0; z < h; z++)
	{
		for (int y = 0; y < n; ++y)
		{
			for (int x = 0; x < m; x++)
			{    // <알고리즘 ~>
				cin >> graph[z][y][x];
				if (graph[z][y][x] == 1)
					que.emplace(z, y, x);
			}
		}
	}

	bfs();

	bool flag = true;
	int result = 0;
	for (int z = 0; z < h; z++)
	{
		if (!flag)
			break;
		for (int y = 0; y < n; ++y)
		{
			if (!flag)
				break;
			for (int x = 0; x < m; x++)
			{
				if (graph[z][y][x] == 0)
				{
					flag = false;
					break;
				}
				else
				{
					result = result < graph[z][y][x] ? graph[z][y][x] : result;
				}
			}
		}
	}// <~ 알고리즘>

	// 정답 출력
	if (flag)
		cout << result - 1 << "\n";
	else
		cout << -1 << "\n";

	return 0;
}

// xyz 좌표계 - up down left right front back
int dx[] = { 0, 0, 0, 0, -1, 1 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { -1, 1, 0, 0, 0, 0 };

// 토마토 bfs로 익었나 확인
void bfs()
{
	while (!que.empty())
	{
		pos now = que.front();
		que.pop();

		for (int i = 0; i < DIRECTION; i++)
		{
			pos t = { dz[i], dy[i], dx[i] };
			t = t + now;

			if (!isInside(t))
				continue;

			if (graph[t.z][t.y][t.x] != 0)
				continue;

			graph[t.z][t.y][t.x] += graph[now.z][now.y][now.x] + 1;
			que.push(t);
		}
	}
}

// graph[z][y][x] - z, y, x가 범위를 벗어났는가 검사하는 함수
bool isInside(const pos& a)
{
	int z = a.z;
	int y = a.y;
	int x = a.x;

	bool result = true;
	if (z < 0 || y < 0 || x < 0)
		result = false;
	else if (z >= h || y >= n || x >= m)
		result = false;
	return result;
}

pos pos::operator+(const pos& a)
{
	// pos temp = { this->z, this->y, this->x };
	pos temp = *this;

	temp.x += a.x;
	temp.y += a.y;
	temp.z += a.z;
	return temp;
}

void pos::operator+=(const pos& a)
{
	*this = this->operator+(a);
}