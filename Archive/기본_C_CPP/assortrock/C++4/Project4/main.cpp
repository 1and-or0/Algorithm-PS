#include <stdio.h>

//  test1 함수의 경우 main함수 지역 변수인 a의 값을 바꾸지 못 함. 
// 이를 위해 전역변수를 사용하거나, 포인터를 이용해 접근하도록 만든다!
int test1(int a)
{
	a += 100;
	return 0;
}

// 포인터를 이용해 접근하는 방법!
int test2(int* pa)
{
	*pa += 100;
	return 0;
}



int main()
{
	int a = 10;

	test2(&a);
	printf("%d\n", a);


	// const 키워드가 사용된 변수는 변수를 상수화 한다!
	// 상수화: 값의 변경이 불가능함!
	volatile const int cint = 100;

	// l-value: 값이 바뀔 수 있는 변수
	// r-value: 값이 바뀔 수 없는 변수

	// 기능적으로 가능하나 문법적으로 막아줌. 
	// cint = 200; 
	// 따라서 주소에 접근해 값을 변경 가능
	int* pint = (int*) &cint;
	*pint = 200;
	// 그러나 메모리에 값은 변경되었어도, 
	// 컴파일러 최적화 과정에서 const라고 선언한 변수 cint의 값 100을 cpu 레지스터 메모리에 저장
	// 이를 다시 불러오기 때문에 스택 메모리에 강제로 변경한 값이 출력되지 않고 cpu 레지스터 메모리의 100이 출력됨
	printf("%d\n", cint);

	// 그래서 컴파일 최적화를 하지 않겠다(휘발성 메모리는 사용하지 않겠다(?))는
	// 키워드  volatile을 변수 선언에 작성해주면 출력시 컴파일 최적화가 이루어지지 않는다
	// 따라서 스택 메모리에 있는 강제로 변경한 값이 출력됨
	// volatile const int cint = 100;




	return 0;
}