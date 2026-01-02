#include "Complex.h"

int main()
{
	Complex a, b, c;

	a.readComplex(" A = ");
	b.readComplex(" B = ");

	c.addComplex(a, b);

	a.printComplex(" A = ");
	b.printComplex(" B = ");
	c.printComplex(" A + B = ");

	a.setComplex(5, 6);
	a.printComplex(" A =");

	return 0;
}