#include <iostream>
#define endl "\n"
using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

const int n_max = 10;
char inputs[n_max][n_max] = { 0 };
int r, c;

int num_can_go[n_max][n_max] = { 0 };

bool is_can_go_over_1(int x, int y)
{
	int can_go = 0;
	for (int del = 0; del < sizeof(dx)/sizeof(dx[0]); del++)
	{
		int nx = x + dx[del];
		int ny = y + dy[del];

		if (nx < 0 || nx >= r || ny < 0 || ny >= c)
			continue;

		if (inputs[nx][ny] == 'X')
			continue;

		can_go += 1;
	}

	return (can_go > 1);
}

int num_dot = 0;

int main()
{
	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int ii = 0; ii < c; ii++)
		{
			cin >> inputs[i][ii];
			if (inputs[i][ii] == '.')
				num_dot += 1;
		}
	}

	bool is_zero = false;
	for (int i = 0; i < r; i++)
	{
		for (int ii = 0; ii < c; ii++)
		{
			if (inputs[i][ii] == 'X')
				continue;

			if (not is_can_go_over_1(i, ii))
			{
				is_zero = true;
				break;
			}
		}
	}

	if (is_zero)
		cout << "1" << endl;
	else
		cout << "0" << endl;

	return 0;
}