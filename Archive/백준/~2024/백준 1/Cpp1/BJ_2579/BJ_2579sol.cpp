#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	// 계단의 개수
	int howMany;
	cin >> howMany;
	// 계단별 점수를 저장할 배열
	int stairs[300] = { 0 };
	// 입력받기
	for (int i = 0; i < howMany; ++i)
	{
		cin >> stairs[i];
	}

	// 같은 점수의 계단이 연속으로 나올 경우는 고려하지 않아도 되는가
	// 점수 저장할 변수: result - 마지막 계단 무조건 포함
	int result = stairs[howMany - 1];
	bool towTimes = false;  // 두번 연속된 계단을 밟았나
	// int nowOn = howMany - 1;  // 지금 서 있는 계단의 인덱스
	for (int i = howMany - 2; i > 0; )
	{
		if (!towTimes)
		{
			if (stairs[i] > stairs[i - 1])
			{
				result += stairs[i];
				i -= 1;
				towTimes = true;
			}
			else
			{
				result += stairs[i - 1];
				i -= 2;
			}
		}
		else
		{
			towTimes = false;
			result += stairs[i - 1];
			i -= 2;
		}
	}
	cout << result;

	return 0;
}