#include <iostream>

int main2()
{
	int n, k;
	std::cin >> n >> k;

	int count = 0;
	while (true)
	{
		int target = (n / k) * k;
		count += n - target;
		n = target;
		if (n < k)
			break;

		count += 1;
		n /= k;
	}
	count += n - 1;
	std::cout << count;

	return EXIT_SUCCESS;
}