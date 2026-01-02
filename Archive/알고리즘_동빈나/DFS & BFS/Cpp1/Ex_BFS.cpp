#include <bits/stdc++.h>
using namespace std;


void bfs(vector<vector<int>>& graph, int start, bool(& visited) [9])
{
    queue<int> q;
    q.push(start);
    // 현재 노드를 방문 처리
    visited[start] = true;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << ' ';
        for (int i = 0; i < graph[v].size(); ++i)
        {
            if (!visited[graph[v][i]])
            {
                q.push(graph[v][i]);
                visited[graph[v][i]] = true;
            }
        }
    }
}

int main_ex_bfs()
{
    vector<vector<int>> graph = {
        {},           // 0번 노드
        {2, 3, 8},    // 1번 노드와 인접한 노드
        {1, 7},       // 2번 노드와 인접한 노드
        {1, 4, 5},    // 3번 노드와 인접한 노드
        {3, 5},       // 4번 노드와 인접한 노드
        {3, 4},       // 5번 노드와 인접한 노드
        {7},          // 6번 노드와 인접한 노드
        {2, 6, 8},    // 7번 노드와 인접한 노드
        {1, 7}        // 8번 노드와 인접한 노드
    };
    // vector<bool> visited(9, false);
    bool visited[9] = { false };
    bfs(graph, 1, visited);

	return EXIT_SUCCESS;
}