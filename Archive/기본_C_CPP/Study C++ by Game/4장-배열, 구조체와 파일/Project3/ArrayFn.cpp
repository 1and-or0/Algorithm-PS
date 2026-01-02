#include "functions.h"

void addDescending(int a[], int len, int val)
{
	if (val > a[len - 1])
	{
		a[len - 1] = val;
		for (int i = len - 1; i > 0; --i)
		{
			if (val < a[i-1])
				return;
			a[i] = a[i - 1];
			a[i - 1] = val;
		}
	}
}


void printArray(const int a[], int len, const char msg[] )
{
	printf("%s: ", msg);
	for (int i = 0; i < len; ++i)
	{
		printf("%3d", a[i]);
	}
	printf("\n");
}

void reverseArray(const int a[], int b[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		b[len - i - 1] = a[i];
	}
}

void reverseString(const char src[], char dst[])
{
	int len = strlen(src);
	for (int i = 0; i < len; ++i)
	{
		dst[len - i - 1] = src[i];
	}
	dst[len] = '\0'; // 오... 이거 해주면 매우 있어보이는 코드임. (없어도.. 큰 문제는 없을것 같지만)
}
