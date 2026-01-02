#include <iostream>
#include <iomanip>

using namespace std;

void summ();


int main()
{
	cout << 2017 << endl; // "2017" 출력
	cout << setw(8) << 2023 << endl; // 8자리로 표기 "_ _ 2023" 출력
	
	cout << fixed;  //  고정 소수점 표기 설정

	cout << setw(8)  // 8자리로 표기
		 << setprecision(3)  // 소수점 이하 3자리
		 << setfill('0')    // 빈 자리에 0을 채움
		 << 3.14159 << endl;   // "0003.142" 출력

	cout //<< setw(8)  // 8자리로 표기
		 << setprecision(3)  // 소수점 이하 3자리
		 << setfill('0')    // 빈 자리에 0을 채움
		 << 3.14159 << endl;   // "3.142" 출력

	cout << setw(8)  // 8자리로 표기
		 << setprecision(3)  // 소수점 이하 3자리
		 << setfill('?')    // 빈 자리에 0을 채움
		 << 3.14159 << endl;   // "3.142" 출력

	cout << setw(8)  // 8자리로 표기
		 //<< setprecision(3)  // 소수점 이하 3자리
		 //<< setfill('?')    // 빈 자리에 0을 채움
		 << 3.14159 << endl;   // "3.142" 출력
	
	cout << 21.15743 << endl;

	cout << 54621.15743 << endl;

	return 0;
}



void summ()
{
	int x, y;
	cout << "두 정수 입력: ";
	cin >> x >> y;
	cout << " x: " << x;
	cout << " y: " << y;
	cout << " x + y: " << x + y << endl;


	cin >> x >> y;
	cout << "x: " << 3 << endl; // stdout 으로 한 라인(endl) 출력
	cout << x << y << flush; // flush: 출력 버퍼를 비움

	char c1, c2, c3 = 'Z';
	c1 = cin.get(); // c = getchar(); 한 문자 입력

	char s[10];
	cin.get(c2); // char 를 읽음. 한 문자 입력
	cin.getline(s, 10, '\n'); // '\n' (default) 까지 한 라인을 읽어 char 배열 s에 저장

	cout << "c1: " << c1 << endl << "c2: " << c2 << endl << "c3: " << c3 << endl;

	cin.get(c3);
	cout << "c1: " << c1 << endl << "c2: " << c2 << endl << "c3: " << c3 << endl;
}