// dp는 점화식을 잘 생각해 내면
// 특정 경우의 수에 대해 따로 처리를 할 필요가 없는 식으로 출제됨을 유의하자
// 접근 방식이 dp스럽지 못했나?
#include <bits/stdc++.h>
using namespace std;

// 홀수 인덱스는 없는 계단으로 편의를 위해 추가함.
int stairs[301 + 300] = { 0 };

// 선택지의 점수가 같아서 못 고르나?
bool cantChoice(short index);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	short howMany;
	cin >> howMany;

	// 입력받기
	for (short i = 2; i <= howMany * 2; i += 2) // 0 . 1 . 2 . 3 //  0 .1. 2 .3. 4 .5. 6
	{
		cin >> stairs[i];
	}

	int result = stairs[howMany*2]; // 마지막 계단은 무조건 포함
	bool towTimes = false;	// 인접한 두 개의 계단을 밟았나?
	// i 는 비교할 두 선택지 사이의 인덱스로 문제에서 입력받지 않은 계단이라고 볼 수 있음
	for (short i = howMany * 2 - 3; i > 0; )
	{
		if (!towTimes)  // 인접한 두개의 계단을 밟지 않고
		{
			if (!cantChoice(i)) // 선택지의 점수가 같지 않아 선택이 가능할 때
			{
				if (stairs[i - 1] > stairs[i + 1]) 
				{ // 인접하지 않은 계단을 밟음; 두 칸 아래 계단을 밟음
					result += stairs[i - 1];
					i -= 4;
				}
				else
				{ // 인접한 계단을 밟음; 한 칸 아래 계단을 밟음
					result += stairs[i + 1];
					i -= 2;
					towTimes = true;
				}
			}
			else  // 선택지의 점수가 같아 선택이 불가능 할 때
			{
				result += stairs[i + 1]; // result += stairs[i + 1]; 도 가능
				towTimes = true;
				i -= 2;
			}

		}
		else // 인접한 계단을 밟은 경우 선택지가 정해져 있음
		{
			towTimes = false; 
			result += stairs[i - 1];
			i -= 4;
		}
	}

	cout << result;
	return 0;
}

bool cantChoice(short index)
{
	short left = index - 1;
	short right = index + 1;

	return (stairs[left] == stairs[right]);
}
