/*
* https://codeforces.com/problemset/problem/4/A
* CODEFORCES A. Watermelon
*/
#include <iostream>

#define endl "\n"

using namespace std;

int main() {
    int w;
    cin >> w;

    // w에서 2를 뺐을 때, 0보다 큰 짝수가 나오면 YES, 아니면 NO
    int b = w - 2;
    if (b > 0 and b % 2 == 0) {
        cout << "YES"; // << endl;
    }
    else {
        cout << "NO"; // << endl;
    }

    return 0;
}