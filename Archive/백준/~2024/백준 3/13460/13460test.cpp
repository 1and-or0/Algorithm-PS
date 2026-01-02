// 13460v2가 깔끔하고 이해하기 쉬운 풀이 
#include <iostream>
#include <queue>
#define endl "\n"
using namespace std;

struct State 
{
    int rx, ry, bx, by, depth;
};

int N, M;
char board[10][10];
bool visited[10][10][10][10];
int dx[4] = {-1, 1, 0, 0}; // up, down, left, right
int dy[4] = {0, 0, -1, 1};

bool move(int &x, int &y, int &count, int dx, int dy) 
{
    while (board[x + dx][y + dy] != '#' && board[x][y] != 'O')
    {
        x += dx;
        y += dy;
        count += 1;
        if (board[x][y] == 'O') return true;
    }
    return false;
}

int bfs(int rx, int ry, int bx, int by) 
{
    queue<State> q;
    q.push({rx, ry, bx, by, 0});
    visited[rx][ry][bx][by] = true;

    while(!q.empty())
    {
        State cur = q.front();
        q.pop();

        if (cur.depth >= 10 ) return -1;

        for (int i = 0; i < 4; i++)
        {
            int nrx = cur.rx, nry = cur.ry, nbx = cur.bx, nby = cur.by;
            int r_c = 0, b_c = 0;

            bool red_in_hole = move(nrx, nry, r_c, dx[i], dy[i]);
            bool blue_in_hole = move(nbx, nby, b_c, dx[i], dy[i]);

            if (blue_in_hole) continue;
            if (red_in_hole) return cur.depth + 1;

            if (nrx == nbx && nry == nby)
            {
                if (r_c > b_c)
                {
                    nrx -= dx[i];
                    nry -= dy[i];   
                }
                else
                {
                    nbx -= dx[i];
                    nby -= dy[i];
                }
            }

            if (!visited[nrx][nry][nbx][nby])
            {
                visited[nrx][nry][nbx][nby] = true;
                q.push({nrx, nry, nbx, nby, cur.depth + 1});
            }
        }
    }

    return -1;
}

int main() 
{
    cin >> N >> M;
    int rx, ry, bx, by;

    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < M; ++j) 
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                rx = i;
                ry = j;
            } 
            else if (board[i][j] == 'B') 
            {
                bx = i;
                by = j;
            }
        }
    }

    cout << bfs(rx, ry, bx, by) << endl;
    return 0;
}