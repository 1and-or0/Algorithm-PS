#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main(void) 
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;

	// rate: 각 주차 공간의 요금, weight: 각 차량의 무개
	vector<int> rate(n + 1), weight(m + 1);
	for (int i = 1; i <= n; i++)
		cin >> rate[i];
	for (int i = 1; i <= m; i++)
		cin >> weight[i];

	set<int> s; // 모든 주차 구역 번호
	for (int i = 1; i <= n; i++)
		s.insert(i);

	int ans = 0;
	unordered_map<int, int> pos;  // 차량이 주차된 장소 번호
	queue<int> q;  // 주차 출입기록
	for (int i = 0; i < 2 * m; i++)
	{
		int car; cin >> car;

		if (car > 0) 
			q.push(car);
		else 
		{
			s.insert(pos[-car]); // 차량이 주차되어 있던 구역 다시 자리가 남
			pos.erase(-car); // 주차후 다시 나간 차량에 대해 이미 저장된 정보 지우기
		}

		while (!q.empty() && !s.empty()) 
		{
			set<int>::iterator iter = s.begin();
			pos[q.front()] = *iter; // 차량이 주차된 구역 번호 저장 by map
			ans += weight[q.front()] * rate[*iter];
			s.erase(*iter); // 해당 주차 구역이 비어있지 않음
			q.pop(); // 처리한 차량 출입기록 큐에서 삭제
		}
	}

	cout << ans << '\n';
	
	return 0;
}