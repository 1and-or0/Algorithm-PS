#include "RoussianRoulette.h"

void main()
{
	int how_many_p;
	int how_many_b;

	srand(time(NULL));

	printf("게임 인원 입력: ");
	scanf_s("%d", &how_many_p);

	printf("총알 개수 입력(1~5개): ");
	scanf_s("%d", &how_many_b);

	while (how_many_b < 1 || how_many_b>5)
	{
		printf("총알 개수의 범위를 주의하세요!\n");
		printf("총알 개수 입력(1~5개): ");
		scanf_s("%d", &how_many_b);
	}

	getchar();

	
	int shotted_p = playRoussianRoulette(how_many_p, how_many_b);
	printf("\n %d번 player가 총에 맞았습니다.\n", shotted_p);

	return;
}