/*
* https://usaco.org/index.php?page=viewproblem2&cpid=1059
* USACO 2020 December Contest, Bronze
* Problem 1. Do You Know Your ABCs?
* Return to Problem List
*/
#include <iostream>
#include <algorithm>
#define endl "\n"

using namespace std;

int main() {
    int arr[7] = { 0 };
    for (int i = 0; i < size(arr); i++)
    {
        cin >> arr[i];
    }

    // 오름차순 정렬 sorting asc
    sort(begin(arr), begin(arr) + size(arr));

    int a, b, c;
    a = arr[0];
    b = arr[1];
    c = arr[size(arr) - 1] - a - b;

    cout << a << " " << b << " " << c;

    return 0;
}