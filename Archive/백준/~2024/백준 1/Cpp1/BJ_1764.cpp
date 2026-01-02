#include <bits/stdc++.h>
using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string temp;
	int n, m;
	cin >> n >> m;

	vector<string> vecN, vec;

	for (int i = 0; i < n; i++) 
	{
		cin >> temp;
		vecN.push_back(temp);
	}
	sort(vecN.begin(), vecN.end());

	for (int i = 0; i < m; i++) 
	{
		cin >> temp;
		if (binary_search(vecN.begin(), vecN.end(), temp))
			vec.push_back(temp);
	}

	sort(vec.begin(), vec.end());
	int size = vec.size(), i;
	cout << vec.size() << endl;
	for (i = 0; i < size - 1; i++) 
	{
		cout << vec.at(i) << "\n";
	}
	if (size != 0)
		cout << vec.at(i);
}