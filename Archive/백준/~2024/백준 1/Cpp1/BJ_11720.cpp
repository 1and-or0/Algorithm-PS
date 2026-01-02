#ifndef BITS_STDC_H11720
#define BITS_STDC_H11720
#include <bits/stdc++.h>
using namespace std;
#endif // !BITS_STDC_H11720

int main_bj_11720()
{
	int n;
	cin >> n;
	
	string st;
	cin.ignore();  // 버퍼 비우기
	getline(cin, st);

	int sum = 0;
	for (int j = 0; j < n; ++j)
	{
		char c;
		c = st[j] - '0';
		if (c != '\n')				
			sum += c;
	}
	
	cout << sum;

	return EXIT_SUCCESS;
}