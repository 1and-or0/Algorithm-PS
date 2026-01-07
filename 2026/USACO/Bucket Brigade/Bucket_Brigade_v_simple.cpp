/*
* https://usaco.org/index.php?page=viewproblem2&cpid=939
* USACO 2019 US Open Contest, Bronze
* Problem 1. Bucket Brigade
* 
* https://usaco.guide/problems/usaco-939/user-solutions
* One Code | Votes: 8
* 소의 개수를 맨해튼 거리로 푼 다른 사람의 정답 코드
*/
#include <iostream>
//#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main() 
{
    //freopen("buckets.in", "r", stdin);
    //freopen("buckets.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int barn_i, barn_j, rock_i, rock_j, lake_i, lake_j;
    for (int i = 0; i < 10; i++) 
    {
        string s;
        cin >> s;
        for (int j = 0; j < 10; j++) 
        {
            if (s[j] == 'B') 
            { 
                barn_i = i; 
                barn_j = j; 
            }
            if (s[j] == 'R') 
            {   
                rock_i = i; 
                rock_j = j; 
            }
            if (s[j] == 'L') 
            { 
                lake_i = i; 
                lake_j = j; 
            }
        }
    }

    int dist_br = abs(barn_i - rock_i) + abs(barn_j - rock_j);
    int dist_bl = abs(barn_i - lake_i) + abs(barn_j - lake_j);
    int dist_rl = abs(rock_i - lake_i) + abs(rock_j - lake_j);

    if ((barn_i == lake_i || barn_j == lake_j) && dist_bl == dist_br + dist_rl)
        cout << dist_bl + 1 << "\n";
    else
        cout << dist_bl - 1 << "\n";

    return 0;
}