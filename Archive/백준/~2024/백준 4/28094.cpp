#include <iostream>
using namespace std;

int ans, cnt;

void DFS(int depth, int& N, int order[], int cost[11][11])
{
    if (depth == N)
    {
        int hap = 0;
        // 순서에 따른 점수 계산
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                hap += cost[order[i]][order[j]];
            }
        }

        if (hap > ans)
        {
            ans = hap;
            cnt = 1; // 새로운 최대값을 발견하면 경우의 수를 1로 초기화
        }
        else if (hap == ans)
        {
            cnt++; // 같은 점수일 경우 경우의 수를 증가
        }
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        bool used = false;
        for (int j = 0; j < depth; j++)
        {
            if (order[j] == i) // 이미 사용된 작품은 무시
            {
                used = true;
                break;
            }
        }
        if (!used)
        {
            order[depth] = i;
            DFS(depth + 1, N, order, cost); // 다음 깊이로 이동
            order[depth] = -1; // 백트래킹: 현재 선택을 취소
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);

    int T, N, M;
    cin >> T;

    while (T--)
    {
        cin >> N >> M;
        ans = 0;
        cnt = 0;
        int cost[11][11] = { 0 }; // N의 최대값이 9이므로 11x11 배열로 설정
        int order[10]; // 작품의 순서를 저장할 배열 (최대 9개)

        for (int i = 0; i < M; i++)
        {
            int V, A, B;
            cin >> V >> A >> B;
            cost[A][B] += V; // A가 B보다 앞에 있을 때 V만큼의 점수 추가
        }

        DFS(0, N, order, cost);
        cout << ans << " " << cnt << "\n";
    }

    return 0;
}
