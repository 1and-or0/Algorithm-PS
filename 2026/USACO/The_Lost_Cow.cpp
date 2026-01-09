/*
* https://usaco.org/index.php?page=viewproblem2&cpid=735
* USACO 2017 US Open Contest, Bronze
* Problem 1. The Lost Cow
*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    long long x, y;
    if (!(cin >> x >> y)) return 0;

    if (x == y)
    {
        cout << 0 << endl;
        return 0;
    }

    long long gap = abs(x - y);

    // 1. 최소 지수 k 계산 (O(1))
    // log2의 정밀도 문제를 방지하기 위해 정수 연산이나 ceil 사용
    int k = (gap == 1) ? 0 : (int)ceil(log2((double)gap));

    // 2. 방향성 검증을 통한 최종 n 확정
    int n = k;
    if (y > x) // 베시가 오른쪽 (n은 짝수여야 함)
    {
        if (n % 2 != 0) n++;
    }
    else // 베시가 왼쪽 (n은 홀수여야 함)
    {
        if (n % 2 == 0) n++;
    }

    // 3. 수식 적용 (O(1))
    long long total_dist = 0;

    if (n > 0)
    {
        // n-1 항까지의 누적합 공식 (1, 3, 6, 12... 수열의 합)
        // 1 + 3 * (2^(n-1) - 1)
        long long power_n_minus_1 = (long long)pow(2, n - 1);
        total_dist = 1 + 3 * (power_n_minus_1 - 1);

        // 마지막 이동: 직전 도착지에서 베시(y)까지의 직선 거리
        // 직전 도착지는 x를 기준으로 2^(n-1)만큼 반대편에 있음
        total_dist += power_n_minus_1 + gap;
    }
    else
    {
        // n이 0인 경우 (x=1, y=2 같이 첫 이동에 바로 찾는 경우)
        total_dist = gap;
    }

    cout << total_dist << endl;

    return 0;
}