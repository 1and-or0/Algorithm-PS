#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
#define MAX 10001
using namespace std;

int N = 0;
vector<vector<int>> adj;
vector<pair<int, int>> can_hack; // idx, can_hack

bool cmp(pair<int, int>& p1, pair<int, int>& p2) 
{
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second > p2.second;
}

void bfs(int start) 
{
    bool visited[MAX] = { 0, };
    queue<int> q;
    int neighbor = 1;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) 
    {
        int cur = q.front();
        for (const auto& e : adj[cur]) 
        {
            if (visited[e])
                continue;
            q.push(e);
            visited[e] = true;
            neighbor++;
        }
        q.pop();
    }
    can_hack.push_back({ start, neighbor });
    return;
}

int main()
{
    FASTIO;
    int M; cin >> N >> M;
    adj.reserve(N + 1);
    while (M--) 
    {
        int x, y; cin >> x >> y;
        adj[y].push_back(x);
    }
    for (int i = 1; i <= N; i++) 
    {
        bfs(i);
    }
    sort(can_hack.begin(), can_hack.end(), cmp);
    int max_hack = can_hack[0].second;
    for (const auto& e : can_hack) 
    {
        if (max_hack > e.second)
            break;
        cout << e.first << ' ';
    }
    return 0;
}