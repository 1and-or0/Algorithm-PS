#include <cstdio>

void main2()
{
	printf("Hello world!\\\n");
	printf("원의 반지름을 입력하세요: ");
	double r;
	scanf_s("%lf", &r);

	printf("원의 반지름: %lf\n", r);
	printf("원의 둘레: %lf\n", 2*3.14*r);
	printf("원의 면적: %1f\n", 3.14*r*r);


	printf("원의 반지름: %f\n", r);
	printf("원의 둘레: %f\n", 2 * 3.14 * r);
	printf("원의 면적: %f\n", 3.14 * r * r);

	printf("원의 반지름: %.2lf\n", r);
	printf("원의 둘레: %f\n", 2 * 3.14 * r);
	printf("원의 면적: %1f\n", 3.14 * r * r);


	return;
 }