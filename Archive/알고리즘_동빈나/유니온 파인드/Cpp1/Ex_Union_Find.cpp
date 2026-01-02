#include <bits/stdc++.h>
using namespace std;

// 인덱스 == (노드: 1~8), 
// 값 == 각 노드가 가지는 값
int parent[9];

int find(int x);
void merge(int x, int y);
bool isUnion(int x, int y);

int main()
{
	// 배열 초기화
	for (int i = 1; i <= 8; i++)
		parent[i] = i;

	merge(1, 2);
	merge(4, 5);
	merge(5, 6);

	cout << "2와 4같은 집합인가?\n";
	cout << isUnion(2, 4) << "\n"; // false

	merge(1, 5);

	cout << "2와 4같은 집합인가?\n";
	cout << isUnion(2, 4) << "\n"; // true

	return 0;
}

// 부모 노드들을 거쳐 루트 노드를 찾는 함수
int find(int x)
{	// 배열 인덱스와 값이 같다면, 해당 값 리턴
	// == 루트 노드임
	if (parent[x] == x)
		return x;

	// 배열의 값을 인덱스로 갖는 값 리턴
	// == 부모 노드의 부모 노드를 찾기 (재귀)
	return parent[x] = find(parent[x]);
}

// x노드에 y노드를 자식 노드로 연결하는 함수
void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	
	// x와 y가 같은 부모 노드와 연결됨 
	// == x, y는 이미 연결됨
	if (x == y)
		return;

	// 배열[y] = x로 저장 == 노드 연결함
	parent[y] = x;

	return;
}

// 두 노드가 연결되어있는지 판별하는 함수
bool isUnion(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x == y)
		return true;
	
	return false;
}
