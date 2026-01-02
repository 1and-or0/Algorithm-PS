#ifndef BITS_STDC_H2941
#define BITS_STDC_H2941
#include <bits/stdc++.h>
using namespace std;
#endif // !BITS_STDC_H2941

int main_bj_2941()
{
	string st; // abcde
	cin >> st;
	string c_a[] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

	for (int i = 0; i < sizeof(c_a) / sizeof(string); ++i)
	{
		while (st.find(c_a[i]) != string::npos)
		{
			st.replace(st.find(c_a[i]), c_a[i].length(), ".");
		}
	}
	
	cout << st.length();

	return EXIT_SUCCESS;
}