#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string s1, s2 = "Game";
	s1.size(), s2.size();  // 문자열의 길이: 0, 5
	s1 = s2 + ' ' + "Over";
	if (s1 == "Game Over")
	{
		cout << s1 << "가 맞습니다\n";
	}

	cout << s1.find("Over") << endl;  // 문자열의 처음부터 Over 검색, 위치 반환.
	cout << s1.find("e", 4) << endl;  // 4번 위치부터 "e"검색. 위치 반환 // 없으면 (string::nnpos   or  -1) 반환

	cout << s1[0] << endl;
	cout << s1.substr(5, 4) << endl; // s1[5] 부터 길이 4 만큼 문자열 추출
	printf("s1: %s\n", s1.c_str());  // string에서 문자 배열 주소 char* 추출
	getline(cin, s1);
	cout << s1 << endl; 

	
	
	
	return 0;
}