#include "Shape.h"

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int main()
{
	Circle c1(3, 4, 5);
	cout << "프로그램 종료\n";
	
	int x = 10, y;
	Point a(1, 2), b;
	
	y = x;
	b = a;

	x = 10, y = 20;
	int z;
	z = 30 + max(x, y);

	return 0;
}