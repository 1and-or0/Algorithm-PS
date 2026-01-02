#ifndef BJ_2744_CPP
#define BJ_2744_CPP
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#endif // !BJ_2744_CPP

int main()
{
	for (int i = 0; i < 100; ++i)
	{
		char temp;
		scanf("%c", &temp);
		if (temp == '\n')
			break;
		else if ('a' <= temp && temp <= 'z')
			temp -= 'a' - 'A';
		else if ('A' <= temp && temp <= 'Z')
			temp += 'a' - 'A';
		printf("%c", temp);
	}
	return EXIT_SUCCESS;
}