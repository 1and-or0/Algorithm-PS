#include <cstdio>

struct Complex {
	double real;
	double imag;
};

void printComplex(Complex c, const char msg[] = "복소수:")
{
	printf(" %s %4.2f + %4.2fi\n", msg, c.real, c.imag);
}

Complex readComplex(const char* msg = "복소수:")
{
	Complex c;
	printf(" %s ", msg);
	scanf_s("%lf%lf", &c.real, &c.imag);
	return c;
}

Complex addComplex(Complex a, Complex b)
{
	Complex c;
	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;
	return c;
}

void resetComplex(Complex a)
{
	a.real = a.imag = 0.0;
}

Complex resetComplex()
{
	Complex a;
	a.real = 0.0;
	a.imag = 0.0;
	return a;
}


int main()
{
	Complex a, b, c;
	a = readComplex("a(입력):");
	b = readComplex("b(입력):");
	c = addComplex(a, b);

	printComplex(a, " a = ");
	printComplex(b, " b = ");
	printComplex(c, " a + b = ");

	resetComplex(c);
	printComplex(c, "reset(c) =");

	c = resetComplex();
	printComplex(c, "reset(c) =");

	return 0;
}