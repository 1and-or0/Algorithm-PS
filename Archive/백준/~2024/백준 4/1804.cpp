#include <iostream>
#include <string>
using namespace std;

int T;
string s;

bool func(int L, int R) 
{
	if (L == R) 
		return 1;
	
	int mid = (L + R) / 2;
	
	for (int i = mid - 1, j = mid + 1; i >= L; i--, j++) 
	{
		if (s[i] == s[j]) return 0;
	}
	return func(L, mid - 1);
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) 
	{
		cin >> s;
		if (func(0, s.length() - 1)) cout << "YES\n";
		else cout << "NO\n";
	}
}