#include <bits/stdc++.h>
using namespace std;

int factorial_iterative(int n)
{
	int result = 1;
	for (int i = 0; i < n; ++i)
	{
		result *= i + 1;
	}
	return result;
}

int factorial_recursive(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return n * factorial_recursive(n - 1);
	}
}

int main_ex_recursive()
{
	int f_f = factorial_iterative(4);
	cout << f_f << endl;

	int f_f2 = factorial_recursive(4);
	cout << f_f2 << endl;

	return EXIT_SUCCESS;
}