#include "Ranking.h"
#include <cstdlib>
#include <ctime>


int main()
{
	srand(time(NULL));
	loadRanking("ranking.bin");
	printRanking();

	for (int i = 0; i < 5; ++i)
	{
		addRanking(rand() % 500, rand() % 1000 * 0.1);
	}
	storeRanking("ranking.bin");

	return 0;
}