#include <bits/stdc++.h>
using namespace std;

int n, a, b;

bool inBorder(int number)
{
    return (0 <= number && number <= n);
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    // 입력받기
    cin >> n >> a >> b;
    
    // <알고리즘~>
    if(a > b)
        swap(a, b);
    
    int cnt = 0; int* arr = new int[n+1];
    arr[0] = 0; arr[1] = 1;
    if(inBorder(a+1))
        arr[a+1] = 1;
    if(inBorder(b+1))
        arr[b+1] = 1;
    
    for (int i = 2; i < a+1; i++)
    {
        arr[i] = i;
    }
    for (int i = a+2; i < b+1; i++)
    {
        arr[i] = arr[i-(a+1)]+1;
    }
    for (int i = b+2; i < n+1; i++)
    {   // a명을 새치기해야 할수도 b명을 새치기해야 할수도 있으니까... 두 경우의 수가 모두 있으니까
        arr[i] = min(arr[i-(a+1)], arr[i-(b+1)])+1;
    }
    // <~알고리즘>

    // 정답 출력
    cout << arr[n] << "\n";

    delete[] arr;

    return 0;
}

