#include <stdio.h>


/// <summary>
/// 플랫폼...
/// 윈도우, 안드로이드, Ios, 스팀, 에픽스토어, Origin ...
/// 32bit, 64bit 무엇으로 만들 것인가.
/// x86, x64
/// x86 - 32bit 윈도우 버전, 당시 cpu이름이 x86이 있어서 카더라~
/// x64 - 64bit 윈도우 버전 - 수업은 64bit기반으로 진행됨!
/// </summary>
/// <returns></returns>


int main()
{
	// 포인터 - 주소를 가리키는 기능
	// 포인터 변수: 주소를 저장하는 변수
	int* pInt = nullptr;  // nullptr 는 실제 들어가는 데이터는 0을 의미한다. 
	// 0이 아닌 nullptr라고 작성하는 이유는 pInt라는 포인터 변수가 아무것도 가르키지 않음을 뜻함 


	int i = 100;
	// 앞의 int는 주소 안에 저장된 data의 type이다. pi는 int 포인터로 
	int* pi = &i;

	long long_A;
	int size_A = sizeof(long_A);

	// *pi: pi에 저장된 주소에 접근하겠다. 그리고 접근한 주소에 100이라는 값을 넣겠다. 즉 i값이 100이 된다. 
	(*pi) = 10; 

	// 주소의 단위: byte, type: (정수 o, 실수 x)


	return 0;
}