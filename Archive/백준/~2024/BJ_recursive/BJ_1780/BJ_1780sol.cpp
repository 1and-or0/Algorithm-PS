#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> graph;  // 종이 입력받을 벡터
vector<int> sum(3);  // 정답 저장하는 벡터

void makepaper(int row, int col, int size);
bool checkpaper(int row, int col, int size);
void sumpaper(int row, int col);

int main()
{
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    // resize(10, 100) vector 크기 10에 원소 100으로 초기화 한다는 뜻. 
    graph.resize(n, vector<int>(n, 0)); // 이차원 벡터를 초기화함
    // 입력받음
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    makepaper(0, 0, n);

    for (int i = 0; i < sum.size(); i++)
    {
        cout << sum[i] << endl;
    }
}

void makepaper(int row, int col, int size)
{
    int inner_size = size / 3;
    if (inner_size < 1) // 최소 크기일때 종료 - 병합해야할까?
        return; //cout << "종이의 분할가능 크기는 최소 1입니다" << endl;
    else
    {
        // 가장 큰 종이로 보고 검사
        if (checkpaper(row, col, size) == true)
        { // 가장 큰 종이인 경우 시작 위치는 항상 0행0열 == graph[0][0]임
            sumpaper(0, 0);
            return;
        }

        // 9등분 중 왼쪽 위가 하나의 종이인가 검사
        if (checkpaper(row, col, inner_size) == false)
        {// 하나의 종이가 아닌 경우
            // cout << "graph1 is not same" << endl;
            makepaper(row, col, inner_size);
        }
        else
        { // true면 모두 같은 종이의 구성요소가 있다는 뜻이다.
           // cout << "graph1 is same." << endl;
            sumpaper(row, col);
        }

        // 9등분 중 가운데 위가 하나의 종이인가 검사
        if (checkpaper(row, col + inner_size, inner_size) == false)
        { // cout << "graph2에 종이의 요소는 모두 같지 않습니다" << endl;
            makepaper(row, col + inner_size, inner_size);
        }
        else
        { // cout << "graph2 is  same" << endl;
            sumpaper(row, col + inner_size);
        }

        // 9등분 중 오른쪽 위가 하나의 종이인가 검사
        if (checkpaper(row, col + 2 * inner_size, inner_size) == false)
        {// cout << "graph3 is not same" << endl;
            makepaper(row, col + 2 * inner_size, inner_size);
        }
        else
        {//cout << "graph3 is same" << endl;
            sumpaper(row, col + 2 * inner_size);
        }

        // 9등분 중 왼쪽 가운데가 하나의 종이인가 검사
        if (checkpaper(row + inner_size, col, inner_size) == false)
        { //cout << "graph4 is not same" << endl;
            makepaper(row + inner_size, col, inner_size);
        }
        else
        { // cout << "graph4 is same" << endl;
            sumpaper(row + inner_size, col);
        }

        // 9등분 중 중앙이 하나의 종이인가 검사
        if (checkpaper(row + inner_size, col + inner_size, inner_size) == false)
        {// cout << "graph5 is not same" << endl;
            makepaper(row + inner_size, col + inner_size, inner_size);
        }
        else
        {// cout << "graph5 is same" << endl;
            sumpaper(row + inner_size, col + inner_size);
        }

        //9등분 중 오른쪽 가운데가 하나의 종이인가 검사
        if (checkpaper(row + inner_size, col + 2 * inner_size, inner_size) == false)
        {// cout << "graph6 is not same" << endl;
            makepaper(row + inner_size, col + 2 * inner_size, inner_size);
        }
        else
        {//cout << "graph6 is same" << endl;
            sumpaper(row + inner_size, col + 2 * inner_size);
        }
        
        // 9등분중 왼쪽 아래가 하나의 종이인가 검사
        if (checkpaper(row + 2 * inner_size, col, inner_size) == false)
        { // cout << "graph7 is not same" << endl;
            makepaper(row + 2 * inner_size, col, inner_size);
        }
        else
        {// cout << "graph7 is same" << endl;
            sumpaper(row + 2 * inner_size, col);
        }

        // 9등분 중 가운데 아래가 하나의 종이인가 검사
        if (checkpaper(row + 2 * inner_size, col + inner_size, inner_size) == false)
        {// cout << "graph8 is not same" << endl;
            makepaper(row + 2 * inner_size, col + inner_size, inner_size);
        }
        else
        {// cout << "graph8 is same" << endl;
            sumpaper(row + 2 * inner_size, col + inner_size);
        }

        // 9등분 중 오른쪽 아래가 하나의 종이인가 검사
        if (checkpaper(row + 2 * inner_size, col + 2 * inner_size, inner_size) == false)
        { // cout << "graph9 is not same" << endl;
            makepaper(row + 2 * inner_size, col + 2 * inner_size, inner_size);
        }
        else
        { // cout << "graph9 is same" << endl;
            sumpaper(row + 2 * inner_size, col + 2 * inner_size);
        }
    }
}

// -1은 sum[0]에, 0은 sum[1]에, 1은 sum[2]에 종이의 개수를 더해줌
void sumpaper(int row, int col)
{
    int num = graph[row][col];
    switch (num)
    {
    case -1:
        sum[0] += 1;
        break;
    case 0:
        sum[1] += 1;
        break;
    case 1:
        sum[2] += 1;
        break;
    }
}

// row행 col열부터 크기 s의 정방행렬이 모두 같은 원소인지 검사하는 함수
bool checkpaper(int row, int col, int s)
{
    int check = graph[row][col]; //-1,0,1 아닌 숫자면 가능
    bool cp = true;
    for (int i = row; i < row + s; i++)
    {
        if (cp == false)
        {
            break;
        }
        for (int j = col; j < col + s; j++)
        {
            if (check != graph[i][j]) {
                cp = false;
                break;
            }
        }
    }
    return cp;
}
