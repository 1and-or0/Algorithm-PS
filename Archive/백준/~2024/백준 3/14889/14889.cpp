#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
using namespace std;

int n;
int synergy[20][20];
bool selected[20];  // 팀을 나누기 위한 방문 배열
int answer = INT_MAX;

void calculate() {
    int start_team = 0, link_team = 0;

    // 두 팀의 시너지를 계산
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (selected[i] && selected[j]) {
                start_team += synergy[i][j] + synergy[j][i];
            }
            else if (!selected[i] && !selected[j]) {
                link_team += synergy[i][j] + synergy[j][i];
            }
        }
    }
    
    // 시너지 차이의 절대값을 구하고 최소값 갱신
    answer = min(answer, abs(start_team - link_team));
}

void backtrack(int idx, int cnt) {
    // 팀이 절반으로 나뉘었을 때 계산
    if (cnt == n / 2) {
        calculate();
        return;
    }
    
    // 인덱스가 범위를 넘으면 종료
    if (idx >= n) return;

    // 현재 사람을 스타트 팀에 넣고 다음 사람 선택
    selected[idx] = true;
    backtrack(idx + 1, cnt + 1);
    
    // 현재 사람을 링크 팀에 넣고 다음 사람 선택
    selected[idx] = false;
    backtrack(idx + 1, cnt);
}

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> synergy[i][j];
        }
    }
    
    backtrack(0, 0);  // 첫 번째 사람부터 시작하여 팀을 나눔
    
    cout << answer << endl;  // 최소 차이 출력
    return 0;
}
