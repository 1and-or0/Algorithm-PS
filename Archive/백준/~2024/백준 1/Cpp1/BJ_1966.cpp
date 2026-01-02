#ifndef BJ_1966_CPP
#define BJ_1966_CPP
#include <bits/stdc++.h>
using namespace std;
#endif // !BJ_1966_CPP

int main()
{
	int t;
	cin >> t;
	for (int case_t = 0; case_t < t; ++case_t)
	{
		int n, m;
		cin >> n >> m;
		int arr[100];
		deque<int> q;
		for(int i=0; i<n; ++i)
		{
			int temp; cin >> temp;
			q.push_back(temp);
			arr[i] = temp;
		}
		for (int i = n; i < 100; ++i)
			arr[i] = -1;
		sort(arr, arr + n, greater<int>());
		
		int index = m;
		int result = 0;
		for (int i = 0; i < n;)
		{
			while (0 != index)
			{
				if (q.front() == arr[i])
				{
					q.pop_front();
					result += 1;
					i += 1;
				}
				else
				{
					int x = q[0];
					q.pop_front();
					q.push_back(x);
					
				}
				index -= 1;
			}

			if (arr[i] == q.front())
				break;
			else
			{
				int x = q[0];
				q.pop_front();
				q.push_back(x);
				index = n - i -1;
			}
		}
		
		cout << result + 1 << endl;
	}
	return EXIT_SUCCESS;
}