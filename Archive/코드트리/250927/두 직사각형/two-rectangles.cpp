#include <iostream>

using namespace std;

int x1, y1, x2, y2;
int a1, b1, a2, b2;

int main() {
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> a1 >> b1 >> a2 >> b2;

    // Please write your code here.
    bool isLap = true;

    if (x2 < a1) // box1 box2
    {
        isLap = false;
    }
    else if (a2 < x1) // box2 box1
    {
        isLap = false;
    }
    else if (b2 < y1) // box1/box2
    {
        isLap = false;
    }   
    else if (y2 < b1) // box2/box1
    {
        isLap = false;
    }

    if (isLap)
    {
        cout << "overlapping" << endl;
    }
    else
    {
        cout << "nonoverlapping" << endl;
    }

    return 0;
}