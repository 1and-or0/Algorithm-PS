#include "functions.h"

void printRanking(int score[], int len, const char msg[])
{
	printArray(score, len, msg);
}

int main()
{
	int score[5] = {0, 0, 0, 0, 0};
	
	srand(time(NULL));

	for (int i = 0; i < 8; ++i)
	{
		int newScore = rand() % 100;
		addDescending(score, 5, newScore);
		printf("[%2d] ", newScore);
		printRanking(score, 5, "¼øÀ§");
	}

	return 0;
}
