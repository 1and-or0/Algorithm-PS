#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

bool dfs(int x, int y);

int n, m;
int graph[1001][1001];

int main()
{
    // n, m을 공백 기준으로 구분, 입력 받기
    cin >> n >> m;

    // 2차원 벡터의 맵 정보 입력 받기
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) 
        {
            scanf("%1d", &graph[i][j]); // %1d로 형식 지정함. 따라서 글자 하나씩만 입력받아 graph[][]에 저장됨
        }
    }

    // 모든 노드(위치)에 대해 음료수 채우기
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // 현재 위치에서 DFS 수행
            if (dfs(i, j))
            {
                result += 1;
            }
        }
    }
    cout << result << '\n';

    return EXIT_SUCCESS;
}

// DFS로 특정 노드를 방문하고 연결된 모든 노드들도 방문
bool dfs(int x, int y)
{
    // 주어진 범위(인덱스)를 벗어난 경우, 종료
    if (x <= -1 || x >= n || y <= -1 || y >= m)
    {
        return false;
    }

    // 현재 노드를 아직 방문하지 않았다면 
    if (graph[x][y] == 0)
    {
        // 해당 노드 방문 처리
        graph[x][y] = 1;

        // 상하좌우 위치들도 모두 재귀적 호출
        dfs(x - 1, y);
        dfs(x + 1, y);
        dfs(x, y - 1);
        dfs(x, y + 1);
        return true;
    }

    return false;
}