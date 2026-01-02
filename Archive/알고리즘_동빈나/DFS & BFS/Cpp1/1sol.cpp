#include <bits/stdc++.h>
using namespace std;

bool ddfs(int x, int y);

int n1, m1;
vector<vector<int>> graph;

int main_1sol()
{
    // n, m을 공백 기준으로 구분, 입력 받기
    cin >> n1 >> m1;

    // 2차원 벡터의 맵 정보 입력 받기
    graph.assign(n1, vector<int>(m1, 0));
    for (int i = 0; i < n1; i++) 
    {
        for (int j = 0; j < m1; j++) 
        {
            char c;
            cin >> c;
            graph[i][j] = c - '0';
        }
    }

    // 모든 노드(위치)에 대해 음료수 채우기
    int result = 0;
    for (int i = 0; i < n1; i++) 
    {
        for (int j = 0; j < m1; j++) 
        {
            // 현재 위치에서 DFS 수행
            if (ddfs(i, j)) 
            {
                result += 1;
            }
        }
    }
    cout << result << '\n';

	return EXIT_SUCCESS;
}

// DFS로 특정 노드를 방문하고 연결된 모든 노드들도 방문
bool ddfs(int x, int y)
{
    // 주어진 범위(인덱스)를 벗어난 경우, 종료
    if (x <= -1 || x >= n1 || y <= -1 || y >= m1)
    {
        return false;
    }

    // 현재 노드를 아직 방문하지 않았다면 
    if (graph[x][y] == 0) 
    {
        // 해당 노드 방문 처리
        graph[x][y] = 1;
        // 상하좌우 위치들도 모두 재귀적 호출
        ddfs(x - 1, y);
        ddfs(x + 1, y);
        ddfs(x, y - 1);
        ddfs(x, y + 1);
        return true;
    }

    return false;
}