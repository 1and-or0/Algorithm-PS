#include <iostream>

#define MAX_N 100
#define MAX_R 200
#define OFFSET 100

using namespace std;

int n;
int x1[MAX_N], x2[MAX_N];

int checked[MAX_R + 1];

int main() {
    // 입력
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
        
        // OFFSET을 더해줍니다.
        x1[i] += OFFSET;
        x2[i] += OFFSET;
    }
    
    // 구간을 칠해줍니다.
    // 구간 단위로 진행하는 문제이므로
    // x2[i]에 등호가 들어가지 않음에 유의합니다.
    for(int i = 0; i < n; i++)
        for(int j = x1[i]; j < x2[i]; j++)
            checked[j]++;
    
    // 최댓값을 구합니다.
    int max = 0;
    for(int i = 0; i <= MAX_R; i++)
        if(checked[i] > max)
            max = checked[i];
    
    cout << max;
    return 0;
}
