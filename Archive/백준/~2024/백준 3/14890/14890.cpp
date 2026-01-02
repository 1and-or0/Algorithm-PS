#include <iostream>
#define endl "\n"
using namespace std;
#include <iostream>
#define endl "\n"
using namespace std;

const int n_max = 100;

const int row = -22;
const int column = -11;

int n, l;
int map[n_max][n_max] = {0};

const int _right = 0, _down = 1, _left = 2, _up = 3; 
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

/// @brief 경사면을 사용할 수 있는지 확인, 입력받은 방향으로 어디까지 공간이 있는지 확인
/// @param dir 
/// @param x 
/// @param y 
/// @return 사용가능 true, 불가시 false
bool can_use_slope(int dir, int x, int y)
{
    int sapce_for_slope = 1;
    for (int i = 0; i < n -1; i++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        
        if (map[nx][ny] == map[x][y])
            sapce_for_slope += 1;
        else
            break;
    }

    return (sapce_for_slope >= l);
}

bool can_go_row(int x)
{
    bool slope_used[n_max] = {false}; // 경사로가 설치된 위치를 기록하는 배열
    for (int y = 0; y < n - 1; y++)
    {
        if (abs(map[x][y] - map[x][y+1]) > 1)
            return false;

        if (map[x][y] + 1 == map[x][y+1]) // 오르막 경사로
        {
            for (int k = 0; k < l; k++) // 경사로를 놓을 공간 확인
            {
                if (y - k < 0 || map[x][y] != map[x][y-k] || slope_used[y-k])
                    return false; // 범위를 벗어나거나 높이가 다르거나 이미 경사로가 있으면 불가
            }
            for (int k = 0; k < l; k++)
                slope_used[y-k] = true; // 경사로 설치
        }
        else if (map[x][y] == map[x][y+1] + 1) // 내리막 경사로
        {
            for (int k = 1; k <= l; k++) // 경사로를 놓을 공간 확인
            {
                if (y + k >= n || map[x][y+1] != map[x][y+k] || slope_used[y+k])
                    return false; // 범위를 벗어나거나 높이가 다르거나 이미 경사로가 있으면 불가
            }
            for (int k = 1; k <= l; k++)
                slope_used[y+k] = true; // 경사로 설치
        }
    }
    return true;
}

bool can_go_column(int y)
{
    bool slope_used[n_max] = {false}; // 경사로가 설치된 위치를 기록하는 배열
    for (int x = 0; x < n - 1; x++)
    {
        if (abs(map[x][y] - map[x+1][y]) > 1)
            return false;

        if (map[x][y] + 1 == map[x+1][y]) // 오르막 경사로
        {
            for (int k = 0; k < l; k++) // 경사로를 놓을 공간 확인
            {
                if (x - k < 0 || map[x][y] != map[x-k][y] || slope_used[x-k])
                    return false; // 범위를 벗어나거나 높이가 다르거나 이미 경사로가 있으면 불가
            }
            for (int k = 0; k < l; k++)
                slope_used[x-k] = true; // 경사로 설치
        }
        else if (map[x][y] == map[x+1][y] + 1) // 내리막 경사로
        {
            for (int k = 1; k <= l; k++) // 경사로를 놓을 공간 확인
            {
                if (x + k >= n || map[x+1][y] != map[x+k][y] || slope_used[x+k])
                    return false; // 범위를 벗어나거나 높이가 다르거나 이미 경사로가 있으면 불가
            }
            for (int k = 1; k <= l; k++)
                slope_used[x+k] = true; // 경사로 설치
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> l;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            cin >> map[x][y];
        }
    }
    int ans = 0;
    for (int x = 0; x < n; x++)
    {
        if (can_go_row(x))
            ans += 1;
    }
    for (int y = 0; y < n; y++)
    {
        if (can_go_column(y))
            ans += 1;
    }
    
    cout << ans << endl;

    return 0;
}
