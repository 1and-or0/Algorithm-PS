#include <bits/stdc++.h>
using namespace std;

int main()
{
	// 오버플로우 나버려요 이렇게 풀면 안됩니다
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	// 펙토리얼에서 10의 약수만 남기고 나머지는 없애버림
	// 3! = 6이지만 2만 남아있음.
	unsigned long long fact[500 + 1] = { 0 };
	fact[0] = 1;
	fact[1] = 1;

	// 0의 개수를 저장하는 배열
	int answer[500 + 1] = { 0 };

	int n;
	cin >> n;

	for (int j = 2; j < n + 1; ++j)
	{
		fact[j] = fact[j - 1] * j;
		
		if (fact[j] % 3 == 0)
			fact[j] = fact[j] / 3;
		else if (fact[j] % 7 == 0)
			fact[j] = fact[j] / 7;

	}

	return 0;
}