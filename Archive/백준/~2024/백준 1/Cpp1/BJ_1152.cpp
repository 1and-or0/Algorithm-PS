#ifndef BITS_STDC_H1152
#define BITS_STDC_H1152
#include <bits/stdc++.h>
using namespace std;
#endif // !BITS_STDC_H1152

int main_bj_1152()
{
	string st;
	getline(cin, st);  // 공백 포함 문자열 입력받기 cin(X), getline(O)

	int count = 0;
	for (int i = 0; i < st.length(); ++i)
	{
		if (st[i] == ' ')
			count += 1;
	}

	if (st[0] == ' ' && st[st.length() - 1] == ' ')
		count -= 1;
	else if (st[0] != ' ' && st[st.length() - 1] != ' ')
		count += 1;
	// else (st[0] or st[st.length()-1] == ' ' no problem
	cout << count <<endl;

	return EXIT_SUCCESS;
}