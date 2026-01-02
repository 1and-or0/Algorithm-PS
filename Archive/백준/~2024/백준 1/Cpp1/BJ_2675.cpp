#ifndef BITS_STDC_H2675
#define BITS_STDC_H2675
#include <bits/stdc++.h>
using namespace std;
#endif // !BITS_STDC_H2675

int main_bj_2675()
{
	int n;
	cin >> n;
	string st;
	int how_many;
	for (int i = 0; i < n; ++i)
	{
		cin >> how_many;
		cin >> st;
		for (int k = 0; k < st.length(); ++k)	
			for (int j = 0; j < how_many; ++j)
			{
				cout << st[k];
			}

		cout << endl;
	}

	return EXIT_SUCCESS;
}