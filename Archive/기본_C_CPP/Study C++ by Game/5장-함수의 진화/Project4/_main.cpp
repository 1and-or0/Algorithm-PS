#define _CRT_SECURE_NO_WARNINGS
// #define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

struct PlayInfo {
	char name[80];
	int level;
	double score;
};

void findMinMax(int* a, int len, int& min, int&max)
{
	min = a[0];
	max = a[len - 1];
	for (int i = 0; i < len; ++ i)
	{
		if (min > a[i])
		{
			min = a[i];
		}
		if (max < a[i])
		{
			max = a[i];
		}
	}
	printf("&min: %d", &min);
}


int _main()
{
	PlayInfo teamKorea[4] = { 
		{"±èÇö¼ö", 20, 22.7},
		{"¿À½ÂÈ¯", 30, 32.0},
		{"Ãß½Å¼ö", 40, 40.5}
	};

	for (int i = 0; i < 3; ++i)
	{
		PlayInfo& play = teamKorea[i];
		printf("%s %d %4.2f\n", play.name, play.level, play.score);
	}

	PlayInfo& Korean4 = teamKorea[3];
	
	strcpy(Korean4.name, "È«±æµ¿");


	int arr[10] = { 3, 24, 82, 12, 34, 7, 53, 17, 26, 51 };
	int x, y;

	findMinMax(arr, 10, x, y);
	printf("&x: %d", &x);
	printf("min: %d, max: %d\n", x, y);

	
	return 0;
}