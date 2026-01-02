#ifndef BJ_11866_CPP
#define BJ_11866_CPP
#include <bits/stdc++.h>
using namespace std;
#endif // !BJ_11866_CPP

#include <bits/stdc++.h>

int main_BJ_11866_CPP(void) 
{
    int n = 0, k = 0;
    cin >> n >> k;

    vector<int> v;
    int i;
    for (i = 1; i < n + 1; ++i)
        v.push_back(i);
    
    cout << '<';
    int index = k - 1;
    while (n != 1)
    {
        cout << v[index] << ', ';
        /*v.erase(v.begin() + index);
        if (index > n)
            index = index - n;
        else
            index += -1 + k;

        n -= 1;*/
    }
    cout << v[0] << '>';

    return 0;
}