#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    priority_queue<double> p_q; // 오름차순 정렬 우선순위 큐
    int n; double h; int t;
    cin >> n >> h >> t;
    for (int i = 0; i < n; i++)
    {
        double h_giant; cin >> h_giant;
        p_q.push(h_giant);
    }
    
    int cnt = 0;
    while(cnt < t)
    {
        if(p_q.top() < h || p_q.top() == 1)
            break;
        double top = p_q.top(); p_q.pop();
        top = top / 2.0; p_q.push(top);
        cnt++;
    }

    if(p_q.top() < h)
    {
        cout << "YES" << "\n";
        cout << cnt << "\n";
    }
    else
    {
        cout << "NO" << "\n";
        cout << (int)p_q.top() << "\n";
    }
    
    return 0;
}
