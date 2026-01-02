#pragma once
#include <iostream>
using namespace std;

struct Point {
	int x, y;
	Point(int xx = 0, int yy = 0) : x(xx), y(yy) 
	{
		cout << "점(" << x << ", " << y << ") 생성자 \n";
	}

	~Point()
	{
		cout << "점(" << x << ", " << y << ") 소멸자 \n";
	}
};

class Circle {
	Point center;   // 원 중심
	int radius;  // 원 반지름
public:
	Circle(int cx = 0, int cy = 0, int r = 0) : center(cx, cy), radius(r) 
	{
		cout << "원(반지름: " << radius << ") 생성자 \n";
	}

	~Circle()
	{
		cout << "원(반지름: " << radius << ") 소멸자 \n";
	}
};

