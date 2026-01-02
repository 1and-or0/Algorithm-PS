#ifndef BJ_2475
#define BJ_2475
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#endif // !BJ_2475

int main_BJ_2475_C()
{
	int arr[5] = { 1 };
	int sum = 0;

	for (int i = 0; i < 5; ++i)
	{
		scanf("%d", &arr[i]);
		arr[i] *= arr[i];
		sum += arr[i];
	}

	printf("%d\n", sum % 10);

	return 0;
}