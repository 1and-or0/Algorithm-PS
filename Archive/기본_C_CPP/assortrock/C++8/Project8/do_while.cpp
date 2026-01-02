#include <stdio.h>

int main()
{
	int i = 0;
	do
	{
		printf("Hello World!");
	} while (1 < i);

	int number = 0;
	int sum = 0;

	do
	{
		number += 1;
		sum += number;
	} while (0 < number && 10 > number);


	int arr[5] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < 5; ++i)
	{
		printf("arr의 %d 번째 값: %d\n", i, arr[i]);
	}

	int arr2[5] = {5};
	int arr3[5] = {2, 5};
	int arr4[] = { 5, 2, 4, 1 };


	return 0;
}