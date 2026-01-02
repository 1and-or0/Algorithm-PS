#include <stdio.h>


// 구조체: 사용자 정의 자료형(user definded datatype)
typedef struct _tagMyST
{
	// 자료형 내부의 a는 int 부분 이라고 정의함
	int a;

	// 자료형 내부의 f는 float 부분 이라고 정의함
	float f;
}MYST;


typedef struct _tagBig
{
	// MYST 라는 자료형을 포함하는 더 큰 자료형을 만듬 
	MYST k;
	int i;
	char c;

}BIG;


// C스타일로 구조체를 선언함. C와 C++ 모두에서 이용 가능하기 때문에 
typedef struct NewStruct
{
	int a;
	short s;
}NEWST; 
// struct NewStruct는 자료형의 이름으로 쓰기에 너무 길기에 typedef를 통해 자료형을 재정의
// 새로운 이름: NEWST 를 만들어줌

// typedef: int 자료형을 INT로 재정의 했기 때문에 이제 컴파일러는 INT도 int로 받아들임
typedef int INT;


int main()
{
	// 배열 초기화
	int array_1[10] = {};  // 모든 요소 0으로 초기화
	int array_2[10] = {1, 2, 3, 4, 5, 7, 66, 8, 9, 10};  // 개별 요소에 대한 초기화
	int array_3[10] = {1, 2, 3, 4, };  // 개별 요소에 대해 1, 2, 3, 4, 0, 0, 0, 0, 0, 0 으로 초기화  

	// 구조체(struct는 자료형의 하나로 사용자 정의 자료형을 모아놓은 자료형이다)
	// 구초제 초기화도 배열과 같음
	MYST t = {}; // 이렇게 하면 MYST의 a 부분 0으로 s 부분 0으로 초기화
	t = { 1, 3.14f }; // 이렇게 하면 MYST(=_tagMyST)의 a부분은 1로, s 부분은 3.14로 초기화

	int size_int = sizeof(int);
	int size_float = sizeof(float);
	int size_MYST = sizeof(MYST);

	t.a = 10;
	t.f = 10.2354f;

	INT number = 999;

	// struct 자료형 중에서 NewStruct라고 만들어 놓은 자료형으로 변수를 만든다
	struct NewStruct a;
	// 자료형의 이름이 struct NewStruct로 너무 길어짐 따라서 새로운 이름을 만들어 줄 것임
	NEWST b;
	// -- 여기까지 C 스타일 -- 
	// C++에서는 개선이 됨
	NewStruct k;
	// 이렇게 struct를 붙이지 않고 그냥 쓸 수 있음


	return 0;
}