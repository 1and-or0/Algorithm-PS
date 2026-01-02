#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

int n, k;
vector<int> sockets;
vector<int> inputs;

bool is_in_sockets(int device)
{
    for (int plugged_in : sockets)
    {
        if (plugged_in == device)
            return true;
    }
    return false;
}

int find_replace_index(int start)
{
    int farthest_index = -1, replace_index = -1;

    for (int i = 0; i < n; i++)
    {
        int next_use = k; // 기본적으로 다시 사용되지 않는 경우
        for (int j = start; j < k; j++)
        {
            if (inputs[j] == sockets[i])
            {
                next_use = j;
                break;
            }
        }

        if (next_use > farthest_index)
        {
            farthest_index = next_use;
            replace_index = i;
        }
    }
    return replace_index;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    inputs.resize(k);
    for (int i = 0; i < k; i++)
    {
        cin >> inputs[i];
    }

    int unplug_count = 0;

    for (int i = 0; i < k; i++)
    {
        if (is_in_sockets(inputs[i]))
            continue;

        if (sockets.size() < n)
        {
            sockets.push_back(inputs[i]);
        }
        else
        {
            int replace_index = find_replace_index(i + 1);
            sockets[replace_index] = inputs[i];
            unplug_count++;
        }
    }

    cout << unplug_count << endl;

    return 0;
}
