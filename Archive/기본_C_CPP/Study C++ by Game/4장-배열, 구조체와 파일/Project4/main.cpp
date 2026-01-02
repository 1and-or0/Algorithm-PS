#include "fns.h"

int main()
{
	int img[3][5] = { {3, 24, 82, 12, 22},
					  {99, 7, 65, 73, 58},
					  {20, 7, 9, 48, 29} };

	int maxPixel = findMaxPixel(img, 3, 5);
	printf("영상의 최대 밝기 = %d\n", maxPixel);

	return 0;
}