#ifndef BJ_10866_C
#define BH_10866_C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#endif // !BJ_10866_C

int main_BJ_10866_C() {
    int arr[20010];
    int top = 10000, bot = 10000;
    char com[10];
    int N;
    scanf("%d", &N);
    for (size_t i = 0; i < N; i++)
    {
        scanf("%s", com);
        if (com[1] == 'u' && com[5] == 'f') scanf("%d", &arr[--top]);
        else if (com[1] == 'u' && com[5] == 'b') scanf("%d", &arr[bot++]);
        else if (com[1] == 'o' && com[4] == 'f') printf("%d\n", bot - top ? arr[top++] : -1);
        else if (com[1] == 'o' && com[4] == 'b') printf("%d\n", bot - top ? arr[--bot] : -1);
        else if (com[1] == 'i') printf("%d\n", bot - top);
        else if (com[1] == 'm') printf("%d\n", bot - top ? 0 : 1);
        else if (com[1] == 'r') printf("%d\n", bot - top ? arr[top] : -1);
        else if (com[1] == 'a') printf("%d\n", bot - top ? arr[bot - 1] : -1);
    }
    return 0;
}