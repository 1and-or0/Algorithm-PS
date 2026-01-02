#include <bits/stdc++.h>
using namespace std;

int main_ex_queue()
{
	queue<int> q;

	q.push(5);
	q.push(2);
	q.push(3);
	q.push(7);

	q.pop();

	q.push(1);
	q.push(4);

	q.pop();

	// 먼저 들어온 원소부터 출력(추출)
	while (!q.empty())
	{
		cout << q.front() << ' ';
		q.pop();
	}

	return EXIT_SUCCESS;
}