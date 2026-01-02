#include <iostream>
#include <cstring>
#define endl "\n"
using namespace std;

const int s_len = 999;
char s[s_len + 1] = { 0 };
char t[s_len + 2] = { 0 };

void MyReversChar(char* destination, char* source)
{
	int len = strlen(source);

	char temp[s_len + 2] = { 0 };
	strcpy_s(temp, source);

	for (int i = 0; i < len; i++)
	{
		destination[i] = temp[len - 1 - i];
	}
}

int main()
{
	cin >> s >> t;
	
	char temp[s_len + 2] = { 0 };
	strcpy_s(temp, t);
	int len = strlen(t);
	while (strlen(temp) > strlen(s))
	{
		if (temp[len-1] == 'A')
		{
			temp[len-1] = NULL;
		}
		else // temp[len] == 'B'
		{
			temp[len-1] = NULL;
			MyReversChar(temp, temp);
		}
		len -= 1;
	}

	if (strcmp(temp, s) == 0)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 0 << endl;
	}
	return 0;
}