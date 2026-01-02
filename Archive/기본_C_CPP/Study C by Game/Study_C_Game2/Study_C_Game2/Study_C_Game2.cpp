#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
	int data[6];

	srand(time(NULL));

	for (int i = 0; i < 6; ++i)
	{
		data[i] = rand() % 46 + 1;

		for (int j = 0; j < i; ++j)
		{
			if (data[i] == data[j])
			{
				--i;
				break;
			}
		}
	}
	
	int user_num[6];

	for (int i = 0; i < 6; ++i)
	{
		printf("(0 ~ 46) 수 입력: ");
		scanf_s("%d", &user_num[i]);;

		for (int j = 0; j < i; ++j)
		{
			if (user_num[i] == user_num[j])
			{
				printf("전에 입력한 수와 중복됩니다! 재입력하세요:\n");
				--i;
				break;
			}
		}
	}


	for (int i = 0; i < 6; ++i)
	{
		printf("%d\t", data[i]);
	}
	printf("\n");


	return 0;
}