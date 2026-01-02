#ifndef BITS_STDC_H
#define BITS_STDC_H
#include <bits/stdc++.h>
using namespace std;
#endif // !BITS_STDC_H

int main_BJ_2475_CPP()
{
	int arr[5];
	int sum = 0;
	for (int i = 0; i < 5; ++i)
	{
		cin >> arr[i];
		arr[i] *= arr[i];
		sum += arr[i];
	}
	
	cout << sum % 10;

	return EXIT_SUCCESS;
}