#include <iostream>

using namespace std;

int a, b, c, d;

int main() {
    cin >> a >> b;
    cin >> c >> d;

    // Please write your code here.
    int arr[100 + 1] = { 0 };

    arr[a] += 1;
    arr[b] -= 1;
    arr[c] += 1;
    arr[d] -= 1;
    
    int ans = 0; //청소된 구역
    int ans_start = -1, ans_end = -1;
    bool is_started = false, is_ended = false;
    int cnt = 0;
    for (int i = 0; i < 100 + 1; i++)
    {
        cnt += arr[i];
        if (cnt > 0 && !is_started)
        {
            is_started = true;
            ans_start = i;
        }
        else if (cnt == 0) // 청소끝난 부분
        {
            // 청소를 시작하지 않았다면
            if (!is_started)
            {
                continue;
            }

            is_started = false;
            ans_end = i;
            ans += ans_end - ans_start;
        }

    }

    cout << ans << endl;

    return 0;
}