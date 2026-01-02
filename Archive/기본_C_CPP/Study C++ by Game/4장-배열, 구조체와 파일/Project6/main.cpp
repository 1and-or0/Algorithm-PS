#include <cstring>
#include <cstdio>

struct Complex {
	double real;
	double img;
};

bool compare(Complex a, Complex b)
{
	if (a.real > b.real)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool compare(Complex a, Complex b, short result)
{
	if (result != -1)
	{
		result = (a.real > b.real);
	}
	return (a.real > b.real);
}


int main()
{
	Complex a = { 1.0, 2.0 };
	Complex b = { 3.0, 4.0 };

	printf("%d\n", 2 > 3);
	printf("%d\n", a.real > b.real);
	
	printf("%d\n", compare(a, b));
	printf("%d\n", compare(b, a));
	printf("%d\n", compare(b, b));

	return 0;
}