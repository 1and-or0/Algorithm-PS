#include <iostream>

using namespace std;

int x1, x2, x3, x4;

int main() {
    cin >> x1 >> x2 >> x3 >> x4;

    // Please write your code here.
    bool isLap = !(x2 < x3 ||x4 < x1);

    if (isLap)
        cout << "intersecting" << endl;
    else
        cout << "nonintersecting" << endl;
    return 0;
}