#include <iostream>
#include <string>
using namespace std;
int main3()
{
	string str;
	cin >> str;

	// 아스키코드 변환 0(= 48) - '0'(= 48) = 0    '1' = 49
	int result = str[0] - '0';

	for (int i = 1; i < str.size(); ++i)
	{
		int num = str[i] - '0';
		// 두 수 중에서 하나라도 '0' or '1'인 경우 + 연산
		if (num <= 1 || result <= 1)
			result += num;
		else
			result *= num;
		// else x 연산 
	}

	cout << result;

	return 0;
}