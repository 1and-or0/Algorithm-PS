/*
* https://usaco.org/index.php?page=viewproblem2&cpid=591
* USACO 2016 January Contest, BronzeProblem 1. Promotion Counting
*/
#include <iostream>

#define endl "\n"

using namespace std;

int main() {
    // 진법 문제랑 비슷해 보이는 데
    // 여러 단계 승급이 가능한 게 포인트인 듯
    // 
    // 새로운 참가자가 늘어나면 무조건 브론즈로 시작한다고 가정하고 풀어야 하는 건가
    // 그렇게 되면 플레티넘 등급의 증가분은 무조건 해당 대회에서 골드->플레로 승급한 인원이 됨
    // 
    // 그렇게 되면 그 이전 등급에서 명이 감소해야 함.
    // 
    // let, 등급 브실골플 = B, S, G, P = i_1, i_2, i_3, i_4 .
    // { k | 4 -> 3 -> 2 -> 1 }
    // 
    // if i_k - i_{k-1} = a,
    // then i_{k-1} - i_{k-2} = -a. (should be)
    // 
    
    // 높은 등급부터 한 단계씩 낮은 등급으로 진행
    // 현재 등급의 인원 차 만큼 다음 단계에서 비교하는 등급간에 인원 차가 발생해야 함
    // 그렇지 않다면 그 만큼 더 낮은 등급에서 승급해온 참가자들이 존재한다는 뜻


    // 간단하게 높은 등급부터 보고 
    // (브+실+골), 플 -> 플만 봄 증가분 확인 -> 그럼 해당 증가분 만큼 골드에서 줄어야 함
    // ㄴ 줄지 않았다? 그 만큼 실에서 골로 추가로 올라온 거임
    
    // 예시 
    //  1 (+3명 추가 등록)   3   
    //  2                   2   
    //  3                   1   
    //  4                   7   
    // 정답 출력
    // 1
    // 1
    // 3

    // 플 비교 7 - 4 = 3   ->   3명이 골에서 플로 승급했구나! 는 확정
    // 추가로 해당 승급한 인원이 골에서부터 온 건지 실버에서 부터 온 건지 브론즈에서부터 온 건지 모름

    // 골 비교 1 - 3 = -2  ->   3명이 골에서 플로 승급했었는데 그럼 골에서 3명이 안 줄고 2명만 줄었다는 건 
    // 브나 실에서부터 골까지 승급한 참가자가 1명 있구나~

    // 실 비교 2 - 2 = 0 -> 골드로 승급한 참가자가 1명 있었는데 실버는 인원이 같다는 건 
    // 1명이 브에서 실로 승급헀구나~

    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

    int participants[4][2] = { 0 };
    const int before_contest = 0;
    const int after_contest = 1;

    for (int i = 0; i < size(participants); i++)
    {
        cin >> participants[i][before_contest] >> participants[i][after_contest];
    }

    int gap = 0;
    
    int ans[3] = { 0 };
    for (int i = 0; i < size(ans); i++)
    {
        int index = size(participants) - 1 - i;
        int before = participants[index][before_contest];
        int after = participants[index][after_contest];

        gap += after - before;
        ans[i] = gap;
        
        // 음.. ans[i] 가 음수가 되는 경우는 없나? 
        // 없음 - 높은 등급부터 확인 하기에 증가분이 반영되어 있음
    }

    for (int i = 0; i < size(ans); i++)
    {
        int index = size(ans) - 1 - i;
        cout << ans[index] << endl;
    }

    return 0;
}