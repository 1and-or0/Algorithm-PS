#include <iostream>
using namespace std;

class student {
	int age;
	int height;
	int weight;
};

int main()
{
	student s1;
	student s2 = student();
	

	int* pi = new int;
	float* pf = new float;

	*pi = 5;
	int& a = *pi;
	a = 10;

	*pf = 1.5;
	float& b = *pf;
	b = 3.14;


	return 0;
}