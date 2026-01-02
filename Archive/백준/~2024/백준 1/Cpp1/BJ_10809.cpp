#ifndef BITS_STD_H10809
#define BITS_STD_H10809
#include <bits/stdc++.h>
using namespace std;
#endif // !BITS_STD_H10809

/// <해결 아이디어>
/// A~Z까지 0 ~ 25를 인덱스로 하는 배열 만들기
/// 기본값 -1로 초기화
/// string st에 입력받은 문자열 st[i]로 하나씩 접근
/// 이를 아스키코드 번호를 이용해 위에서 만들었던 배열에 인덱스로 해서 접근 
/// st[i]에서 i의 값이 접근한 배열의 원소로 들어가게 함
/// 주의: 같은 문자가 st에 있는 경우 가장 처음의 위치가 들어가야 하므로
/// st[i]의 값이 -1인지 확인 후 값을 넣기
/// -1이 아니면 이미 가장 처음의 위치가 들어가 있음.
/// </해결 아이디어>
int main_bj_10809()
{
	string st;
	cin >> st;

	int abc[26];
	fill_n(abc, 26, -1);  // abc 배열을 -1로 초기화

	for (int i = 0; i < st.length(); ++i)
	{
		int index;
		index = (int) st[i] - 'a';
 		if(abc[index] == -1)
			abc[index] = i;
	}


	for (int i = 0; i < 26; ++i)
	{
		cout << abc[i] << ' ';
	}

	return EXIT_SUCCESS;
}