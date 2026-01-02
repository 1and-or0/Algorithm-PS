#include <bits/stdc++.h>
using namespace std;

string graph[100];
char now; // 탐색중인 구역이 R, G, B 중 어느 것인지 저장함
queue<pair<int, int>> q;

//  아래, 오른쪽, 위, 왼쪽
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs() 
{
    while (!q.empty()) 
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (graph[x][y] == '.' || graph[x][y] == 'K')
            continue;

        if (now == 'B')
            graph[x][y] = '.';
        else // R - G 인 경우 K로 바꾸고 bfs를 수행하면 색약인이 보는 구역의 개수
            graph[x][y] = 'K';

        for (int i = 0; i < 4; ++i) 
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위를 벗어난 경우
            if (nx < 0 || nx >= graph[0].length() || ny < 0 ||
                ny >= graph[0].length())
                continue;

            // 탐색하고 있는 노드가 같은 노드인 경우
            if (now == graph[nx][ny]) 
            {
                q.push(make_pair(nx, ny));
            }
        }
    }
}

void bfs2()
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (graph[x][y] == '.')
            continue;
        else
            graph[x][y] = '.';

        for(int i=0; i<4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위를 벗어난 경우
            if (nx < 0 || nx >= graph[0].length() || ny < 0 ||
                ny >= graph[0].length())
                continue;

            // 탐색하고 있는 노드가 같은 노드인 경우
            if (now == graph[nx][ny])
            {
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    // 입력받기
    for (int i = 0; i < n; ++i) 
    {
        cin >> graph[i];
    }

    int n_R = 0, n_G = 0, n_B = 0, n_RG = 0;

    now = graph[0][0];
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < graph[i].length(); ++j) 
        {
            if (graph[i][j] != '.' && graph[i][j] != 'K')
            {
                now = graph[i][j];
                q.push(make_pair(i, j));
                bfs();
                switch (now)
                {
                case 'R':
                    n_R++;
                    break;
                case 'G':
                    n_G++;
                    break;
                case 'B':
                    n_B++;
                    break;
                }
            }
        }
    }


    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < graph[i].length(); ++j)
        {
            if (graph[i][j] != '.')
            {
                now = graph[i][j];
                q.push(make_pair(i, j));
                bfs2();
                n_RG++;
            }
        }
    }
    cout << n_R + n_G + n_B << " " << n_RG + n_B;

    return 0;
}

// <낙서장>
// now = 탐색중인 문자 저장
// 탐색 시작지점 큐에 넣기 
// BFS
// BFS돌면
// 큐에서 꺼내고 
// 그 지점 문자 "."로 바꾸고
// 인접한 곳이 now랑 같은 문자면 탐색 
// 아니면 탐색X
// BFS가 끝나면 
// R구역 개수
// G구역 개수
// B구역 개수 중
// now에 저장된 거에 해당하는 구역의
// 개수를 하나 올리고 
// 다음 탐색 시작
