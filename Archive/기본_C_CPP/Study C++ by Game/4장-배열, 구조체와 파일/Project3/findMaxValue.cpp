#include "functions.h"

int findMaxValue(int a[], int len)
{
	int maxVal = a[0];

	for (int i = 1; i < len; ++i)
	{
		if (maxVal < a[i])
		{
			maxVal = a[i];
		}
	}

	return maxVal;
}