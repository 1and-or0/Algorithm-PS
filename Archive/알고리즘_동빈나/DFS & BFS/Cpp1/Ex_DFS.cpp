#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& graph, int v, vector<bool>& visited) 
{
    // 현재 노드를 방문 처리
    visited[v] = true;
    cout << v << ' ';

    // 현재 노드와 연결된 다른 노드를 재귀적으로 방문
    for (int i = 0; i < graph[v].size(); i++) 
    {
        int next_node = graph[v][i];
        if (!visited[next_node]) 
        {
            dfs(graph, next_node, visited);
        }
    }
}

int main_ex_dfs() {
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
    vector<bool> visited(9, false);

    dfs(graph, 1, visited);

    return 0;
}