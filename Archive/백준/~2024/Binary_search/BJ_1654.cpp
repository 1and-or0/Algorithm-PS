#ifndef BJ_1654_CPP
#define BJ_1654_CPP
#include <bits/stdc++.h>
using namespace std;
#endif // !BJ_1654_CPP

long long howManyLine(const long long* p_a, const long long len_of_arr, const long long len_of_a_line)
{
    long long result = 0;
    for (long long i = 0; i < len_of_arr; ++i)
    {
        result += (p_a[i] / len_of_a_line);
    }

    return result;
}

int main()
{
    long long k, n;
    cin >> k >> n;
    long long* p_arr = new long long[k];
    long long max = 0; 
    for (long long i = 0; i < k; ++i)
    {
        long long temp;
        cin >> temp;
        p_arr[i] = temp;
        max = temp > max ? temp : max;
    }
    
    long long start = 1, target_len; 
    long long howMany = 0;
    max++;
    while (start + 1 < max)
    {
        target_len = (start + max) / 2;
        howMany = howManyLine(p_arr, k, target_len);
        if (howMany >= n)
            start = target_len;
        else
            max = target_len;
    }
    cout << start;

    delete[] p_arr;
    return EXIT_SUCCESS;
}