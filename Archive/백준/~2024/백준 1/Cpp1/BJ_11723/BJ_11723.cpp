#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m;
	cin >> m;

	set<int> s;
	for (int i = 0; i < m; ++i)
	{
		char op[7];
		cin >> op;
		
		if (op[1] == 'd')
		{
			int temp;
			cin >> temp;
			s.insert(temp);
		}
		else if (op[1] == 'e')
		{
			int temp;
			cin >> temp;
			s.erase(temp);
		}
		else if (op[1] == 'h')
		{
			int temp;
			cin >> temp;
			cout << s.count(temp) << '\n';
		}
		else if (op[1] == 'o')
		{
			int temp;
			cin >> temp;
			if (s.count(temp) == 1)
				s.erase(temp);
			else
				s.insert(temp);
		}
		else if (op[1] == 'l')
		{
			s.clear();
			for (int i = 1; i < 21; ++i)
				s.insert(i);
		}
		else if (op[1] == 'm')
		{
			s.clear();
		}
	}
	return 0;
}