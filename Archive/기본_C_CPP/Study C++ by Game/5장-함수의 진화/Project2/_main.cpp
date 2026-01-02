#include <cstdio>

int _main()
{
	int list[5] = { 1, 2, 3, 4, 5 };
	int* p = list;

	printf("%d\n", list);

	printf("list: ");

	for (int i = 0; i < 5; ++i)
	{
		printf("%d", *p++);
	}
	
	int sum = 0;

	p = list; // 포인터에 배열 주소 복사
	for (int i = 0; i < 5; ++i)
	{
		sum += p[i];
	}
	printf("\n sum: %d\n", sum);


	printf("list: ");

	for (int i = 0; i < 5; ++i)
	{
		printf("%d", ++*p);
	}

	return 0;
}