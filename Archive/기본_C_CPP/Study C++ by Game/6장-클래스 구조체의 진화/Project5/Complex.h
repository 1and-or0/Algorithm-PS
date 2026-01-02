#pragma once
#include <cstdio>

class Complex
{
	double real;
	double imag;
public:
	void set(double r, double i)
	{
		real = r;
		imag = i;
	}

	void read(const char* msg = "º¹¼Ò¼ö = ")
	{
		printf("%s", msg);
		scanf("%lf%lf\n", &real, &imag);
	}

	void add(Complex a, Complex b)
	{
		real = a.real + b.real;
		imag = a.imag + b.imag;
	}

	void add(Complex a)
	{
		real += a.real;
		imag += a.imag;
	}

};