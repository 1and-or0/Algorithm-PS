#include <bits/stdc++.h>

using namespace std;

int main4()
{
	int n;
	vector<int> arr;

	cin >> n;
	
	for (int i = 0; i < n; ++i)// vector<int>에 입력받은 숫자 추가
	{
		int x;
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());

	int result = 0; // 만들어질 수 있는 총 모험가 그룹 수 
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		// 현재 그룹에 모험가 포함
		count += 1;
		if (count >= arr[i])
		{
			result += 1;
			count = 0;
		}
	}

	cout << result << endl;

	return EXIT_SUCCESS;
}