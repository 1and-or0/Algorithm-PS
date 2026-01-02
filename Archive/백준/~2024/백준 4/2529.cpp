#include <iostream>
#include <string>
#define endl "\n"
using namespace std;

int k;
const int k_max = 9;
char map[k_max] = { 0 };
bool used[k_max + 1] = { 0 };
string ans_min = "9999999999";
string ans_max = "0000000000";

bool my_comp(int a, char op, int b)
{
	if (op == '<')
		return (a < b);
	else if (op == '>')
		return (a > b);
}

void func(bool used[k_max+1], const int cnt, const string left)
{
	if (cnt == k + 1 )
	{
		if (ans_min > left)
		{
			ans_min = left;
		}

		if (ans_max < left)
		{
			ans_max = left;
				
		}
		return;
	}

	for (int i = 0; i < k_max + 1; i++)
	{
		if (used[i])
			continue;

		if (left == "")
		{
			used[i] = true;
			func(used, cnt + 1, left + to_string(i));
			used[i] = false;
		}
		else if (my_comp(left[cnt - 1] - '0', map[cnt - 1], i))
		{
			used[i] = true;
			func(used, cnt + 1, left + to_string(i));
			used[i] = false;
		}
	}
}

int main()
{
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> map[i];
	}

	func(used, 0, "");
	
	cout << ans_max << endl;
	cout << ans_min << endl;

	return 0;
}