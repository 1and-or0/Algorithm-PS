#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string word1;
string word2;

int iAlphabetOrNum(char c)
{
    int result = 0;
    if (c >= '0' && c <= '9')
    {
        result =  (int ) c - '0';
    }
    else if (c >= 'A' && c <= 'Z')
    {
        result = (int) (c - 'A') + 10;
    }
    else
    {
        result = (int)(c - 'a') + 10 + 26;
    }

    return result;
}

int main()
{
    cin >> word1;
    cin >> word2;

    // Please write your code here.
    // 0~9 + A~Z + a~z 각 개수 저장
    const int size = 10 + (int)('Z'-'A') + 1 + (int)('z' - 'a') + 1;
    
    int cnt1[size] = { 0 };
    int cnt2[size] = { 0 };
    bool isNo = false;
    int n = max(word1.length(), word2.length());
    if (word1.length() != word2.length())
    {
        isNo = true;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cnt1[iAlphabetOrNum(word1[i])] += 1;
            cnt2[iAlphabetOrNum(word2[i])] += 1;
        }

        for (int i = 0; i < size; i++)
        {
            if (cnt1[i] != cnt2[i])
            {
                isNo = true;
                break;
            }
        }
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
