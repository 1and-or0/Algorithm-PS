#include <stdio.h> 
#include "func.h"  
// func.h 파일을 참조할 것이다
// #inlcude는 전처리기로 명시해놓은 func.h 파일을 복붙하는 역할임. 파이썬 import 느낌



//// 정적변수 선언 
//static int g_iStatic = 0;
#include "common.h"

void printing()
{
	printf("g_iStatic의 값: %d", g_iStatic);
	g_iExtern += 1;
	printf("뭐지?: \n%d\n", g_iExtern);
}

// 선언은 func.h 파일에서 했고 이를 참조했기 때문에 정의만 해주면 됨
// 따라서 정의해줌
int Add(int a, int b)
{
	printf("이게 뭔가..:\n");
	g_iExtern += 1;
	printf("g_iExtern: %d\n", g_iExtern);

	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}


int Mul(int a, int b)
{
	return a * b;
}


int Div(int a, int b)
{
	return a / b;
}
