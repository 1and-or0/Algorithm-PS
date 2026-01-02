#include <cstdio>

int& getCount()
{
	static int count = 0;
	++count;
	//	int& _count = count;

	return count; // _count;
}


int MazeGameMap[480][640];

inline int& Map(int x, int y)
{
	return MazeGameMap[y][x];
}

int factorial(int n)
{
	if (n == 1)
		return 1;
	else if(n > 1)
	{
		return n * factorial(n - 1);
	}
}

int factorial_2(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		int result = 1;

		for (int i = n; i > 0; --i)
		{
			result *= (i);
		}

		return result;
	}
}

int fibonacci(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	return fibonacci(n - 1) + fibonacci(n - 1);
}

int fibonacci_ver2(int n)
{
	if (n < 2)
	{
		return n;
	}

	int temp, current = 1, last = 0;

	for (int i = 2; i < n; ++i)
	{
		temp = current;
		current += last;
		last = temp;
	}
	return current;
}

int fibonacci_my(int n)
{
	if (n < 2)
	{
		return n;
	}

	int an, a1 = 0, a2 = 1;
	
	for (int i = 1; i < n; ++i)
	{
		an = a2 + a1;
		a1 = a2;
		a2 = an;
	}
	return an;
}



int main()
{
	for (int i = 0; i < 5; ++i)
	{
		printf("count: %d\n", getCount());
	}

	getCount() = 10;

	for (int i = 0; i < 5; ++i)
	{
		printf("count: %d\n", getCount());
	}


	int factorial_4 = factorial_2(4);
	int factorial_4_ver2 = factorial(4);

	for (int i = 0; i < 10; ++i)
	{
		printf("%d!: %d\n", i + 1, factorial(i + 1));
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("%d!: %d\n", i + 1, factorial_2(i + 1));
	}

	for (int i = 1; i < 10; ++i)
	{
		printf("fibonacci(%d): %d\n", i, fibonacci_ver2(i));
	}

	for (int i = 1; i < 10; ++i)
	{
		printf("fibonacci_my(%d): %d\n", i, fibonacci_my(i));
	}

	return 0;
}