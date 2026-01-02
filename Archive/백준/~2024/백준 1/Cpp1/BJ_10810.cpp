#ifndef BITS_STDC_H2
#define BITS_STDC_H2
#include <bits/stdc++.h>
using namespace std;

#endif // !BITS_STDC_H2

int main_bj_10810()
{
    int n, m;
    cin >> n >> m;

    int* p_a = new int[n];

    for (int i = 0; i < n; ++i)
        p_a[i] = 0;

    int start = 0, end = m - 1, ball_num = -1;

    for (int i = 0; i < m; ++i)
    {
        cin >> start >> end >> ball_num;
        for (int j = start - 1; j < end; ++j)
        {
            p_a[j] = ball_num;
        }
    }

    for (int i = 0; i < n; ++i)
        cout << p_a[i] << ' ';

    delete[] p_a;


	return EXIT_SUCCESS;
}