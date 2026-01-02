#ifndef BITS_STDC_H2908
#define BITS_STDC_H2908
#include <bits/stdc++.h>
using namespace std;
#endif // !BITS_STDC_H2908

int main_bj_2908()
{
	int a, b;
	cin >> a >> b;

	int r_a = 0, r_b = 0;
	r_a += (a / 100) + (a / 10) % 10 * 10 + a % 10 * 100;
	r_b += (b / 100) + (b / 10) % 10 * 10 + b % 10 * 100;

	cout << (r_a > r_b ? r_a : r_b);

	return EXIT_SUCCESS;
}