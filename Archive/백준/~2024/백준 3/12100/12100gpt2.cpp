#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // For memcpy

using namespace std;

// 방향 상수 정의
const int LEFT = 0;
const int UP = 1;
const int RIGHT = 2;
const int DOWN = 3;

// 게임 설정
int N; // 보드의 크기
const int LIMIT = 5; // 최대 이동 횟수
int maxValue = 0; // 최대 블록 값

// 비어있는 칸을 나타내는 상수
const int BLANK = 0;

// 함수 선언
void dfs(vector<vector<int>> &map, int step);
vector<vector<int>> action(const vector<vector<int>> &mapCopy, int dir);
void updateMaxValue(const vector<vector<int>> &mapCopy);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력: 보드 초기 상태
    cin >> N;
    vector<vector<int>> map(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    // DFS를 통해 최대 블록 값 찾기
    dfs(map, 0);

    // 결과 출력
    cout << maxValue;
    return 0;
}

/**
 * 깊이 우선 탐색을 통해 모든 가능한 이동 경로를 탐색하고 최대 블록 값을 업데이트합니다.
 *
 * @param map 현재 보드 상태
 * @param step 현재 이동 단계
 */
void dfs(vector<vector<int>> &map, int step)
{
    // 종료 조건: 이동 횟수가 제한에 도달했을 경우
    if(step == LIMIT)
    {
        updateMaxValue(map);
        return;
    }

    // 모든 방향으로 이동 시도
    for(int dir = 0; dir < 4; dir++)
    {
        // 현재 보드 상태를 복사하여 새로운 보드 상태 생성
        vector<vector<int>> mapCopy = map;
        // 선택한 방향으로 이동을 수행
        vector<vector<int>> newMap = action(mapCopy, dir);

        // 재귀적으로 다음 이동 단계로 진행
        dfs(newMap, step + 1);
    }
}

/**
 * 주어진 방향으로 보드를 이동시키고, 이동 후의 새로운 보드 상태를 반환합니다.
 *
 * @param mapCopy 이동 전의 보드 상태
 * @param dir 이동할 방향 (LEFT, UP, RIGHT, DOWN)
 * @return 이동 후의 새로운 보드 상태
 */
