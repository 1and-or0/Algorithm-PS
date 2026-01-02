#include <iostream>
using namespace std;

// 최대공약수 (GCD)를 구하는 함수
int gcd(int a, int b) 
{
    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// 최소공배수 (LCM)를 구하는 함수
int lcm(int a, int b) 
{
    return a * b / gcd(a, b);
}

int main() 
{
    int T; // 테스트 케이스의 수
    cin >> T;

    while (T--) 
    {
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        // 가능한 해가 있는지 찾기 위해 반복
        bool found = false;
        // M을 기준으로 x에서 시작, LCM(M, N) 안에서만 탐색
        int limit = lcm(M, N); // LCM(M, N) 안에서 해를 찾는다.
        for (int k = x; k <= limit; k += M) 
        {
            // y를 만족하는 해를 찾으면 출력
            if ((k - 1) % N + 1 == y) 
            {
                cout << k << '\n';
                found = true;
                break;
            }
        }

        // 해를 찾지 못했으면 -1 출력
        if (!found) 
        {
            cout << -1 << '\n';
        }
    }

    return 0;
}
