#ifndef BJ_11050_C
#define BJ_11050_C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#endif // !BJ_11050_C
static int factorial(int num)
{
	if (num < 0)
		return -1;

	int factorial = 1;
	for (int i = 2; i < num + 1; ++i)
		factorial *= i;
	return factorial;
}

int main_BJ_11050_C()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int result = factorial(n) / (factorial(k) * factorial(n-k));
	printf("%d\n", result);
	return 0;
}