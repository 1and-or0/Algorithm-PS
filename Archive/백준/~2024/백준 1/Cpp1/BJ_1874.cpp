#ifndef BJ_1874_CPP
#define BJ_1874_CPP
#include <bits/stdc++.h>
using namespace std;
#endif // !BJ_1874_CPP

int main()
{
	string result;
	int n, i;
	cin >> n;
	vector<int> stack;
	int start = 0;
	for (i = 0; i < n; ++i)
	{
		//int now = -1;
		int temp;
		cin >> temp;
		while (start < temp)
		{
			start++;
			stack.push_back(start);
			result += '+';
		}

		if (stack.back() == temp)
		{
			//now = stack.back();
			stack.pop_back();
			result += '-';
		}
		else
		{
			result = "NO";
			break;
		}
	}

	for (++i; i < n; ++i)
	{
		int temp;
		cin >> temp;
	}

	if (result != "NO")
	{
		cout << result[0];
		for (int i = 1; i < size(result); ++i)
		{
			cout << '\n' << result[i];
		}
	}
	else
	{
		cout << result;
	}
	return EXIT_SUCCESS;
}