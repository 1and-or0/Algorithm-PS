#include <iostream>
#define endl "\n"
using namespace std;

string l, r;

int main()
{	
	cin >> l >> r;
	
	if (r.size() > l.size())
		cout << 0;
	else if (r.size() == l.size())
	{
		int temp = 0;
		for (int i = 0; i < l.size(); i++)
		{
			if (l[i] == '8' && r[i] == '8')
				temp += 1;
			else if (l[i] != r[i])
				break;
		}
		cout << temp;
	}


	return 0;
}