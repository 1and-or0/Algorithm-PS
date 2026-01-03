#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long k, n, w;
    cin >> k >> n >> w;

    // 등차수열의 합 공식: k * w * (w + 1) / 2
    long long total_price = k * w * (w + 1) / 2;

    // 필요한 금액이 가진 돈보다 적으면 0을 출력해야 하므로 max 활용
    long long borrow = max(0LL, total_price - n);

    cout << borrow << endl;

    return 0;
}