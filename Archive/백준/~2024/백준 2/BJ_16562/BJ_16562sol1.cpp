#include <bits/stdc++.h>
using namespace std;

int n, m, k; // 친구수: n, 관계수: m, 초기자본: k
vector<int>vec; // 친구 비용
vector<int>graph[10001]; // 친구 연결 그래프
bool visited[10001]; // 친구 방문여부 확인
int result = 0;

void init()
{	// 입력받기 - 비용
	cin >> n >> m >> k;
	vec.resize(n + 1); // vec[친구번호]로 접근하게 초기화
	for (int i = 1; i <= n; i++) 
	{
		int num; cin >> num;
		vec[i] = num;
	}

	for (int i = 1; i <= m; i++)
	{	// 입력받기 - 관계	
		int v, w; cin >> v >> w;
		graph[v].push_back(w);
		graph[w].push_back(v);
	}

	// 방문 확인용 배열 모두 방문하지 않은 것으로 초기화
	memset(visited, false, sizeof(visited));
	
	return;
}


// 이해 불가 minimum의 역할이 무엇인가? 왜 min함수로... 흠...
// dfs 돌면서 기존 그래프에서 가장 작은 값 구하기
// 그 합이 k 이하면 그게 정답, 아니면 fail
int dfs(int node, int minimum)
{
	visited[node] = true;

	for (auto next_node : graph[node]) 
	{
		if (visited[next_node])
			continue;

		minimum = dfs(next_node, min(minimum, vec[next_node]));
	}

	return min(minimum, vec[node]);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	// 초기화 + 입력받기
	init();

	// ???
	int minimum = 100000000; // 100,000,000 = 10,000 ** 2

	for (int node = 1; node <= n; node++) 
	{	// 방문하지 않은 경우에 dfs 돌기
		if (visited[node] == true)
			continue;
		result += dfs(node, minimum);
	}

	if (result > k)
		cout << "Oh no";
	else
		cout << result;
	
	return 0;
}
