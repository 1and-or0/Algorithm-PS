#include <iostream>
#define endl "\n"
using namespace std;

const int n_max = 250;
const char wall = '#', sheep = 'o', wolf = 'v';

int r, c;
char map[n_max][n_max] = { 0 };
bool is_visit[n_max][n_max] = { 0 };

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int num_wolf, num_sheep, temp_wolf, temp_sheep;

void DFS(int x, int y)
{
	if (map[x][y] == wolf)
		temp_wolf += 1;
	else if (map[x][y] == sheep)
		temp_sheep += 1;

	is_visit[x][y] = true;

	for (int del = 0; del < sizeof(dx) / sizeof(dx[0]); del++)
	{
		int nx = x + dx[del];
		int ny = y + dy[del];

		if (nx < 0 || nx >= r || ny < 0 || ny >= c)
			continue;

		if (map[nx][ny] == wall)
			continue;

		if (is_visit[nx][ny])
			continue;

		DFS(nx, ny);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int ii = 0; ii < c; ii++)
		{
			char temp;
			cin >> temp;

			map[i][ii] = temp;

			if (temp == wolf)
				num_wolf += 1;
			else if (temp == sheep)
				num_sheep += 1;


		}
	}


	for (int i = 0; i < r; i++)
	{
		for (int ii = 0; ii < c; ii++)
		{
			if (map[i][ii] == wall)
				continue;

			temp_wolf = 0;
			temp_sheep = 0;

			DFS(i, ii);

			if (temp_wolf >= temp_sheep)
				num_sheep -= temp_sheep;
			else
				num_wolf -= temp_wolf;
		}
	}

	cout << num_sheep << " " << num_wolf << endl;

	return 0;
}