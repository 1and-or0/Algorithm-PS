#include <iostream>
#define endl "\n"
using namespace std;

int n, r1, c1, r2, c2;
const int n_max = 20000;

void print_ans(int x1, int y1, int x2, int y2)
{
	for (int i = 0, s = r1; i < r2 - r1 + 1; i++, s++) 
	{
		for (int j = 0, e = c1; j < c2 - c1 + 1; j++, e++)
		{
			int x = s % (2 * n - 1);
			int y = e % (2 * n - 1);
			int dis = abs((n - 1) - x) + abs((n - 1) - y);

			if (dis >= n)
				cout << ".";
			else 
				cout << (char)((dis % 26) + 'a');
		}
		cout << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> r1 >> c1 >> r2 >> c2;

	print_ans(r1, c1, r2, c2);

	return 0;
}