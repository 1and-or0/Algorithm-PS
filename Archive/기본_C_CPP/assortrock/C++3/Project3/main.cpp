#include <stdio.h>

int main()
{
	int* pint = nullptr;
	short* pshort = nullptr;
	char* pchar = nullptr;
	// int*  short*  char* 는 해당 주소의 위치에 있는 데이터를 인식하는 type을 지정한 것 뿐이다
	// 따라서 pint와 pshort, pchar는 모두 주소를 저장하므로 세 변수의 크기는 같다
	// 포인터의 크기는 모두 같다면 몇으로 정해지는가
	// 운영체제에 맞춰 정해진다
	// 32bit 운영체제는 보통 4byte 단위로 명령이 만들어져 실행되기 때문에, 포인터의 크기는 4byte로 만들어짐
	// 64bit 운영체제는 보통 8byte 단위로 명령이 만들어져 실행되기 때문에, 포인터의 크기는 8byte로 만들어짐


	int itest = 10;
	int* pitest = &itest;
	printf("%d\n", pitest);
	printf("%d\n", sizeof(pitest));

	short stest = 12;
	short* pstest = &stest;
	printf("%d\n", pstest);
	printf("%d\n", sizeof(pstest));


	int itest2 = 10;
	int* pitest2 = &itest2;
	printf("%d\n", pitest2);
	printf("%d\n", sizeof(pitest2));

	short stest2 = 12;
	short* pstest2 = &stest2;
	printf("%d\n", pstest2);
	printf("%d\n", sizeof(pstest2));

	int itest3 = 10;
	int* pitest3 = &itest3;
	printf("%d\n", pitest3);
	printf("%d\n", sizeof(pitest3));

	short stest3 = 12;
	short* pstest3= &stest3;
	printf("%d\n", pstest3);
	printf("%d\n", sizeof(pstest3));
	
	return 0;
}