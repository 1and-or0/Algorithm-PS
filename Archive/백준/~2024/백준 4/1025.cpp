#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
int n, m, ans, flag = -1;
char arr[11][11];

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			cin >> arr[i][j];
			if (arr[i][j] == '9' && flag < 9) 
				flag = 9;
			else if (arr[i][j] == '4' && flag < 4) 
				flag = 4;
			else if (arr[i][j] == '1' && flag < 1) 
				flag = 1;
			else if (arr[i][j] == '0' && flag < 0) 
				flag = 0;
		}
	}
	ans = flag;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			string str;
			str += arr[i][j];
			for (int dx = -i; dx + i < n; dx++) 
			{
				for (int dy = -j; dy + j < m; dy++) 
				{
					if (!dx && !dy) 
						continue;

					string s;
					s = str;
					for (int ddx = dx, ddy = dy;
						i + ddx < n && i + ddx >= 0 && j + ddy < m && j + ddy >= 0;
						ddx += dx, ddy += dy) 
					{
						s += arr[i + ddx][j + ddy];
						int num = stoi(s);
						int sqnum = sqrt(num);
						if (num == sqnum * sqnum && num > ans)
							ans = num;
					}
				}
			}
		}
	}

	cout << ans;
	return 0;
}