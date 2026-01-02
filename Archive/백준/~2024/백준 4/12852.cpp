#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

const int n_max = 1000000;
int dp[n_max + 1] = { 0 }; // dp[i]: i를 1로 만드는 최소 연산 횟수
int map[n_max + 1] = { 0 }; // map[i]: i를 1로 만들 때 바로 이전 숫자

int main()
{
    dp[1] = 0; // 1은 이미 1이므로 연산 횟수가 0
    map[1] = 1; // 1은 자기 자신

    for (int i = 2; i < n_max + 1; i++)
    {
        // 1을 빼는 연산을 기본값으로 설정 (dp[i] = dp[i-1] + 1)
        dp[i] = dp[i - 1] + 1;
        map[i] = i - 1; // 1을 빼서 i-1로 가는 경로 설정

        // 2로 나누어지는 경우, 1을 빼는 연산보다 더 적은 연산으로 가능하면 갱신
        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
        {
            dp[i] = dp[i / 2] + 1; // i를 2로 나누는 경우로 dp[i] 갱신
            map[i] = i / 2; // i를 2로 나눈 결과로 가는 경로 설정
        }

        // 3으로 나누어지는 경우, 역시 1을 빼는 연산이나 2로 나누는 연산보다 적은 연산이면 갱신
        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
        {
            dp[i] = dp[i / 3] + 1; // i를 3으로 나누는 경우로 dp[i] 갱신
            map[i] = i / 3; // i를 3으로 나눈 결과로 가는 경로 설정
        }
    }

    int n;
    cin >> n;

    cout << dp[n] << endl; // n을 1로 만드는 최소 연산 횟수 출력

    // n에서 1로 가는 경로 출력
    while (n > 1)
    {
        cout << n << " ";
        n = map[n];
    }
    cout << 1 << endl; 

    return 0;
}
