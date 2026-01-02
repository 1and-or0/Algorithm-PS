#ifndef BJ_4153_C
#define BJ_4153_C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#endif // !BJ_4153_C

int main_BJ_4153_C()
{
    int arr[3] = { -1, -1, -1 };

    for (int i = 0; i < 3; ++i)
    {
        scanf("%d", &arr[i]);
        arr[i] *= arr[i];
    }

    while (arr[0] != 0 && arr[1] != 0 && arr[2] != 0)
    {
        int temp = -1;
        for (int i = 0; i < 2; ++i)
        {
            if (arr[2] < arr[i])
            {
                temp = arr[2];
                arr[2] = arr[i];
                arr[i] = temp;
            }

        }

        if (arr[0] + arr[1] == arr[2])
            printf("right\n");
        else
            printf("wrong\n");

        for (int i = 0; i < 3; ++i)
        {
            scanf("%d", &arr[i]);
            arr[i] *= arr[i];
        }
    }
    return 0;
}