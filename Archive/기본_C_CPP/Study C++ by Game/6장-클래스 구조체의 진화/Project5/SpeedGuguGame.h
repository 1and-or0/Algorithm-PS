#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <ctime>

class SpeedGuguGame
{
	int NumGames = 0;     // 전체 시도 횟수	
	int NumWins = 0;      // 맞힌 횟수
	double Score = 0;     // 점수
	bool playGuguOnce()
	{
		int a = rand() % 8 + 2;
		int b = rand() % 8 + 2;
		int result;

		++NumGames;
		printf("[문제 %d번] %2d x %2d = ", NumGames, a, b);
		scanf("%d", &result);

		if (result == a * b) ++NumWins;

		return (result == a * b);
	}
public:
	double tElapsed = 0;  // 게임 소요시간

	double play(int nPlay)
	{
		clock_t t0 = clock();

		for (int i = 0; i < nPlay; ++i)
		{
			if (playGuguOnce() == false)
			{
				printf("\t틀렸습니다.\n");
			}
		}

		clock_t t1 = clock();

		tElapsed = (double)(t1 - t0) / CLOCKS_PER_SEC;
		Score = (NumGames > NumWins) ? 0.0 : 100 * (10.0 * NumGames - tElapsed) / (10.0 * NumGames);

		return Score;
	}
};