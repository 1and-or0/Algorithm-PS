#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string word1;
string word2;

int main()
{
    cin >> word1;
    cin >> word2;

    // Please write your code here.
    sort(word1.begin(), word1.end());
    sort(word2.begin(), word2.end());

    bool isNo = false;

    for (int i = 0; i < min(word1.length(), word2.length()); i++)
    {
        if (word1[i] != word2[i])
        {
            isNo = true;
            break;
        }
    }

    if (word1.length() != word2.length())
    {
        isNo = true;
    }

    if (isNo)
    {
        cout << "No";
    }
    else
    {
        cout << "Yes";
    }
    return 0;
}
