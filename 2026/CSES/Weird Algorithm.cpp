/*
* https://cses.fi/problemset/task/1068/
* Weird Algorithm
*/
#include <iostream>

using namespace std;

int main() {
	long long n; // NOTE: 중요 - Use long long to handle large numbers in the sequence
	cin >> n;
	
	cout << n << " ";
	while (n != 1) {
		if (n % 2 == 0) {
			n = n / 2;
		} else {
			n = 3 * n + 1;
		}
		cout << " " << n;
	}

	return 0;
}