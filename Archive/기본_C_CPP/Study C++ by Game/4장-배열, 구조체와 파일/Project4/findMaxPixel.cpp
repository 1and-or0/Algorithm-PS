#include "fns.h"

int findMaxPixel(int a[][5], int h, int w)
{
	int maxVal = 0;
	for (int i = 0; i < h; ++i)
	{
		for (int j=0; j<w; ++j)
		{
			if (maxVal < a[i][j])
			{
				maxVal = a[i][j];
			}
		}
	}
	return maxVal;
}