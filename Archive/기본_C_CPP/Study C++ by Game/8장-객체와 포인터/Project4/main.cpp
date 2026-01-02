#include <iostream>
using namespace std;

#define pie 3.14

#include <cstdio>

class Point {
	int x, y;
	static int count;
public:
	static void printCount() { printf("PtCount: %d\n", count); }

	Point(const Point& p) : x(p.x), y(p.y) { ++count; }

	Point(int xx = 0, int yy = 0) : x(xx), y(yy) { ++count; }
	~Point() { --count; }

	void print(const char* msg = "Point")
	{
		printf("%s: (%d, %d)\n", msg, x, y);
	}

	void add(Point a, Point b)
	{
		x = a.x + b.x;
		y = a.y + b.y;
	}
};

int Point::count = 0;

int main()
{
	cout << sin(pie / 2) << endl;


	Point p(1, 2), q(3, 4), r;
	Point::printCount();

	p.print("P");
	q.print("Q");

	Point* pPt;
	pPt = new Point(5, 6);
	pPt->print("pPt");

	r.add(p, q);
	r.print("(P + Q)");

	delete pPt;
	Point::printCount();


	return 0;
}