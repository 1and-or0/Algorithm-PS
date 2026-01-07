/*
* https://usaco.org/index.php?page=viewproblem2&cpid=939
* USACO 2019 US Open Contest, Bronze
* Problem 1. Bucket Brigade
*/
#include <iostream>
#include <queue>
#include <algorithm>
#define endl "\n"

using namespace std;

char farm[10][10] = { 0 };

struct Pos
{
    int x, y;

    Pos(int x=0, int y=0) : x(x), y(y)
    {
    }

    bool operator== (Pos b)
    {
        return (x == b.x and y == b.y);
    }
};

bool is_rock(const Pos& pos)
{
    return (farm[pos.x][pos.y] == 'R');
}

bool is_out_of(const Pos& pos)
{
    return (pos.x < 0 or pos.x >= size(farm) or pos.x < 0 or pos.y >= size(farm[0]));
}

// R, D, U, L (= 우하상좌)
int dx[] = { 0, 1, -1, 0 };
int dy[] = { 1, 0, 0, -1 };

void bfs(Pos start, Pos end, int& ans, bool is_visited[10][10])
{
    queue<pair<Pos, int>> q;

    is_visited[start.x][start.y] = true;
    q.push({ start, 0 });

    while (not q.empty())
    {
        Pos now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for (int i = 0; i < size(dx); i++)
        {
            Pos temp = Pos({ now.x + dx[i], now.y + dy[i] });
            
            if (is_out_of(temp) or is_rock(temp))
            {
                continue;
            }
            
            if (is_visited[temp.x][temp.y])
            {
                continue;
            }

            if (temp == end)
            {
                ans = cnt;
                return;
            }

            is_visited[temp.x][temp.y] = true;
            q.push({temp, cnt + 1});
        }
    }
}

int main() {
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);

    bool is_visited[10][10] = { 0 };
    Pos barn = Pos();
    Pos lake = Pos();

    for (int i = 0; i < size(farm); i++)
    {
        for (int ii = 0; ii < size(farm[0]); ii++)
        {
            cin >> farm[i][ii];

            if (farm[i][ii] == 'B')
            {
                barn.x = i;
                barn.y = ii;
            }
            else if (farm[i][ii] == 'L')
            {
                lake.x = i;
                lake.y = ii;
            }
        }
    }

    int ans = 0; 

    bfs(barn, lake, ans, is_visited);

    cout << ans << endl;

    return 0;
}