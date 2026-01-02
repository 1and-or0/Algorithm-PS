struct Point {
	int x, y;
	Point(int xx = 0, int yy= 0) : x(xx), y(yy) {}
};

class Circle {
	Point center;
	int radius;
public:
	Circle(int cx=0, int cy=0, int r=0) : center(cx, cy), radius(r) {}

	Circle(Point p, int r = 0) : center(p), radius(r) {}

	double perimeter() { return 2 * 3.141592 * radius; }
	double circumference() { return 2 * 3.141592 * radius; }
};

int main()
{
	Circle cir(10, 20, 5);
	Circle* ptr = &cir;


	double peri = cir.perimeter();
	double peri2 = ptr->perimeter();

	// cir.radius = 2;
	// ptr->radius = 2;

	Point A_p(2, 4);
	Circle cir2(A_p, 10);
	A_p.x = 1;
	
	Point* ptr2 = &A_p;
	ptr2->y = 15;


	return 0;
}