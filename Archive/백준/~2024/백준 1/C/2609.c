#ifndef BJ_2609_C
#define BJ_2609_C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#endif // !BJ_2609_C

int main_BJ_2609_C()
{
	int a = 0, b = 0, a1=0, b1=0;
	scanf("%d", &a);
	scanf("%d", &b);
	
	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	a1 = a;
	b1 = b;

	int r = a1 % b1;
	while (r != 0)
	{
		a1 = b1;
		b1 = r;
		r = a1 % b1;
	}
	printf("%d\n", b1);
	printf("%d\n", a * b / b1);
	return 0;
}