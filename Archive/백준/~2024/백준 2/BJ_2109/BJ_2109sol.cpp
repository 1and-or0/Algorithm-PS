#include <bits/stdc++.h>
using namespace std; 

int main() 
{	
	priority_queue <int, vector<int>, greater<int>> q; //우선순위 큐.min heap
	int n; cin >> n; // 입력받기
	vector <pair<int, int>> v; 
	int p, d; 
	for (int i = 0; i < n; i++) 
    {
		cin >> p >> d; 
		v.push_back({ d,p }); 
	}
	sort(v.begin(), v.end()); // d(날짜) 기준 오름차순대로 정렬.  
	
    for (int i = 0; i < n; i++)  // 입력받은 vector 의 길이만큼
    { // 우선순위 큐에 p를 모두 넣어주네
		q.push(v[i].second);  
		if (q.size() > v[i].first)  
        { // 우선순위 큐의 크기가 vector의 날짜보다 커지면, pop을 해?
			q.pop(); 
		}
	}
	
    int sum = 0; 
	while (!q.empty())
    {
		sum += q.top(); 
		q.pop(); 
	}
	cout << sum << "\n"; 

    return 0;
}