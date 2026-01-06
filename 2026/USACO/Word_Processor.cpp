/*
* https://usaco.org/index.php?page=viewproblem2&cpid=987
* USACO 2020 January Contest, Bronze Problem 1. 
* Word Processor
*/
#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

int main() {
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    int now_line_len = 0;
    bool is_need_new_line = false;

    // 출력 끝에 공백 문자 있으면 오답임. 라인 끝에는 `\n`만 가능
    bool is_need_spliter = false;
    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        int need_space = size(word);
        
        if (now_line_len + need_space > k)
        {
            cout << endl;
            now_line_len = 0;
            is_need_spliter = false;
        }

        if (now_line_len <= k)
        {
            if (is_need_spliter)
            {
                cout << " ";
                is_need_spliter = false;
            }

            cout << word;
            now_line_len += size(word);
            is_need_spliter = true;
        }

    }
    cout << endl;

    return 0;
}