#include <iostream>
#include <algorithm>
using namespace std;

// 각 크레인의 현재 위치를 저장하는 배열
int crane_positions[51] = { 0 };

// 크레인의 최대 적재량을 저장하는 배열
int crane_capacities[51];

// 상자의 방문 여부를 확인하는 배열
bool box_moved[10001] = { 0 };

// 상자의 무게를 저장하는 배열
int box_weights[10001];

// 크레인과 상자의 개수를 나타내는 변수, 상자가 모두 옮겨졌는지 확인하는 변수, 크레인 최대 적재량
int num_cranes, num_boxes, moved_boxes_count = 0, max_crane_capacity = 0;

int main()
{
    int time = 0;  // 모든 상자를 옮기는 데 걸리는 시간

    // 크레인의 수와 최대 적재량 입력 받기
    cin >> num_cranes;
    for (int i = 0; i < num_cranes; i++)
    {
        cin >> crane_capacities[i];
        if (crane_capacities[i] > max_crane_capacity)
            max_crane_capacity = crane_capacities[i];
    }

    // 상자의 수와 각 상자의 무게 입력 받기
    cin >> num_boxes;
    for (int i = 0; i < num_boxes; i++)
        cin >> box_weights[i];

    // 상자를 무게 기준으로 내림차순 정렬 (무거운 상자를 먼저 처리)
    sort(box_weights, box_weights + num_boxes, greater<>());

    // 크레인 최대 적재량보다 무거운 상자가 있으면 불가능한 경우이므로 -1 출력
    if (box_weights[0] > max_crane_capacity)
    {
        cout << -1;
        return 0;
    }

    // 모든 상자를 옮길 때까지 반복
    while (moved_boxes_count != num_boxes)
    {
        for (int i = 0; i < num_cranes; i++)
        {
            // 크레인이 옮길 수 있는 상자를 찾는 반복문
            for (int j = crane_positions[i]; j < num_boxes; j++)
            {
                // 해당 상자가 아직 옮겨지지 않았고, 크레인이 옮길 수 있는 무게라면
                if (!box_moved[j] && crane_capacities[i] >= box_weights[j])
                {
                    box_moved[j] = true;   // 상자를 옮김 표시
                    moved_boxes_count++;   // 옮긴 상자 수 증가
                    break;                 // 현재 크레인은 다음 상자로 이동
                }
                crane_positions[i]++;      // 현재 크레인 위치 갱신
            }
        }
        time++;  // 한 번의 작업이 끝나면 시간 증가
    }

    // 모든 상자를 옮기는 데 걸린 시간 출력
    cout << time;
    return 0;
}
