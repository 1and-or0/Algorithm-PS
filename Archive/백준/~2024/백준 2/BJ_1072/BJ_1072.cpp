#include <bits/stdc++.h>
using namespace std;
#define X_BORDER 1000000000

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    // 입력받기
    unsigned long long x; cin >> x;
    unsigned long long y; cin >> y;
    unsigned long long z = (unsigned long long) (y*100 / x);

    // <알고리즘 ~ 정답출력>
    if(z >= 99)
        cout << -1 << "\n";
    else
    {
        unsigned long long left = y;
        unsigned long long right = X_BORDER*2;

        while(left + 1 < right)
        {
            unsigned long long mid = (unsigned long long) (left + right) / 2;
            unsigned long long temp = (unsigned long long) (mid*100 / (x + mid - y));
            if(temp == z)
                left = mid;
            else
                right = mid;
        }
        cout << right - y << "\n";
    }
    
    return 0;
}