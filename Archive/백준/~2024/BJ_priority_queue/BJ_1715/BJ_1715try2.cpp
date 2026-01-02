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

    int now = 0, cnt = 0, ans = 0;
    while(!p_q.empty())
    {
        cnt += 1;
        now += p_q.top();
        p_q.pop();
        if(cnt == 2)
        {
            cnt = 0;
            ans += now;
            p_q.push(now);
            now = 0;
        }
    }

    if(ans != 0)
        cout << ans << "\n";
    else
        cout << now << "\n";

	return 0;
}