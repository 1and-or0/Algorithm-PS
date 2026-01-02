#include <bits/stdc++.h>
using namespace std;

int myMax(const int& a, const int& b, const int& c)
{
    if(a >= b && a >= c)
        return a;
    else if(b >= a && b >= c)
        return b;
    else if(c >= b && c >= a)
        return c;
    return 0;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // 입력받기
    const int n_border = 10000;
    int arr[n_border+1] = {0};
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i+1];
    }
    
    // <알고리즘~>
    int dp[n_border+1] = {0};
    dp[0] = arr[0]; dp[1] = arr[1];
    dp[2] = max(dp[0]+arr[1], dp[0]+arr[1]+arr[2]);
    
    for (int i = 3; i < n+1; i++)
    {
        dp[i] = myMax(dp[i-1], dp[i-2]+arr[i], dp[i-3]+arr[i-1]+arr[i]);
    }
    //<~알고리즘>
    
    // // 정답 출력
    cout << dp[n] << "\n";

    return 0;
}
