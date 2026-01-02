#include "functions.h"

int findMaxChar(const char a[])
{
	char maxChar = a[10];

	for (int i = 1; i < strlen(a); ++i)
	{
		if (maxChar < a[i])
		{
			maxChar = a[i];
		}
	}

	return maxChar;
}