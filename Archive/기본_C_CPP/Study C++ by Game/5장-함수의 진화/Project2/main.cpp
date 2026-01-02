#include <cstdio>

struct Complex {
	double real;
	double imag;
};

void printComplex(Complex c, const char* msg = "º¹¼Ò¼ö")
{
	printf(" %s %4.2f + %4.2fi\n", msg, c.real, c.imag);
}

void resetComplex(Complex* a)
{
	a->real = a->imag = 0.0;
}

int main()
{
	Complex c;

	
	resetComplex(&c);
	printComplex(c, "reset(c):");

	return 0;
}