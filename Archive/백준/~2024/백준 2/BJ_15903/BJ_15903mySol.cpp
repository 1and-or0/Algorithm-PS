#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // 최소 힙
    priority_queue<long long, vector<long long>, greater<long long>> p_q;

    // 입력 받기
    long long n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        long long ai; cin >> ai;
        p_q.push(ai);
    }
    
    // 놀이하기
    for (int i = 0; i < m; i++)
    {
        long long a = p_q.top(); p_q.pop();
        long long b = p_q.top(); p_q.pop();
        a = a + b; b = a;
        p_q.push(a); p_q.push(b);
    }
    
    // 정답 출력하기
    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += p_q.top(); p_q.pop();
    }
    
    cout << ans << "\n";

    return 0;
}
