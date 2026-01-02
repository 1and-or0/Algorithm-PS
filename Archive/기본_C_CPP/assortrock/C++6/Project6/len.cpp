#include <stdio.h>
#include <wchar.h>

// 유니코드 문자를 사용하기 위한 헤더파일 tchar
#include <tchar.h>
// 지역설정을 해주기 위한 헤더파일 locale
#include <locale.h>

// 문자열 길이 구하는 함수
unsigned int len(const wchar_t* str)
{
	unsigned int len = 0;

	// 참고 문자'' 문자열"", '\0': null 문자
	// 참고2 *(str + len) == str[len]
	// 참고3 조건부 작성시 상수 == 변수 이런식으로 작성하면
	// ==이 오타나서 =로 작성된 경우 컴파일 문법 오류로 잡힘
	// 습관으로 들이면 좋음!
	while (str[len] != '\0')
	{
		++len;
	}

	return len;
}

int main()
{
	wchar_t name1[10] = L"양수진 동글동글";

	int len_name1 = len(name1);
	printf("%d\n", len(name1));
	wprintf(L"%s\n", name1);
	wprintf(L"%c\n", name1[0]);
	
	// 지역을 한국으로 설정해주는 부분 L"kroean", L"지역명"
	_tsetlocale(LC_ALL, L"korean");

	// _TCHAR 라는 자료형이 유니코드 문자 자료형이고 크기는 2byte임. 2byte 배열이 만들어짐 
	_TCHAR name2[10] = L"양수진 동글동글";

	int len_name2 = len(name2);
	printf("%d\n", len(name2));
	// 유니코드 문자를 출력하는 함수는 printf가 아니라 _tprintf임
	// 문자열 출력 기호는 %s, 문자 출력 기호는 %c임
	_tprintf(L"%s\n", name2);
	_tprintf(L"%c\n", name2[0]);



	return 0;
}