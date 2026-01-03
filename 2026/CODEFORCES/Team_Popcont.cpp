/*
* https://codeforces.com/problemset/problem/231/A
* CODEFORCES A. Team
*/
#include <iostream>
#include <bit> // C++20 std::popcount

#define endl "\n"

using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int mask = (a << 2) | (b << 1) | c;
        // popcount는 비트 내에 1이 몇개 들어있는지를 세어냄.
        if (popcount((unsigned int)mask) >= 2) {
            cnt += 1;
        }
    }
    cout << cnt;

    return 0;
}