#include <bits/stdc++.h>
using namespace std;

int main()
{
	// L, R, U, D에 따른 이동 방향
	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { -1, 1, 0, 0 };
	char moveTypes[4] = { 'L', 'R', 'U', 'D' };

	int x = 1, y = 1;

	int n;
	cin >> n;
	
	// C++, Java의 경우 정수를 입력받은 후 문자열을 입력받기 전에 버퍼에 엔터가 남아있음... 엔터를 비워주는 것 
	// ex) 입력
	// 4(정수)     => 4 \n R R R U D \n => 4 \n (정수 입력 => R R R U D (문자열 입력 => \n을 버퍼에서 비우기 
	// R R R U D (문자열)
	cin.ignore();  // 버퍼 비우기
	
	string plans;
	getline(cin, plans);

	for (int i = 0; i < plans.size(); ++i) // i < plans.size() 
	{
		char plan = plans[i];
		// 이동 후 좌표 바꾸기 (nx, ny 매번 초기화해주기 + plan = plans의 공백 부분인 경우 if문 continue만나 다음으로 넘어감 
		int nx = -1, ny = -1;
		for (int j = 0; j < 4; ++j)
		{
			if (plan == moveTypes[j])
			{
				nx = x + dx[j];
				ny = y + dy[j];
			}
		}
		// 공간을 벗어난 경우는 무시
		if (nx < 1 || ny < 1 || nx > n || ny > n)
			continue;

		x = nx;
		y = ny;
	}
	cout << x << ' ' << y << endl;

	return EXIT_SUCCESS;
}