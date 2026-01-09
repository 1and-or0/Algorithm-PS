#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("speeding.in", "r", stdin);
    //freopen("speeding.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<int> limit_at(100);
    int current_pos = 0;
    for (int i = 0; i < n; i++)
    {
        int length, speed;
        cin >> length >> speed;
        for (int j = 0; j < length; j++)
        {
            limit_at[current_pos++] = speed;
        }
    }

    vector<int> bessie_at(100);
    current_pos = 0;
    for (int i = 0; i < m; i++)
    {
        int length, speed;
        cin >> length >> speed;
        for (int j = 0; j < length; j++)
        {
            bessie_at[current_pos++] = speed;
        }
    }

    int max_over = 0;
    for (int i = 0; i < 100; i++)
    {
        int diff = bessie_at[i] - limit_at[i];
        if (diff > max_over)
        {
            max_over = diff;
        }
    }

    cout << max_over << endl;

    return 0;
}