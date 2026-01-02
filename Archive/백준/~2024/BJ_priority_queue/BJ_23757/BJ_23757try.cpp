#include <bits/stdc++.h>
using namespace std;
#define INPUT_YES 1

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    const int size = 100000 + 1;
    // 입력받기 0: 상자 혹은 장난감 존재 유무, 1: ci 입력, 2: wi 입력
    int checkInput[size][3] = { 0 };
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
    { // 박스
        int temp; cin >> temp;
        checkInput[temp][0] = INPUT_YES;
        checkInput[temp][1] += 1;
    }
    for (int i = 0; i < m; i++)
    { // 장난감
        int temp; cin >> temp;
        checkInput[temp][0] = INPUT_YES;
        checkInput[temp][2] += 1;
    }
    
    /// <알고리즘~>
    priority_queue<int> boxes;
    priority_queue<int> toys;
    // maxheap에 원소 추가 - 시간복잡도 고려 큰 원소부터 추가
    for (int i = 0; i < size; i++)
    {
        if(checkInput[size - 1 - i][0] == INPUT_YES)
        {   
            int num_box = checkInput[size - 1 - i][1];
            int num_toy = checkInput[size - 1 - i][2];
            // 상자인 경우
            for (int j = 0; j < num_box - num_toy; j++)
            {
                boxes.push(size - 1 - i);
            }
            // 장난감인 경우
            for (int j = 0; j < num_toy - num_box; j++)
            {
                toys.push(size - 1 - i);
            }
        }
    }

    while (!boxes.empty() && !toys.empty())
    {
        int a = boxes.top();
        int b = toys.top();
        if (a == b)
        {
            boxes.pop();
            toys.pop();
            continue;
        }
        else if(a < b)
        {
            break;
        }
        else // if (a > b)
        {
            boxes.pop();
            toys.pop();
            a = a - b;
            boxes.push(a);
        }
    }
    /// <~알고리즘>

    // 정답 출력
    if(toys.empty())
        cout << 1 ;
    else
        cout << 0;
    
    return 0;
}
