#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	string* numToName = new string[100000]; // 인덱스를 통해 이름 접근, 번호 = 인덱스 + 1
	map<string, int> nameToNum; // 이름을 통해 인덱스 접근, 번호 = 인덱스 + 1

	for (int i = 0; i < n; ++i)
	{
		string temp;
		cin >> temp;
		numToName[i] = temp;
		nameToNum[temp] = i;
	}

	for (int i = 0; i < m; ++i)
	{
		string temp;
		cin >> temp;
		if ('0' > temp[0] || '9' < temp[0])
		{ // 이름을 알 때, 인덱스 + 1 = 번호
			cout << nameToNum[temp] + 1 << "\n";
		}
		else
		{ // 번호를 알 때, 번호 - 1 = 인덱스
			cout << numToName[stoi(temp) - 1] << "\n";
		}
	}
	return 0;
}