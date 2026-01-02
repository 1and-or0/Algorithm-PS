#include <iostream>
#include <vector>
using namespace std;

int n;
int grid[20][20];

// 기울어진 직사각형 변의 방향
#define ONE 0
#define TWO 1
#define THREE 2
#define FOUR 3

//            ↗  ↖  ↙ ↘  
int dx[] = { -1, -1,  1, 1};
int dy[] = {  1, -1, -1, 1};

int ans = 0;

struct MyStruct
{
	int start_x = 0, start_y = 0;
    int x = 0, y = 0;
    int n_dir = ONE;
	int change_dir_count = 0;
    int sum = 0;
	bool is_visit[20][20];

	MyStruct(int x, int y, int n_dir, int sum, bool (&is_visit)[20][20])
    {
		this->start_x = x;
		this->start_y = y;
        this->x = x;
        this->y = y;
		this->n_dir = n_dir;
        for (int i = 0; i < 20; i++)
        {
            for (int ii = 0; ii < 20; ii++)
            {
    			this->is_visit[i][ii] = is_visit[i][ii];
            }
        }
		this->is_visit[x][y] = true;
		this->sum += grid[x][y];
    }
};

bool is_out_of(int x, int y)
{
	bool result = false;
    // out of range
    if (x < 0 || x >= n)
    {
		result = true;
    }
    if (y < 0 || y >= n)
    {
		result = true;
    }
	return result; 
}

void go_straight(MyStruct cur, vector<MyStruct>& v)
{
    // 직진방향으로 다음 칸
    cur.x = cur.x + dx[cur.n_dir];
    cur.y = cur.y + dy[cur.n_dir];

	// out of range
    if (is_out_of(cur.x, cur.y))
    {
        return;
    }

    // 방문했다면
    if (cur.is_visit[cur.x][cur.y])
    {
        // 시작점이 아닐경우
        if (cur.x != cur.start_x || cur.y != cur.start_y)
        {
            return;
        }

		// 상자가 그려졌을 때 최댓값 갱신
        if (ans < cur.sum)
        {
            ans = cur.sum;
        }
        return;
    }

    cur.is_visit[cur.x][cur.y] = true;
    cur.sum += grid[cur.x][cur.y];
    v.push_back(cur);
}

void go_next_dir(MyStruct cur, vector<MyStruct>& v)
{
    // 다음 방향으로 방향 변경
	cur.n_dir = (cur.n_dir + 1);

    // 4번 이상 방향 변경 불가
    if (cur.n_dir > FOUR)
    {
		return;
    }

    // 해당 방향으로 직진
	go_straight(cur, v);
}

int main() 
{
    cin >> n;

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
	vector<MyStruct> v;

    for (int i = 0; i < n -2; i++)
    {
        for (int ii = 0; ii < n -2; ii++)
        {
            int x = 2 + i;
            int y = 1 + ii;
            bool temp[20][20] = { false };

            MyStruct start = MyStruct(x, y, ONE, 0, temp);
			v.push_back(start);

            while (!v.empty())
            {
                auto cur = v.back();
                v.pop_back();

                // 직진 방향 확인
				go_straight(cur, v);


				// 다음 방향 확인
                go_next_dir(cur, v);
            }

        }
    }

	cout << ans << endl;

    return 0;
}
