#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

// Find 함수: 부모 게이트 찾기
int find(int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    return parent[x] = find(parent[x]); // 경로 압축
}

// Union 함수: 두 집합 병합
void unionGate(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        parent[x] = y; // x의 부모를 y로 설정
    }
}

int main()
{
    int G, P;
    cin >> G >> P;

    parent.resize(G + 1);
    for (int i = 1; i <= G; i++)
    {
        parent[i] = i; // 초기화: 각 게이트가 자기 자신을 부모로 가짐
    }

    int count = 0;
    for (int i = 0; i < P; i++)
    {
        int gi;
        cin >> gi;

        int dockingGate = find(gi); // 현재 가능한 가장 큰 게이트 찾기
        if (dockingGate == 0)
        {
            break; // 더 이상 도킹할 게이트가 없음
        }

        unionGate(dockingGate, dockingGate - 1); // 도킹 후 게이트 병합
        count++;
    }

    cout << count << endl;
    return 0;
}
