#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"
using namespace std;

int find_max_in_v(vector<vector<int>> &board, int n)
{
    int max = -1;
    for (int i = 0; i < n; i++)
    {
        int temp = *max_element(board[i].begin(), board[i].end());
        if (max < temp)
            max = temp;
    }
    return max;
}

void move_down(vector<vector<int>> &board, int& n)
{
    for (int y = 0; y < n; y++)
    {
        int down = n-1;
        for (int x = 1; x < n; x++)
        {
            if (board[n-1-x][y] == 0) continue;

            int up = n-1-x;
            if (board[down][y] == 0)
            {
                swap(board[up][y], board[down][y]);
                // iter_swap(board[x].begin() + up, board[x].begin() + down);
                continue;
            }

            if (board[down][y] != board[up][y])
            {
                down -= 1;
                swap(board[up][y], board[down][y]);
                // iter_swap(board[x].begin() + up, board[x].begin() + down);
            }
            else
            {
                board[down][y] += board[up][y];
                board[up][y] = 0;
                down -= 1;
            }
        }
    }
}

void move_up(vector<vector<int>> &board, int& n)
{
    for (int y = 0; y < n; y++)
    {
        int up = 0;
        for (int x = 1; x < n; x++)
        {
            if (board[x][y] == 0) continue;

            int down = x;
            if (board[up][y] == 0)
            {
                swap(board[up][y], board[down][y]);
                // iter_swap(board[x].begin() + up, board[x].begin() + down);
                continue;
            }

            if (board[down][y] != board[up][y])
            {
                up += 1;
                swap(board[up][y], board[down][y]);
                // iter_swap(board[x].begin() + up, board[x].begin() + down);
            }
            else
            {
                board[up][y] += board[down][y];
                board[down][y] = 0;
                up += 1;
            }
        }
    }
}

void move_right(vector<vector<int>> &board, int& n)
{
    for (int x = 0; x < n; x++)
    {
        int right = n-1;
        for (int y = 1; y < n; y++)
        {
            if (board[x][n-1-y] == 0) continue;

            int left = n-1-y;
            if (board[x][right] == 0)
            {
                iter_swap(board[x].begin() + left, board[x].begin() + right);
                continue;
            }

            if (board[x][left] != board[x][right])
            {
                right -= 1;
                iter_swap(board[x].begin() + left, board[x].begin() + right);
            }
            else
            {
                board[x][right] += board[x][left];
                board[x][left] = 0;
                right -= 1;
            }

        }        
    }
}

void move_left(vector<vector<int>> &board, int& n)
{
    for (int x = 0; x < n; x++)
    {
        int left = 0;
        for (int y = 1; y < n; y++)
        {
            if (board[x][y] == 0) continue;

            int right = y;
            if (board[x][left] == 0)
            {
                iter_swap(board[x].begin() + left, board[x].begin() + right);
                continue;
            }

            if (board[x][left] != board[x][right])
            {
                left += 1;
                iter_swap(board[x].begin() + left, board[x].begin() + right);
            }
            else
            {
                board[x][left] += board[x][right];
                board[x][right] = 0;
                left += 1;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int> (n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    queue<vector<vector<int>>> q;
    q.push(board);

    int num_move = 5;
    for (int move = 0; move < num_move; move++)
    {
        int temp = q.size();
        for (int j = 0; j < temp; j++)
        {
            vector<vector<int>> cur_board = q.front();
        q.pop();
        
        vector<vector<int>> left_case = cur_board;
        move_left(left_case, n);
        q.push(left_case);
        
        // TODO: 나머지 3개 방향 추가 
        vector<vector<int>> right_case = cur_board;
        move_right(right_case, n);
        q.push(right_case);

        vector<vector<int>> up_case = cur_board;
        move_up(up_case, n);
        q.push(up_case);

        vector<vector<int>> down_case = cur_board;
        move_down(down_case, n);
        q.push(down_case);

        }
    }

    int total_max = -1;
    while(!q.empty())
    {
        int n_max = find_max_in_v(q.front(), n);
        if (total_max < n_max)
        {
            total_max = n_max; 
        }
        

        q.pop();
    }

    cout << total_max << endl;

    return 0;
}
