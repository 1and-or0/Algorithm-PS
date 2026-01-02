#include "functions.h"

int main()
{
	int arr[10] = { 3, 24, 82, 12, 34, 7, 53, 17, 26, 51 };
	char str[] = "Game over !";

	printf("mac val = %d\n", findMaxValue(arr, 10));
	printf("mac char = %c\n", findMaxChar(str));

	int b[10];
	char src[] = "You Win !!", dst[40];

	reverseArray(arr, b, 10);
	reverseString(src, dst);

	printArray(arr, 10);
	printArray(arr, 10, "배열 arr");
	printArray(b, 10, "배열 b");

	printf("src = %s\n", src);
	printf("dst = %s\n", dst);
	
	return 0;
}