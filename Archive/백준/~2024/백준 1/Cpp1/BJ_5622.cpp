#ifndef BITS_STDC_H5622
#define BITS_STDC_H5622
#include <bits/stdc++.h>
using namespace std;
#endif // !BITS_STDC_H5622

int main_5622()
{
	int abc[26];
	// fill_n(abc, 26, 0); 

	for (int i = 0; i < 5; ++i)  // 0, 1, 2, 3, 4
	{
		for (int j = i*3; j < i*3 + 3; ++j) // 0, 1, 2
		{
			abc[j] = i + 3;
		}
	}

	for (int i = 15; i < 26; ++i)
	{
		int key = (i / 10 + i % 10);
		if (i / 10 == 1 && 5 <= key && 9 >= key)
			abc[i] = 8;
		else if (i / 10 == 2 && 4 <= key && 7 >= key)
			abc[i] = 10;
		else
			abc[i] = 9;
	}

	string st;
	cin >> st;
	int total_time = 0;
	for (int i = 0; i < st.length(); ++i)
	{
		int index;
		index = (int)st[i] - 'A';
		total_time += abc[index];
	}
	cout << total_time;

	return EXIT_SUCCESS;
}