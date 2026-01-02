#include <iostream>

using namespace std;

int a, b, c, d;

int main() {
    cin >> a >> b;
    cin >> c >> d;

    // Please write your code here.
    bool isLap = !(b < c || d < a);

    // 겹친다면
    if (isLap)
    {
        int min = a > c ? c : a;
        int max = b > d ? b : d;
        cout << max - min << endl;
    }
    else // 겹치지 않는다면
    {
        cout << b - a + d - c << endl;
    }

    return 0;
}