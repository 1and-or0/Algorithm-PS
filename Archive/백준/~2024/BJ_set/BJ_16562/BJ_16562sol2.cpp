#include <bits/stdc++.h>
using namespace std;

int parent[10001]; // parent[노드 번호] == 부모 노드 번호
int cost[10001]; // 

// 최상위 부모를 찾는 파인드 함수
int find(int x) 
{
    if (parent[x] == x) 
        return x;

    return parent[x] = find(parent[x]);
}

// 두 그룹을 합치는 유니온 함수
void merge_parent(int a, int b) 
{
    a = find(a);
    b = find(b);
    if (a != b) 
    {
        // 비용이 낮은 것을 부모로 설정
        if (cost[a] > cost[b]) parent[a] = b;
        else parent[b] = a;
    }
}

int main() 
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N, M, k;
    cin >> N >> M >> k;

    // 초기화 = 자기 자신을 부모로 설정
    for (int i = 0; i <= 10000; i++)
        parent[i] = i;
    for (int i = 1; i <= N; i++)
        cin >> cost[i];
    for (int i = 0; i < M; i++) 
    {
        int v, w;
        cin >> v >> w;
        merge_parent(v, w);
    }

    unordered_set<int> s;

    // 집합에 각 친구의 최상위 부모를 담음(중복 제거)
    for (int i = 1; i <= N; i++)
    {
        s.insert(find(i));
    }
    int ans = 0;

    // 중복이 제거된후 그 비용을 담음
    for (auto it : s) 
    {
        ans += cost[it];
        k -= cost[it];
    }
    // k원이 0이상이라면 성공
    if (k >= 0)
        cout << ans;
    else
        cout << "Oh no";

    return 0;
}