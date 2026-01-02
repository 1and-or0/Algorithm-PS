#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

const int n_max = 1000000;
bool is_not_prime[n_max+1] = { 0 };
int n;

void set_prime()
{
	is_not_prime[0] = true;
	is_not_prime[1] = true;

	for (int i = 2; i * i < n_max + 1; i++)
	{
		if (is_not_prime[i] == false)
		{
			for (int j = i*i; j < n_max + 1; j+=i)
			{
				is_not_prime[j] = true;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	set_prime();
	
	cin >> n;
	while (n != 0)
	{
		bool is_way = false;
		for (int i = 3; i < n/2+1; i +=2)
		{
			if (is_not_prime[i] == false && is_not_prime[n - i] == false)
			{
				cout << n << " = " << i << " + " << n - i << endl;
				is_way = true;
				break;
			}
		}

		if (not is_way)
		{
			cout << "Goldbach's conjecture is wrong." << endl;
		}

		cin >> n;
	}

	return 0;
}