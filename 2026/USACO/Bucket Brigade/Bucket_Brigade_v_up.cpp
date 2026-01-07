/*
* https://usaco.org/index.php?page=viewproblem2&cpid=939
* USACO 2019 US Open Contest, Bronze
* Problem 1. Bucket Brigade
* 
* 보완한 버전
*/
#include <iostream>
#include <queue>
#include <algorithm> // std::size (C++17)

#define endl "\n"

using namespace std;

// 매직 넘버 제거 및 전역 상수화
const int N = 10;
char farm[N][N]; // 0으로 자동 초기화됨 (전역 변수의 특징)

struct Pos
{
    int x, y;

    // 생성자 간소화
    Pos(int x = 0, int y = 0) : x(x), y(y) {}

    // 1. const Reference 사용: 불필요한 복사 방지
    // 2. const Method 선언: 이 함수는 멤버 변수를 수정하지 않음을 명시
    bool operator==(const Pos& other) const
    {
        return x == other.x && y == other.y;
    }
};

// 방향 배열도 변하지 않으므로 const 처리
const int dx[] = { 0, 1, -1, 0 };
const int dy[] = { 1, 0, 0, -1 };

// 인라인으로 처리해도 될 만큼 간단한 함수들은 굳이 분리하지 않아도 되지만,
// 가독성을 위해 유지한다면 아래와 같이 작성합니다.
bool is_out_of(const Pos& pos)
{
    // [버그 수정] x, y 모두 0 미만, N 이상인지 체크
    return pos.x < 0 || pos.x >= N || pos.y < 0 || pos.y >= N;
}

// 2차원 배열을 매개변수로 넘길 때는 vector를 쓰거나, 
// PS에서는 편의상 전역 변수(visited)를 많이 사용합니다.
// 여기서는 함수 인자로 넘기는 정석적인 방법을 보여드립니다.
void bfs(const Pos& start, const Pos& end, int& ans, bool visited[N][N])
{
    // 큐에는 {좌표, 거리}를 저장
    queue<pair<Pos, int>> q;

    visited[start.x][start.y] = true;
    q.push({ start, 0 });

    while (!q.empty())
    {
        Pos now = q.front().first;
        int dist = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) // size(dx) 대신 상수 4 사용이 더 일반적
        {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            Pos nextPos{ nx, ny }; // Uniform Initialization

            // 1. 범위 벗어남 체크
            if (is_out_of(nextPos)) continue;

            // 2. 바위('R') 체크
            if (farm[nx][ny] == 'R') continue;

            // 3. 방문 여부 체크
            if (visited[nx][ny]) continue;

            // 목적지 도착?
            if (nextPos == end)
            {
                // 거리가 D일 때, 사이의 소 개수는 D-1개
                // 현재 로직: dist는 'now'까지의 거리. 
                // nextPos까지는 dist+1. 따라서 소 개수는 (dist+1)-1 = dist.
                ans = dist;
                return;
            }

            // [중요] 큐에 넣을 때 방문 처리 (메모리 초과 방지)
            visited[nx][ny] = true;
            q.push({ nextPos, dist + 1 });
        }
    }
}

int main()
{
    // 실행 속도 향상 (C++ I/O와 C I/O 동기화 끊기)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

     freopen("buckets.in", "r", stdin);
     freopen("buckets.out", "w", stdout);

    Pos barn, lake;

    // 지역 변수로 선언 시 반드시 초기화 필요. 
    // 전역으로 빼거나 {0}으로 초기화 추천.
    bool visited[N][N] = { false };

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> farm[i][j];
            if (farm[i][j] == 'B') barn = { i, j };
            else if (farm[i][j] == 'L') lake = { i, j };
        }
    }

    int ans = 0;
    bfs(barn, lake, ans, visited);

    cout << ans << endl;

    return 0;
}