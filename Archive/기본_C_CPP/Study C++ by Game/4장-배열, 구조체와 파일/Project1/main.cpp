#include "calcTax.h"


void main()
{
	printf("%d\n", sizeof(char));

	int income = 0;
	double tax;
	printf("연봉을 입력하세요: ");
	scanf_s("%d", &income);

	tax = calcTax(income);
	printf("전체 세금은 %7.2f만원입니다.\n", tax);
	printf("순수 소득은 %7.2f만원입니다.\n", income - tax);

	return;
}