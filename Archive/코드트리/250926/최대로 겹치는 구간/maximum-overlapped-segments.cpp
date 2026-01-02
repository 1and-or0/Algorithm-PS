#include <iostream>
#include <vector>
using namespace std;

enum Point_t
{
    start, end
};

struct _point
{
    double x;
    Point_t where;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    const int MAX_X = 100; // 좌표 범위 (6자리 정수 가정)
    vector<int> diff(2*MAX_X + 2, 0);

    // 입력 구간 반영
    for (int i = 0; i < n; i++)
    {
        int x1, x2;
        cin >> x1 >> x2;

        diff[x1 + 100] += 1;   // 구간 시작점에서 +1
        diff[x2 + 100] -= 1;   // 구간 끝 다음 좌표에서 -1
    }

    int curr = 0;
    int max_cnt = 0;
    int best_start = 0, best_end = 0;

    bool in_max_interval = false;

    // 좌표 순회 (Counting Sort처럼 좌표 범위 전체를 순차 확인)
    for (int x = 0; x < MAX_X* 2 + 1; x++)
    {
        curr += diff[x];

        if (curr > max_cnt)
        {
            max_cnt = curr;
            best_start = x - 100;
            in_max_interval = true;
        }
        else if (in_max_interval && curr < max_cnt)
        {
            best_end = x - 100;
            in_max_interval = false;
        }
    }

    cout << max_cnt << endl;
    //cout << "max count: " << max_cnt << "\n";
    //cout << "max: [" << best_start << ", " << best_end << "]\n";

    return 0;
}
