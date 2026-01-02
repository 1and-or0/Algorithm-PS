#include <iostream>
#include <cmath>
#include <bitset>
#define endl "\n"
using namespace std;

int n, k, ans = 0;
const int k_max = 1000;

// bitset[index]위치에 1bit 더하는 연산
void bit_sum(bitset<k_max>& bits, int index)
{
	bitset<1> carry(1);
	while (bits[index] == 1)
	{
		bits[index] = 0;
		index += 1;
	}
	bits[index] = 1;
}

int main()
{
	cin >> n >> k;

	bitset<k_max> n_to_bit(n);

	// get highest Bit Index 
	int highestBitIndex = 0, count_1bit = 0;
	for (int i = 0; i < n_to_bit.size(); i++)
	{
		if (n_to_bit[n_to_bit.size() -1 -i] == 1)
		{
			if (count_1bit < k)
				highestBitIndex = n_to_bit.size() -1 -i;
			count_1bit += 1;
		}
	}
	//cout << count_1bit << endl; 
	//cout << highestBitIndex << endl;
	// get ans
	for (int i = 0; i < n_to_bit.size(); i++)
	{
		if (i == highestBitIndex)
			break;

		if (n_to_bit[i] == 1)
		{
			bit_sum(n_to_bit, i);
			ans += pow(2, i);
		}
	}

	cout << ans;

	return 0;
}