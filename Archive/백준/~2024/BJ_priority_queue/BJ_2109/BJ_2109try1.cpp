#include <bits/stdc++.h>
using namespace std;

int main()
{   // 빠른 입력
    // ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // 우선순위 큐 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p_q;
    // 입력 받기
    int n; cin >> n; // n개의 대학
    for(int i=0; i < n; ++i)
    {
        int p, d; cin >> p >> d;
        p_q.emplace(d, p);
    }

    // 문제에서 d의 최소값은 1임
    int day = 1, pay = 0, ans = 0;
    while(p_q.size() != 0)
    {
        if(day == p_q.top().first && pay < p_q.top().second)
        {
            pay = p_q.top().second;
        }
        else if(day != p_q.top().first)
        {
            day = p_q.top().first;            
            ans += pay;
            pay = 0;
            continue;
        }
        p_q.pop();
    }
    ans += pay;
    cout << ans << "\n";
    return 0;
}
