#include <bits/stdc++.h>
using namespace std;

int main()
{ // 왜 que에 원소가 남아있으면 안된다는 생각을 했을까...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // 우선순위 큐(오름차순 정렬)
    priority_queue<int, vector<int>, greater<>> pq;
    int sum = 0;
    int n; cin >> n;
    
    // 입력
    for (int i = 0; i < n; i++) 
    {
        int num;
        cin >> num;
        pq.push(num);
    }
    
    // 두개 꺼내고 다시 넣어줌
    while (1) 
    {    // 사이즈 1이면 지금까지의 합 출력
        if (pq.size() == 1)
        {
            cout << sum;
            break;
        }

        int temp1, temp2;
        temp1 = pq.top(); pq.pop();
        temp2 = pq.top(); pq.pop();

        sum += temp1 + temp2;
        pq.push(temp1 + temp2);
    }

	return 0;
}