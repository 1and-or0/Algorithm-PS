#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i;
	int max_index;

	int kor[10];
	int eng[10];
	int math[10];

	int total[10];
	float avr[10];

	srand(time(NULL));

	for (int i = 0; i < 10; ++i)
	{
		kor[i] = rand() % 101;
		eng[i] = rand() % 101;
		math[i] = rand() % 101;
	}

	for (int i = 0; i < 10; ++i)
	{
		total[i] = kor[i] + eng[i] + math[i];
		avr[i] = total[i] / 3.0;
	}

	max_index = 0;
	for (int i = 0; i < 10; ++i)
	{
		if (total[max_index] < total[i])
		{
			max_index = i;
		}
	}
	
	for (int i = 0; i < 10; ++i)
	{
		printf("index: %d, kor: %d, eng: %d, math: %d, total: %d, avr: %.2f\n", i, kor[i], eng[i], math[i], total[i], avr[i]);
	}
	printf("최고점인 학생의 번호(max_index): %d", max_index);

	return 0;
}