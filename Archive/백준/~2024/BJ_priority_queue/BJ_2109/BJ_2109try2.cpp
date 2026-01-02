#include <bits/stdc++.h>
using namespace std;

int main() 
{    // 빠른 입력
    ios_base::sync_with_stdio(0);  cin.tie(NULL); cout.tie(NULL);
    
    deque<pair<int, int>> day_pay;
    // 우선순위 큐
    priority_queue<int, vector<int>, greater<int>> p_q;
    
    // 입력 받기
    int n; cin >> n; // n개의 대학
    for (int i = 0; i < n; ++i) 
    {
        int p, d;
        cin >> p >> d;
        day_pay.emplace_back(d, p);
    }
    sort(begin(day_pay), end(day_pay)); // 날짜 기준 오름차순 정렬

    int day = day_pay.front().first, ans = 0;
    for(pair<int, int> d_p : day_pay)
    {
        if(day == d_p.first)
        { // 같은 값의 d를 볼 때, p_q를 이용해 p의 최대값을 구함
            p_q.push(d_p.second);
            if(p_q.size() > 1)
                p_q.pop();
        }
        else
        { // 다른 값의 d를 볼 때, 구한 최대값 p를 ans에 더해줌
            ans += p_q.top();
            p_q.pop();
            day = d_p.first;
            p_q.push(d_p.second);
        }
    }

    if(p_q.size() == 1)
        ans += p_q.top();
    
    cout << ans << "\n";

    return 0;
}
