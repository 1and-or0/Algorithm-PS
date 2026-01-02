#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
// 경고 발생 헤더
#include <assert.h>

// 함수 오버라이딩이랑 다르다!
// 면접 단골 질문 함수 오버로딩 vs 오버라이딩

// 로딩 불러오기 (리소스를 메모리에)
// 함수 오버로딩: 같은 이름의 함수를 여러개 만들었다!
// 함수 오버로딩, 인자의 개수, 인자의 자료형으로 함수가 구별된다!
void Test(int a)
{

}

void Test(float a)
{

}


void Test(int a, int b)
{

}


// const 를 추가로 매개변수에 작성함으로써 받아온 주소를 통해 접근한 곳의 값을 변화시키지 않을 것임을 명시!

// 문자열의 길이 구하는 함수
unsigned int len(const wchar_t* p_str)
{ 
	// 인덱스 0의 값에 접근한 것임
	// p_str[0];  // 수정은 불가능 const pointer로 받아왔기 때문임


	// tip from 어소트락 게임아카데미
	// 반복문이 익숙하지 않은 경우 조건에 일단 true를 넣고 본다
	// 그리고 특정 상황에서 break; 를 통해 나오면 된다

	// 문자 개수 확인하는 변수 
	unsigned int index_ = 0;

	while (true)
	{
		// 받아온 문자열의 주소를 처음부터 증가해가며 담는 변수
		wchar_t p_n_char = p_str[index_];
		p_n_char = p_str[index_];

		// null문자는 \0임
		if (p_n_char == '\0')
		{
			break;
		}
		else
		{
			++index_;
		}
		/*if ("\0" == p_n_char)
		{
			break;
		}
		else
		{
			++index_;
		}*/
	}

	return index_;
}


// 문자열 이어붙이기
// 마이크로소프트 레퍼런스 문서
// 문자열은 그 자체로 포인터 변수, 주소이다
void Cat_(wchar_t* str1, unsigned int size_str3, const wchar_t* str2)
{
	int len_str1 = len(str1);
	int len_str2 = len(str2);

	if (size_str3 < len_str1 + len_str2 + 1)
	{
		assert(nullptr);
	}

	// str2의 문자열을 str1 문자열에 추가하기
	for (int i = 0; i < len_str2 + 1; ++i)
	{
		str1[len_str1 + i] = str2[i];
	}

}

int main()
{
	// 문자열 길이 알려주는 wsclen 함수 직접 만들어보기
	wchar_t name[10] = L"양수진 동글동글";
	
	int len_name = len(name);
	

	wchar_t String1[100] = L"abc";
	wchar_t String2[100] = L"defghijklmnopqrstuvwxyz";

	wcscat_s(String1, 100, L"defghijklmnopqrstuvwxyz");

	wchar_t str1[20] = L"abcdef";
	wchar_t str2[10] = L"ghijklmn";
	Cat_(str1, 39, str2);


	//wcscmp(); // 구현하기
	// 두 문자열을 인자로 받음
	// 두 문자열이 완벽하게 일치하면 0, 아니면 ???
	// 오름차순 정렬에서 (후순위, 선순위) 이면 양수, 1
	// (선순위, 후순위)이면 음수, -1
	// 저울과 같은 놈
	// 값 비교 ,,, 우열을 아스키 코드로...

	printf("아아아");

	return 0;
}