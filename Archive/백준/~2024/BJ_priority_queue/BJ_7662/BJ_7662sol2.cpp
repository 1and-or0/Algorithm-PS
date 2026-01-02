#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000 + 1;

int N;
// n번째로 들어온 숫자가 heap에 남아있는지 여부를 저장함
bool visited[MAX]; // index: n번째, true: 남아있음, false: 없음(pop되버림)

int main(void)
{
    ios_base::sync_with_stdio(0);    cin.tie(0);

    int test_case;
    cin >> test_case;

    for (int t = 0; t < test_case; t++)
    {
        cin >> N;

        priority_queue<pair<int, int>> maxHeap;  // 내림차순 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; // 오름차순

        for (int i = 0; i < N; i++)
        {
            char op;
            int num;

            cin >> op >> num;

            if (op == 'I')
            {
                maxHeap.push({ num, i });
                minHeap.push({ num, i });

                visited[i] = true;
            }
            else
            {
                if (num == 1)
                {
                    //유효하지 않은 숫자들 전부 pop
                    while (!maxHeap.empty() && !visited[maxHeap.top().second])
                        maxHeap.pop();

                    if (!maxHeap.empty())
                    {
                        //pop하므로 유효하지 않다고 표시
                        visited[maxHeap.top().second] = false;

                        maxHeap.pop();
                    }
                }
                else // D -1
                {
                    while (!minHeap.empty() && !visited[minHeap.top().second])
                        minHeap.pop();

                    if (!minHeap.empty())
                    {
                        visited[minHeap.top().second] = false;

                        minHeap.pop();
                    }
                }
            }
        }

        while (!maxHeap.empty() && !visited[maxHeap.top().second])
            maxHeap.pop();

        while (!minHeap.empty() && !visited[minHeap.top().second])
            minHeap.pop();

        if (minHeap.empty() && maxHeap.empty())
            cout << "EMPTY\n";
        else
            cout << maxHeap.top().first << " " << minHeap.top().first << "\n";
    }

    return 0;
}
