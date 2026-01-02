#ifndef BITS_STDC_H10988
#define BITS_STDC_H10988
#include <bits/stdc++.h>
using namespace std;
#endif // !BITS_STDC_H10988

int main_bj_10988()
{
	string st;
	cin >> st;
	// cout << ((float)st.length() / 2);
	bool result = true;
	for (int i = 0; i < (float) st.length()/2; ++i)
	{
		if (st[i] != st[st.length()-1 - i])
			result = false;
	}
	cout << (int)result;

	return EXIT_SUCCESS;
}