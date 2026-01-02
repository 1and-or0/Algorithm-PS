#include <stdlib.h>
#include <stdio.h>

typedef struct _tagMySt
{// 맴버: 구조체를 구성하는 자료형 부분들. MYST의 경우 맴버들이 int part와 float 파트가 있는 것임
	// 여기서 a와 f는 변수가 아님!!
	// 맴버임!

	int i;
	float f;
}MYST;

int main()
{
	// 구조체와 포인터
	// 구조체 초기화
	MYST x = {};
	
	MYST* p_x = &x;

	// x = ?;      ==    (*p_x) = ?;
	(*p_x).i = 100;
	 // x.i = 200;      ==    (*p_x).i = 200;
	(*p_x).f = 3.14f;

	// 줄여쓰고 싶어졌네? 그래서 나온 표현식
	// 역참조한 이후 파트를 지칭하는 것을 한번에 표현. 
	p_x->i = 200;
	p_x->f = 2.71;



	return 0;
}