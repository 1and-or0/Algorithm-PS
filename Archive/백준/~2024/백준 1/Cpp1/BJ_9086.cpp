#ifndef BITS_STDC_H9086
#define BITS_STDC_H9086
#include <bits/stdc++.h>
using namespace std;
#endif // !BITS_STDC_H9086

int main_bj_9086()
{
	int n;
	cin >> n;

	string st;
	cin.ignore(); // 버퍼 비우기, C, JAVA에서는 숫자를 입력받다가 문자열을 입력받기 위해 버퍼에 남아있는 엔터를 없애야함
	for (int i = 0; i < n; ++i)
	{
		getline(cin, st);
		cout << st[0] << st[st.size() - 1] << endl;
	}


	return EXIT_SUCCESS;
}