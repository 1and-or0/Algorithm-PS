#include <iostream>
#include <algorithm>
//#include <iterator>
using namespace std;

int N;
int grid[20][20];

const int l = 3;

int getCoins(int x, int y)
{
	int sum = 0;
    for (int i = 0; i < l; i++)
    {
        for (int ii = 0; ii < l; ii++)
        {
            sum += grid[x + i][y + ii];
        }
    }
    
    return sum;
}

int main() 
{
    cin >> N;

    for (int x = 0; x < N; x++) 
    {
        for (int y = 0; y < N; y++) 
        {
            cin >> grid[x][y];
        }
    }

    // Please write your code here.

    int dx[] = { 1 };
    int dy[] = { 1 };

    int ans = 0;

    for (int x = 0; x < N - l +1; x++)
    {
        for (int y = 0; y < N - l +1; y++)
        {
            int nx = x;
            int ny = y;

			// out of range
            if (nx < 0 || nx +l -1 >= N)
            {
                continue;
            }
            if (ny < 0 || ny +l -1 >= N)
            {
                continue;
			}

            int temp_ans = getCoins(nx, ny);
            if (temp_ans > ans)
            {
                ans = temp_ans;
			}

        }
    }

	cout << ans << "\n";    
    return 0;
}
