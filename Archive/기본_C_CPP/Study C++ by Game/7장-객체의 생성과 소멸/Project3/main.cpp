#include <iostream>
using namespace std;

struct Point {
	int x, y;
	Point(int xx = 0, int yy = 0) : x(xx), y(yy) {}
	Point(Point& p) : x(p.x) 
	{
		y = p.y;
		p.y = 999; 
	}
};

Point readPoint()
{
	Point p;
	cout << "좌표를 입력해주세요(x, y): ";
	cin >> p.x >> p.y;
	return p;
}

void printPoint(Point p, const char* str = "Point")
{
	cout << str << ": (" << p.x << ", " << p.y << ")\n";
}


int main()
{
	Point a;

	a = readPoint();
	printPoint(a, "입력 좌표");

	Point b(a);

	a.y = 919;

	return 0;
}