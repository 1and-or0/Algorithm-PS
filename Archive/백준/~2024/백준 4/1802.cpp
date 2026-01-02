#include <iostream>
#define endl "\n"
using namespace std;

int t;
bool is_visit[3000] = { 0 };

bool check(int mid, string s)
{
	if (is_visit[mid])
		return true;

	is_visit[mid] = true;

	if (mid - 1 < 0 || mid + 1 >= s.size())
		return true;

	char left = s[mid - 1];
	char right = s[mid + 1];
	
	if (left == right)
		return false;

	return (check(mid-2, s) && check(mid+2, s));
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		string s;
		cin >> s;
		
		if (check(s.size() / 2, s))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}


	return 0;
}