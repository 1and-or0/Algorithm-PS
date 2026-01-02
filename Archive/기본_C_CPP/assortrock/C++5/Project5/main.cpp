#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

int main()
{
	// 1. const (문법적으로만 변수를 상수로 취급해주는 것, 절대적으로 값이 고정되는 것이 아님!)
	const int i = 100;

	// const + pointer 
	int a = 0;
	int* pInt = &a;

	*pInt = 1;
	pInt = nullptr;

	// const + pointer 
	// (상수화const 포인터) 1. pointer로 접근해 그곳의 데이터 수정 기능이 제한, 
	//     포인터로 접근시에만 그 곳의 데이터는 const(상수화)가 됨. 이 경우(포인터로 접근할 시에만 변경 불가,
	//         변수로 접근시(변수가 const가 아니면) 변경 가능)
	// (포인터 상수화const) 2. pointer 변수가 가르키는 위치를 고정(=const=상수화)시키는 경우


	// ==== const 포인터 ====
	// 1에 해당하는 경우, 포인터 변수는 상수화가 되지 않음!
	const int* pConstInt = &a;
	// *pConstInt = 100;
	

	// ==== 포인터 const ====
	// 2에 해당하는 경우, 주소에 있는 데이터는 변경 가능!
	int* const pIntConst = &a;
	// 따라서 다음과 같은 문구 실행 불가
	// pIntConst = 1;
	// 대신 이는 가능
	*pIntConst = 100;


	// 1과 2의 혼합 활용
	const int* const pConstIntConst = nullptr;
	// 번지가 다른 번지로 바뀌지 못 하고, 번지가 가리키는 데이터도 변경 불가


	// 기출 변형, const 포인터(*)에 해당함... 
	int const* p = nullptr;


	{
		int a = 0;
		const int* pInt = &a;

		// a = 100; 문제 없음, 변경 가능!
		// const int* 는 *를 제한(상수화)한 것임. 변수 a는 제한(const)이 없음

		a = 100;
		printf("%d\n", a);

	}


	// void: 함수의 반환값이 없음을 의미, 이에 해당하는 함수는 return이 필요 없음

	float* pFloat = nullptr; // 원본을 float으로 보겠다는 뜻. float 포인터

	// void 포인터
	// 원본 데이터가 어떻게 사용되고 있는지와 무관한 포인터이다!
	/*
	* == void 포인터 특징 ==
	* 1. 원본의 자료형을 정하지 않음 
	* 2. 어떤 타입의 변수라도 주소를 저장 가능
	* 3. 역참조 불가능
	* 4. 주소 연산 불가능
	*/
	void* pVoid = nullptr;  // 원본을 void로 보겠다는 뜻으로 즉, 어떤 데이터 타입으로 해석할지 정하지 않은 것.
	                        // 당연히 포인터 변수 pVoid에 주소는 저장이 가능.
	// 원본을 어떻게 해석할지 pVoid는 정해져있지 않으므로 어떤 데이터 타입의 주소던 다 받을 수 있다.

	{
		int a = 0;
		float f = 3.1f;
		double d = 24.4f;
		long long ll = 0;

		pVoid = &a;
		pVoid = &f;
		pVoid = &d;
		pVoid = &ll;

		// 따라서 void 포인터는 역참조가 불가능하다
		// *pVoid;
		// 역참조를 하려면 포인터 변수가 가리키는 곳을 해석할 자료형이 필요하기 때문
		// 그래야 그 자료형(data type)에 맞춰 몇 byte로 접근할지 정해지기 때문이다!
		// 정수냐 실수냐, short 2byte씩이냐 int 4byte씩이냐 정해지지 않아서 해석이 불가능!

		// 주소 연산도 불가능
		// pVoid + 1; 
		// int 포인터 변수인 경우 + 1 을 하면 4byte 단위로 끊어서 읽기 때문에 원래 보던 주소에서 4byte를 증가
		// 그러나 void 포인터 변수의 경우 자료형이 정해지지 않아 단위도 정해지지 않아 주소 연산이 불가능하다!

	}

	// 메모리 영역
	/*
	* 1. 스택 영역
	* 2. 데이터 영역
	* 3. 힙 영역
	* 4. 읽기 전용 영역(ROM: Read Only Memory 코드 ex) 소스코드)
	*/ 

	// 읽기 전용 영역

	{
		// 문자
		// 아스키코드 49 = '1', 65 = 'A',
		// 정수, 1byte, character
		char c = 1;
		
		// 서로 완전 다르다
		c = 1;  // 아스키코드 값 1은 문자 SOH: \x1 이라는 문자임. 변수 c에는 1'\x1'이라고 저장됨
		c = '1';  // '1'은 아스키코드로 49이므로 변수 c에는 아스키코드 값인 49'1'이 저장됨


		// 또 다른 1byte 정수 자료형, bool
		bool b = 1;

		// 정수, 2byte, 
		wchar_t wc = 49;

		// 또 다른 2byte 정수 자료형, short
		short s = 49;

		int i = 0;
	}

	// UTF-8과 같이 특정 언어를 명시해주는데 최상위 비트(1bit)를 사용함
	// 따라서 1byte(7bit)로 127가지의 문자가 표현이 가능함
	// 그런데 한글과 같은 경우 조합하면 문자가 엄청 많아서 char(127가지)로는 모두 표현 불가
	// 따라서 한글을 저장하는 경우 wchar_t를 사용한다
	// 2byte인 wchar_t를 사용하면 총 약 6만가지이상, 비트 하나를 언어를 명시해준는데 사용하더라도
	// 총 약 3만가지 이상은 표현이 가능함 
	
	// 1byte 문자 넣기
	char c = 'a';

	// 2byte 문자 넣기, L을 통해 2byte 문자라는 것을 명시해준다
	wchar_t wc = L'a';

	// 1byte 문자열
	char szChar[10] = "abcdef";

	// 문자열의 경우 문자열이 끝났음을 알려주기위해 마지막 byte에는 null(0)이 들어간다.
	// 따라서 wchar_T szWChar[10]의 경우, 총 9개의 문자만 넣을 수 있다. == 인덱스 0~8까지만 내가 넣고 싶은 문자를 넣을 수 있다. 
	// (왜냐하면 마지막 인덱스에는 문자열이 끝났음을 알려주는 null(0) 문자가 들어가야 하기 때문이다!

	// 2byte 문자열, L을 붙여줌으로써 문자열을 구성하고 있는 문자 하나하나가 2byte 단위라는 것을 알려주는 것!
	wchar_t szWChar[10] = L"abcedf";

	// 포인터
	// 문자열은 포인터에서 그 자체로 주솟값이다(?)
	// 문자열은 배열에서 데이터 값이다.
	const wchar_t* pWChar = L"abcdef";
	

	// 문자열 L"abcdef"; 는 그대로이고
	// 배열 szWChar의 인덱스 1번의 데이터 값을 'b'에서 'z'로 바꾸겠다
	szWChar[1] = 'z';
	*(szWChar + 1) = 'h';
	
	// 배열 szWChar는 그대로이고
	// 문자열 L"abcdef"; 에서 b의 주솟값을 z의 주솟값으로 바꾸겠다는 뜻
	// 문자열 L"abcdef";를 L"azcdef";로 바꾸겠다는 뜻
	// pWChar[1] = 'z';    ==    *(pWChar += 1) = 'z';
	// 그런데 L"abcdef"는 상수, 리터럴 취급 이므로 변경이 불가능


	// 문자열 표현
	// 'abcd' - 멀티바이트 표현방식 1byte와 2byte를 섞어 가변적 표현, 모든 문자를 1byte로 표현하는 것은 아님
	// L'abcd' - wide byte 표현 방식 2byte 만으로 표현

	char szTest[10] = "abc한글";

	// 멀티바이트는 표준으로 잘 안 씀
	// UTF  유니코드 시스템은 2byte 표현방식으로 쓰기 때문에
	// wide byte를 사용함

	wchar_t szWTest[10] = L"abc한글";

	// 함수에서 자동으로 멀티바이트를 쓸지 와이드 바이트를 쓸지 선택하는 것이 가능함
	// 그러나 수업은 와이드 바이트만 사용할 것이므로 상관X



	unsigned char szUTest[10] = "abc한글";
	// 멀티바이트 문자 


	{
		// 파이썬 문자 길이 알려주는 len() 함수
		// C++의 경우, wcslen함수가 존재 
		// 문자열에 문자 몇개있어?
		wchar_t szName[10] = L"Raimond";
		// 배열 변수는 그 자체로 포인터 변수처럼 사용 가능
		int iLen = wcslen(szName);

		return 0;
	}


	return 0;
}