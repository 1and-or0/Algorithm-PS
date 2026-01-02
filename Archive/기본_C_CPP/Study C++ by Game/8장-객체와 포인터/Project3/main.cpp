#include <iostream>
using namespace std;

class Vector {
	int dim; // 벡터의 차원
	double* arr; // 벡터의 각 차원 데이터

public:
	Vector(int d = 0) : dim(d) { arr = new double[dim]; }
	~Vector() { delete[] arr; }

	void setRand(int max = 100)
	{
		for (int i = 0; i < dim; ++i)
		{
			arr[i] = rand() % (max * 10) / 10.0;
		}
	}

	void print(const char* str = "Vector")
	{
		cout << str << "[" << dim << "] = < ";
		for (int i = 0; i < dim; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << ">\n";
	}

	void add(Vector* a, Vector* b)
	{
		for (int i = 0; i < dim; ++i)
			arr[i] = a->arr[i] + b->arr[i];
	}

	void add(Vector& a, Vector& b)
	{
		for (int i = 0; i < dim; ++i)
			arr[i] = a.arr[i] + b.arr[i];
	}

	void clone(Vector& a) 
	{
		if (dim > 0) delete[] arr;
		dim = a.dim;
		arr = new double[dim];
		for (int i = 0; i < dim; ++i)
		{
			arr[i] = a.arr[i];
		}
	}

	// void operator = (Vector& a) { clone(a); }
	Vector& operator = (Vector& a) { clone(a); return *this; }
	Vector(Vector& a) : dim(0) { clone(a); }

	/*
	void addx(Vector a, Vector b)
	{
		for (int i = 0; i < dim; ++i)
		{
			arr[i] = a.arr[i] + b.arr[i];
		}
	
	}
	*/
};


int main()
{
	Vector u(3), v(5), w(3), z(3);

	u.setRand();
	u.print(" U ");
	

	v.setRand();
	v.print(" V ");
	
	w.setRand();
	w.print(" W ");

	w.add(&u, &v);
	w.print(" W ");

	z.setRand();
	z.print(" Z ");

	z.clone(u);
	z.print(" Z(= U)");

	v = z;
	v.print(" V ");

	w = v = z;
	w.print(" W ");

	return 0;
}