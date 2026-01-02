#include <bits/stdc++.h>
using namespace std;

void addFromString(string::iterator start, const int len, int* whereAdd);

int main()
{
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

	int positive = 0, negative = 0;
	string str;
	cin >> str;

	bool plusLeft = true;
	int _index = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (plusLeft)
				addFromString(str.begin() + _index, i - _index, &positive);
			else
				addFromString(str.begin() + _index, i - _index, &negative);

			_index = i + 1;

			if (str[i] == '-' && plusLeft)
				plusLeft = false;
		}
		else if (i == str.size() - 1)
		{
			if (plusLeft)
				addFromString(str.begin() + _index, i - _index + 1, &positive);
			else
				addFromString(str.begin() + _index, i - _index + 1, &negative);
		}
	}

	cout << positive - negative;
	return 0;
}

void addFromString(string::iterator start, const int len, int* whereAdd)
{
	stringstream ss;
	string num;
	for (int i = 0; i < len; ++i)
		num += start[i];

	ss << num;
	int temp = 0;
	ss >> temp;

	*whereAdd += temp;
}
