#include <iostream>

int main1_b()
{

    int n = 0, k = 0;
    std::cin >> n;
    std::cin >> k;

    int* p_arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> p_arr[i];
    }

    int count = 0;

    for (int i = 0; i < n; ++i)
    {
        count += k / p_arr[n -1 - i];
        k %= p_arr[n -1 - i];
    }
    std::cout << count;
    delete[] p_arr;

	return 0;
}