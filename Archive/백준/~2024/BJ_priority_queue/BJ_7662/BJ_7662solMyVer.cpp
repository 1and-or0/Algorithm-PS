#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    
    while (t--)
    {
        int op_len;
        cin >> op_len;

        multiset<int> ms;
        while (op_len--)
        {
            char op; int num;
            cin >> op >> num;
            
            if (op == 'D' && !ms.empty())
            {
                multiset<int>::iterator iter;
                switch (num)
                {
                case 1:
                    iter = ms.end();
                    iter--;
                    ms.erase(iter);
                    break;
                case -1:
                    iter = ms.begin();
                    ms.erase(iter);
                    break;
                }
            }
            else if (op == 'I')
            {
                ms.insert(num);
            }
        }

        if (ms.empty())
            cout << "EMPTY" << '\n';
        else
        {
            multiset<int>::iterator end_iter = ms.end();
            end_iter--;
            cout << *end_iter << ' ' << *ms.begin() << '\n';
        }
    }

    return 0;
}