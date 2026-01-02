#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	priority_queue<int, vector<int>, greater<int>> p_q;
	int n; cin >> n;
	for (int i=0; i < n; ++i) 
    {
		int temp; cin >> temp;
		p_q.push(temp);
	}

    if (n == 1) 
    {
        cout << p_q.top();
    }
    else 
    {
        long long now = (long long)p_q.top(), ans = 0;
        p_q.pop();
        for (int i=0; i < n-1; ++i) 
        {
            now += (long long)p_q.top();
            p_q.pop();
            ans += now;
        }
        cout << ans << "\n";
    }

	return 0;
}