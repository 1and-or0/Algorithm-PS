#include <stdio.h>

int main()
{
	int i1[2] = { 100 , 50};
	int i2 = 200;

	i1;
	
	printf("%d\n", i1);
	printf("%d\n", (i1 + 1));
	printf("%d\n", *(i1 + 1));
	*(i1 + 1) += 10;

	return 0;
}