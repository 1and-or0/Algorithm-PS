#ifndef BJ_18111_CPP
#define BJ_18111_CPP
#include <bits/stdc++.h>
using namespace std;
#endif // !BJ_18111_CPP

int n, m, b;
int arr[500][500] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> b;
	int cnt[257] = { 0 };  // 각 높이가 몇개 들어왔나
	int time[257];  // 각 높이로 만들 때의 시간
	fill_n(time, 257, -1);

	int max_h = 0;  /*min_h = 256,*/ 

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int temp;
			cin >> temp;
			arr[i][j] = temp;
			cnt[temp] += 1;

			if (max_h < temp)
				max_h = temp;
		}
	}

	int high = max_h;
	int before_time = 128000001;
	while (high >= 0)
	{
		int inven = b;
		int this_h_time = 0;
		
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (arr[i][j] == high)
					continue;
				else if (arr[i][j] < high) // 인벤토리에서 블록을 꺼내 쌓기 
				{
					int temp = high - arr[i][j];
					inven -= temp;
					this_h_time += temp;
				}
				else if (arr[i][j] > high)  // 인벤토리에 블록을 넣기
				{
					int temp = arr[i][j] - high;
					inven += temp;
					this_h_time += 2*temp;
				}
			}
		}

		if (inven < 0)  // 만들 수 없는 경우
		{
			continue;
		}
		else  // 만들 수 있는 경우 
		{
			time[high] = this_h_time;
		}

		if (before_time > time[high])
		{
			before_time = time[high];
		}
		else
		{
			break;
		}
		high -= 1;
	}

	int result_time = time[max_h];
	int result_high = max_h;
	for (int h = max_h; h > -1; --h)
	{
		if (time[h] == -1)
			continue;
		else if (result_time > time[h])
		{
			result_time = time[h];
			result_high = h;
		}
	}

	cout << result_time << ' ' << result_high;

	return EXIT_SUCCESS;
}