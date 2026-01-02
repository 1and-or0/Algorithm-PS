#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int n;
const int n_max = 500000;
long long total_depth_sum = 0;
vector<vector<int>> map(n_max + 1); // +1 to match 1-based indexing
bool is_visit[n_max + 1] = { 0 };

void dfs(int num, int depth)
{
    is_visit[num] = true;
    bool is_leaf = true;

    for (auto node : map[num])
    {
        if (!is_visit[node])
        {
            is_leaf = false;
            dfs(node, depth + 1);
        }
    }

    if (is_leaf)
    {
        total_depth_sum += depth;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        map[a].push_back(b);
        map[b].push_back(a);
    }

    dfs(1, 0);

    if (total_depth_sum % 2 == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
