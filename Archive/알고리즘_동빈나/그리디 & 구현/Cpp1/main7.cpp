#include <bits/stdc++.h>
using namespace std;

int main7()
{
	char n[3];
	cin >> n;

	// 입력받은 현재 위치 확인
	int x = n[1]-'0';
	
	int y=-1;
	for (int i = 1; i <= 8; ++i)
	{
		if ((tolower(n[0])-'`') == i)
		{
			y = i;
			//cout << n[0];
			break;
		}
	}

	// 나이트가 움직일 수 있는 위치
	int moves[8][2] = { {-1, -2}, {-2, -1},
						{-2, 1}, {-1, 2},
						{1, 2}, {2, 1},
						{2, -1}, {1, -2} };
	
	// 나이트가 움직일 수 있는 위치 확인
	for (int i = 0; i < 8; ++i)
	{
		int nx = x, ny = y;
		nx += moves[i][0];
		ny += moves[i][1];
		char show_y = '`' + ny;
		if (nx > 0 && ny > 0 && nx < 9 && ny << 9)
		{
			cout << nx << ", " << ny << endl;
			cout << show_y << nx << endl;
		}
	}


	return EXIT_SUCCESS;
}