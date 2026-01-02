#include <bits/stdc++.h>
using namespace std;

int n, room, from, to, answer = 1;

vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> lastTime; // 오름차순 정렬 top == 최소값

int main() 
{   // 빠른 입력
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // 정보 입력받기
	cin >> n;
	for (int i = 0; i < n; i++) 
    {   // room: 방번호, 
		cin >> room >> from >> to;
		v.push_back({ from, to });
	} // default: 오름차순 정렬 - 1: 시작시간 2: 끝나는 시간
	sort(v.begin(), v.end()); 

	for (int i = 0; i < v.size(); i++) 
    {   
		int startTime = v[i].first;
		int endTime = v[i].second;
        // 강의실이 비어있으면
		if (lastTime.empty()) 
        {   // 끝나는 시간을 갱신
			lastTime.push(endTime);
		}
		else // 강의실에 이미 수업이 있는 경우
        {   // 먼저 한 수업의 끝난시간 > 새로 할 강의 시작시간
			if (lastTime.top() > startTime) 
            {   // 같은 강의실에서 수업이 불가능. 겹치므로. 강의실 증가
				answer++;
			}
			else 
            { // 이미 있는 강의실로 들어가면 된다.
				lastTime.pop(); // 끝난 강의는 없애준다.
			} // 어떤 경우에서든 새롭게 시작한 강의의 끝나는 시간을 저장
			lastTime.push(endTime);
		}
	}
	cout << answer;
}