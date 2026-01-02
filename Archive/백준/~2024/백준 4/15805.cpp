#include <iostream>
#include <vector>
using namespace std;

const int n_max = 200000;

// 전역 변수 선언
vector<int> stk; // 스택을 위한 벡터
int parent[(n_max+1)/2 + 1]; // 정답을 저장할 배열 (최대 100,000개의 요소)

// 메인 함수 시작
int main() 
{   // 입력 및 출력을 더 빠르게 하기 위한 설정
    ios::sync_with_stdio(0); cin.tie(0); // cin과 cout의 동기화 해제

    int N;
    cin >> N; // 노드의 수 N 입력
    int NN = (N + 1) / 2; // 출력할 정답의 개수 (N의 절반 + 1)

    N--; // 첫 번째 요소를 이미 읽었으므로 N을 1 줄임

    int x;
    cin >> x; // 첫 번째 노드 값을 입력
    parent[x] = -1; // parent 배열의 해당 인덱스에 -1 할당

    stk.emplace_back(x); // 첫 번째 노드를 스택에 추가

    // N개의 노드에 대해 반복
    while (N--) 
    {
        cin >> x; // 다음 노드 값을 입력
        // 현재 노드 x가 스택의 상단 노드와 같은 경우
        if (x == parent[stk.back()]) 
        {
            stk.pop_back(); // 스택에서 마지막 노드 제거
        }
        else 
        {
            parent[x] = stk.back();

            // 현재 노드 x를 스택에 추가
            stk.emplace_back(x);
        }
    }

    // 정답 개수 NN 출력
    cout << NN << '\n';
    // 정답 배열의 값들을 출력
    for (int i = 0; i < NN; i++)
        cout << parent[i] << ' '; // 각 정답을 공백으로 구분하여 출력

    return 0;
}
