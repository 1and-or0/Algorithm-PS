#include <cstdio>

int main()
{
	class Complex {
	private:
		double real;
		double imag;
	public:
		void set(double r, double i)
		{
			real = r;
			imag = i;
		}

		void print()
		{
			printf("%4.2f + %4.2fi\n", real, imag);
		}

		double mag()
		{
			return (real * real + imag * imag);
		}

	};


	Complex a, b;

	a.set(1.0, 2.0);
	a.print();

	b.set(3, 5);
	b.print();

	printf("a¿« ≈©±‚: %lf", a.mag());

	return 0;
}