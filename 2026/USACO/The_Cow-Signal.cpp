/*
* https://usaco.org/index.php?page=viewproblem2&cpid=665
* USACO 2016 December Contest, Bronze
* Problem 3. The Cow-Signal
*/
#include <iostream>
#include <array>
#define endl "\n"

using namespace std;

int main() {
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    
    int m, n, k;
    cin >> m >> n >> k;

    const int n_max = 10;
    array<string, n_max> inputs;

    for (int i = 0; i < m; i++)
    {
        cin >> inputs[i];
    }

    // for a single character
    for (int i = 0; i < m; i++)
    {
        // k-times for height
        for (int j = 0; j < k; j++)
        {
            // k-times for width
            for (int ii = 0; ii < n; ii++)
            {
                char c = inputs[i][ii];

                for (int jj = 0; jj < k; jj++)
                {
                    cout << c;
                }
            }
            cout << endl;
        }
    }

    return 0;
}