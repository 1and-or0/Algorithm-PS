#include <cstdio>
#include <cstring>

void printArray(const int a[], int len, const char msg[] = "Array")
{
	printf("%s: ", msg);
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", a[i]);
	}
}

void reverseArray(const int a[], int len, int b[])
{
	for (int i = 0; i < len; ++i)
	{
		b[len - i - 1] = a[i];
	}
}

int main()
{
	int a_list[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int b_list[10] = {};

	reverseArray(a_list, 10, b_list);


	int var = 10;
	int& ref = var;

	ref = 20;
	printf("&var: %d\n", &var);
	printf("&ref: %d\n", &ref);

	
	int map[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int sum = 0;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			int& elem = map[i][j];
			elem = i * 3 + j + 1;
			sum += elem;
			printf(" %d", elem);
		}
	}
	printf("\n sum: %d\n", sum);

	return 0;
}