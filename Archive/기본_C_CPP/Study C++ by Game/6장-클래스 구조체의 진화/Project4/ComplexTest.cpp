#include "Complex_.h"

int main()
{
	Complex a, b, c;

	a.read(" A = ");
	b.read(" B = ");

	c.add(a, b);

	a.print(" A = ");
	b.print(" B = ");
	c.print(" A + B = ");

	a.set(5, 6);
	a.print(" A =");

	return 0;
}