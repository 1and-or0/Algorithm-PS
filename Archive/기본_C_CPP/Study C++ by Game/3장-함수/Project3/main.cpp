#include "SpeedGugu.h"

void main()
{
	srand(time(NULL));

	int nPlay = 10;
	printf("<스피드 구구단 게임>\n\n");
	printf("당신의 구구단 실력을 테스트하세요.!!!\n\n");
	printf(" 문재 %d개를 통해 테스트 하겠습니다.\n", nPlay);
	printf("크게 심호흡을 하시고...\n 준비되면 엔터를 누르세요...");
	getchar();

	// 화면 비우기
	system("cls"); 

	double score = playSpeedGugu(nPlay);
	printf("\n 점수: %4.2lf점(총 %4.2lf초)\n", score, tElapsed);


	return;
}