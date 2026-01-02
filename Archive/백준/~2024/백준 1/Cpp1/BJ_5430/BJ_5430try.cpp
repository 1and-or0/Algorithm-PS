#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	for (int times = 0; times < t; ++times)
	{
		int len;
		string order, temp;
		cin >> order >> len >> temp;

		deque<int> deq;

		int start = 1;
		for (int i = start + 1; i < temp.size(); )
		{
			if (temp[i] == ',' || temp[i] == ']')
			{
				int num = stoi(temp.substr(start, i - start));
				deq.push_back(num);
				start = i + 1;
				i += 2;
			}
			else
				i += 1;
		}

		bool onError = false, isReverse = false;
		for (int i = 0; i < order.size(); ++i)
		{
			switch (order[i])
			{
			case 'R':
				isReverse = !isReverse;
				break;
			case 'D':
				if (deq.empty())
				{
					onError = true;
					cout << "error" << "\n"; 
				}
				else
				{
					if (!isReverse)
						deq.pop_front();
					else
						deq.pop_back();
				}
				break;
			}

			if (onError)
				break;
		}

		if (!onError)
		{
			cout << "[";
			if (!deq.empty())
			{
				if (!isReverse)
				{
					deque<int>::iterator iter;
					for (iter = deq.begin(); iter != deq.end() - 1; ++iter)
						cout << *iter << ",";
					cout << *iter;
				}
				else
				{
					deque<int>::reverse_iterator iter;
					for (iter = deq.rbegin(); iter != deq.rend() - 1; ++iter)
						cout << *iter << ",";
					cout << *iter;
				}
			}
			cout << "]" << "\n";
		}
	}

	return 0;
}