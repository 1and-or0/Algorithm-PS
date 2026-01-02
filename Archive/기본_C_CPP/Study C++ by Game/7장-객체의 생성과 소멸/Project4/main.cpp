struct Complex {
	double real, imag;
	Complex(double r = 10, double i = 10) : real(r), imag(i) {}

};

Complex operator+ (Complex& a, Complex& b)
{
	Complex c;
	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;
	return c;
}

int main()
{
	Complex a, b, c;
	b.real = 44;
	b.imag = 91;

	c = a + b;

	Complex& cibal = c;
	cibal.real = 100;

	cibal = b;
	cibal.imag = -99;



	return 0;
}