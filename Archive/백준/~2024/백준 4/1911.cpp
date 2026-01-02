#include <iostream>
#include <queue>
#define endl "\n"
using namespace std;

int n, l, ans = 0;
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> l;

	for (size_t i = 0; i < n; i++)
	{
		int start, end;
		cin >> start >> end;
		pq.push({ start, end });
	}

	int use_end = -1; // use_end ±îÁö´Â ±¸¸ÛÀÌ ÀÖ¾îµµ µ¤¾îÁü
	
	while (not pq.empty())
	{
		int now_start = pq.top().first;
		int now_end = pq.top().second;
		pq.pop();

		if (use_end < now_start)
			use_end = now_start;
	
		while (now_end > use_end)
		{
			ans += 1;
			use_end += l;
			//use_end += now_start + l;
		}
	}

	cout << ans << endl;

	return 0;
}