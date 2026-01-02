#ifndef BJ_1259_C
#define BJ_1259_C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#endif // BJ_1259_C

int main_BJ_1259_C()
{
	char nums[6];
	scanf("%s", nums);

	while (nums[0] != '0')
	{
		short result = 1;
		int len = 0;
		for (int i = 0; i < 6; ++i)
		{
			if (nums[i] == '\0')
			{
				len = i;
				break;
			}
		}

		for (int i = 0; i < len / 2; ++i)
		{
			if (nums[i] != nums[len - i - 1])
			{
				printf("no\n");
				result = 0;
				break;
			}
		}

		if (result == 1)
		{
			printf("yes\n");
		}

		scanf("%s", nums);
	}

	return 0;
}