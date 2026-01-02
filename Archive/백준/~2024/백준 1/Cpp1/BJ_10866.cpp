#ifndef BJ_10866_CPP
#define BJ_10866_CPP
#include <bits/stdc++.h>
using namespace std;
#endif // !BJ_10866_CPP

int main_BJ_10866_CPP()
{
	int n;
	cin >> n;
	deque<int> d;
	for (int i = 0; i < n; ++i)
	{
		string order;
		cin >> order;
		if (order == "push_back")
		{
			int a;
			cin >> a;
			d.push_back(a);
		}
		else if (order == "push_front")
		{
			int a;
			cin >> a;
			d.push_front(a);
		}
		else if (order == "pop_front")
		{
			if (!d.empty())
			{
				cout << d.front() << endl;
				d.pop_front();
			}
			else
				cout << -1 << endl;
		}
		else if (order == "pop_back")
		{
			if (!d.empty())
			{
				cout << d.back() << endl;
				d.pop_back();
			}
			else
				cout << -1 << endl;
		}
		else if (order == "size")
			cout << d.size() << endl;
		else if (order == "empty")
		{
			if (d.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (order == "front")
		{	
			if (!d.empty())
				cout << d.front() << endl;
			else
				cout << -1 << endl;
		}
		else if (order == "back")
		{
			if (!d.empty())
				cout << d.back() << endl;
			else
				cout << -1 << endl;
		}
	}

	return EXIT_SUCCESS;
}