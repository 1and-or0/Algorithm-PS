#include <iostream>

int main1()
{
	int n = 1260; // 거슬러 줘야 하는 금액
	

	int arr[] = { 500, 100, 50, 10 };
	int count = 0, len_arr = 4;
	
	for (int i = 0; i<len_arr; ++i)
	{
		count += n / arr[i];
		n %= arr[i];
	}
	std::cout << count << std::endl;



	return EXIT_SUCCESS;
}