#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int n, k;
vector<pair<int, int>> v;
vector<int> bag;

priority_queue<int> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    // 보석 정보 입력
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second; // {무게, 가격}
    }
    sort(v.begin(), v.end()); // 무게를 기준으로 정렬

    // 가방 정보 입력
    bag.resize(k);
    for (int i = 0; i < k; i++)
    {
        cin >> bag[i];
    }
    sort(bag.begin(), bag.end()); // 용량을 기준으로 정렬

    long long ans = 0;
    int index_jewel = 0;

    for (int i = 0; i < k; i++) // 각 가방에 대해
    {
        // 현재 가방에 넣을 수 있는 모든 보석을 우선순위 큐에 추가
        while (index_jewel < n && v[index_jewel].first <= bag[i])
        {
            pq.push(v[index_jewel].second);
            index_jewel++;
        }

        // 가장 비싼 보석을 선택해 가방에 넣음
        if (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << endl;
    return 0;
}
