/*
* https://usaco.org/index.php?page=viewproblem2&cpid=568
* USACO 2015 December Contest, Bronze
* Problem 2. Speeding Ticket
*/
#include <iostream>
#include <array>
#include <utility>
#define endl "\n"

using namespace std;

int main() {
    //freopen("speeding.in", "r", stdin);
    //freopen("speeding.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    const int _max = 100;
    array<pair<int, int>, _max> limits;
    array<pair<int, int>, _max> journey;

    for (int i = 0; i < n; i++)
    {
        cin >> limits[i].first;
        cin >> limits[i].second;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> journey[i].first;
        cin >> journey[i].second;
    }

    int ans = 0;
    int road_sum = 0;
    int journey_road_sum = 0;
    for (int i = 0, j = 0; i < n and j < m; ) // 종료 조건 확인 필요
    {
        int road = limits[i].first;
        int speed_limit = limits[i].second;

        int journey_road = journey[j].first;
        int journey_speed = journey[j].second;

        ans = max(ans, journey_speed - speed_limit);

        if (road_sum + road < journey_road_sum + journey_road)
        {
            i += 1;
            road_sum += road;
        }
        else if (road_sum + road > journey_road_sum + journey_road)
        {
            j += 1;
            journey_road_sum += journey_road;
        }
        else // road_sum + road == journey_road_sum + journey_road
        {
            i += 1;
            j += 1;

            road_sum += road;
            journey_road_sum += journey_road;
        }
    }

    cout << ans;

    return 0;
}