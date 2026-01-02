#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n_z = 0, n_o = 0;

    int arr[41][2] = { 0 };
    arr[0][0] = 1, arr[0][1] = 0;
    arr[1][0] = 0, arr[1][1] = 1;
    //arr[2][0] = 1, arr[2][1] = 1;

    for (int i = 2; i < 41; ++i)
    {
        arr[i][0] = arr[i - 2][0] + arr[i - 1][0];
        arr[i][1] = arr[i - 2][1] + arr[i - 1][1];
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int an;
        cin >> an;
        cout << arr[an][0] << ' ' << arr[an][1] << '\n';
    }
    return 0;
}