vector<vector<int>> action(const vector<vector<int>> &mapCopy, int dir)
{
    // 이동 후의 보드 상태를 저장할 새로운 보드
    vector<vector<int>> newMap = mapCopy;

    switch(dir)
    {
        case LEFT:
        {
            // 각 행을 왼쪽으로 이동
            for(int row = 0; row < N; row++)
            {
                int nBlank = 0; // 연속된 빈 칸의 수
                for(int col = 1; col < N; col++)
                {
                    if(newMap[row][col] == BLANK)
                    {
                        nBlank++;
                        continue;
                    }
                    else
                    {
                        // 왼쪽으로 병합 가능한지 확인
                        if(newMap[row][col] == newMap[row][col - 1 - nBlank])
                        {
                            newMap[row][col - 1 - nBlank] *= 2; // 병합
                            newMap[row][col] = BLANK; // 현재 칸을 빈 칸으로 설정
                        }
                        // 병합이 불가능하지만 왼쪽에 빈 칸이 있는 경우 이동
                        else if(newMap[row][col - 1 - nBlank] == BLANK)
                        {
                            newMap[row][col - 1 - nBlank] = newMap[row][col];
                            newMap[row][col] = BLANK;
                            nBlank++;
                        }
                        // 병합 불가능하고 왼쪽에 다른 값이 있는 경우 현재 위치로 이동
                        else
                        {
                            newMap[row][col - nBlank] = newMap[row][col];
                            if(nBlank != 0)
                            {
                                newMap[row][col] = BLANK;
                            }
                        }
                    }
                }
            }
            break;
        }

        case UP:
        {
            // 각 열을 위쪽으로 이동
            for(int col = 0; col < N; col++)
            {
                int nBlank = 0; // 연속된 빈 칸의 수
                for(int row = 1; row < N; row++)
                {
                    if(newMap[row][col] == BLANK)
                    {
                        nBlank++;
                        continue;
                    }
                    else
                    {
                        // 위쪽으로 병합 가능한지 확인
                        if(newMap[row][col] == newMap[row - 1 - nBlank][col])
                        {
                            newMap[row - 1 - nBlank][col] *= 2; // 병합
                            newMap[row][col] = BLANK; // 현재 칸을 빈 칸으로 설정
                        }
                        // 병합이 불가능하지만 위쪽에 빈 칸이 있는 경우 이동
                        else if(newMap[row - 1 - nBlank][col] == BLANK)
                        {
                            newMap[row - 1 - nBlank][col] = newMap[row][col];
                            newMap[row][col] = BLANK;
                            nBlank++;
                        }
                        // 병합 불가능하고 위쪽에 다른 값이 있는 경우 현재 위치로 이동
                        else
                        {
                            newMap[row - nBlank][col] = newMap[row][col];
                            if(nBlank != 0)
                            {
                                newMap[row][col] = BLANK;
                            }
                        }
                    }
                }
            }
            break;
        }

        case RIGHT:
        {
            // 각 행을 오른쪽으로 이동
            for(int row = 0; row < N; row++)
            {
                int nBlank = 0; // 연속된 빈 칸의 수
                for(int col = N - 2; col >= 0; col--)
                {
                    if(newMap[row][col] == BLANK)
                    {
                        nBlank++;
                        continue;
                    }
                    else
                    {
                        // 오른쪽으로 병합 가능한지 확인
                        if(newMap[row][col] == newMap[row][col + 1 + nBlank])
                        {
                            newMap[row][col + 1 + nBlank] *= 2; // 병합
                            newMap[row][col] = BLANK; // 현재 칸을 빈 칸으로 설정
                        }
                        // 병합이 불가능하지만 오른쪽에 빈 칸이 있는 경우 이동
                        else if(newMap[row][col + 1 + nBlank] == BLANK)
                        {
                            newMap[row][col + 1 + nBlank] = newMap[row][col];
                            newMap[row][col] = BLANK;
                            nBlank++;
                        }
                        // 병합 불가능하고 오른쪽에 다른 값이 있는 경우 현재 위치로 이동
                        else
                        {
                            newMap[row][col + nBlank] = newMap[row][col];
                            if(nBlank != 0)
                            {
                                newMap[row][col] = BLANK;
                            }
                        }
                    }
                }
            }
            break;
        }

        case DOWN:
        {
            // 각 열을 아래쪽으로 이동
            for(int col = 0; col < N; col++)
            {
                int nBlank = 0; // 연속된 빈 칸의 수
                for(int row = N - 2; row >= 0; row--)
                {
                    if(newMap[row][col] == BLANK)
                    {
                        nBlank++;
                        continue;
                    }
                    else
                    {
                        // 아래쪽으로 병합 가능한지 확인
                        if(newMap[row][col] == newMap[row + 1 + nBlank][col])
                        {
                            newMap[row + 1 + nBlank][col] *= 2; // 병합
                            newMap[row][col] = BLANK; // 현재 칸을 빈 칸으로 설정
                        }
                        // 병합이 불가능하지만 아래쪽에 빈 칸이 있는 경우 이동
                        else if(newMap[row + 1 + nBlank][col] == BLANK)
                        {
                            newMap[row + 1 + nBlank][col] = newMap[row][col];
                            newMap[row][col] = BLANK;
                            nBlank++;
                        }
                        // 병합 불가능하고 아래쪽에 다른 값이 있는 경우 현재 위치로 이동
                        else
                        {
                            newMap[row + nBlank][col] = newMap[row][col];
                            if(nBlank != 0)
                            {
                                newMap[row][col] = BLANK;
                            }
                        }
                    }
                }
            }
            break;
        }
    }

    return newMap;
}

/**
 * 현재 보드 상태에서 최대 블록 값을 업데이트합니다.
 *
 * @param mapCopy 현재 보드 상태
 */
void updateMaxValue(const vector<vector<int>> &mapCopy)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(mapCopy[i][j] > maxValue)
            {
                maxValue = mapCopy[i][j];
            }
        }
    }
}
