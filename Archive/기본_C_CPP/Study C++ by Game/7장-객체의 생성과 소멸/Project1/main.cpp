#include <iostream>

class Complex {
	double real, imag;
public:
	Complex() // 기본 생성자
	{ 
		real = imag = 0.0; 
	}  
	
	Complex(double r, double i)   // 매개변수가 있는 생성자
	{
		real = r;
		imag = i;
	}

	void print(const char* msg = "복소수")
	{
		printf("%s = real: %.2lf, imag: %.2lf\n", msg, real, imag);
		if (imag >= 0)
			printf("%s = %.2f + %.2fi\n", msg, real, imag);
		else
			printf("%s = %.2f - %.2fi\n", msg, real, -1*imag);
	}
};

class new_Complex {
	double real, imag;
public:
	new_Complex(double r = 0, double i = 0)
	{
		real = r;
		imag = i;
	}
};

class same_new_C {
	double real, imag;
public:
	same_new_C(double r=0, double i=0) : real(r), imag(i) {}
};

class ComplexVer2 {
	double real, imag;
	const int version = 2;
	double& imaginary = imag;
};

struct Point {
	int x, y;
	Point(int xx = 0, int yy = 0)
	{
		x = xx;
		y = yy;
	}
};

class Line {
	Point p1, p2;
public:
	Line(int x1, int y1, int x2, int y2)
	{
		p1.x = x1;
		p1.y = y1;
		p2.x = x2;
		p2.y = y2;
	}
};

struct PointVer2 {
	int x, y;
	PointVer2(int xx = 0, int yy = 0) : x(xx), y(yy) {}
};

class LineVer2 {
	PointVer2 p1, p2;
public:
	LineVer2(int x1, int y1, int x2, int y2) : p1(x1, y1), p2(x2, y2) {}
};

int main()
{
	Complex a1;
	a1.print("a1");

	Complex a2(2, -3);
	a2.print("a2");

	return 0;
}