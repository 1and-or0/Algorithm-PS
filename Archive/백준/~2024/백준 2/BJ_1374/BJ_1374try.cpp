#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    priority_queue<int> p_q;
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(3, 0));
    bool* visit = new bool[n];
    for (int i = 0; i < n; i++)
    {
        int no, start, end;
        cin >> no >> start >> end;
        v[i] = {end, start, no};
        visit[no] = false;
    }
    sort(v.begin(), v.end());

    p_q.push(0); 
    int cnt=0, ans=0;
    int i = 0;
    for(; cnt < n; i++)
    {
        if(i == n)
        {
            i = -1;
            ans++;
            while(p_q.size() != 1)
            {
                p_q.pop();
            }
            continue;
        }

        if(visit[v[i][2]])
           continue; 
        
        // if (시작시간 >= p_q의 끝나는 시간)
        if(v[i][1] >= p_q.top())
        {   // 방문처리
            cnt++;
            visit[v[i][2]] = true; 
            p_q.push(v[i][0]); // 끝나는 시간 갱신
        }
    }

    cout << ++ans << "\n";
    delete[] visit;
    return 0;
}
