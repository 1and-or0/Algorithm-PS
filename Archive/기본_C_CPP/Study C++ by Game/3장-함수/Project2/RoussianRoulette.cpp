#include "RoussianRoulette.h"

int playRoussianRoulette(int nTurns, int nBullets)
{
	int start_n = rand() % nTurns + 1;
	printf("\n총을 돌렸습니다. %d번부터 시작합니다.\n", start_n);

	while (true)
	{
		int pos = rand() % 5 +1 ;
		printf("[%d번 player]\t탄창을 무작위로 돌렸습니다.\n", start_n);
		printf("\t엔터를 누르면 방아쇠를 당깁니다...");

		getchar();
		if (pos <= nBullets)
		{
			break;
		}
		printf("\t휴~~~ 살았습니다!!!\n");
		start_n = (start_n) % nTurns + 1;
	}
	printf("\t빵~~~~~!!!\n");
	return start_n;
}