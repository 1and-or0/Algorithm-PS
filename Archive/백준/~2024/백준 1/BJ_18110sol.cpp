#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    if (n == 0) //n이 0이면 0출력 후 종료
    {
        cout << 0 << endl;
        return 0;
    }

    //입력
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());    //정렬

    float res = 0;

    // 30%의 절사평균을 구함 - // 아래, 위로 15%
    float tmp = n * 0.15;
    tmp = round(tmp);    //반올림

    // 반올림한 절사평균을 아래15%, 위 15%명을 제외하고 더함
    for (int i = tmp; i < n - tmp; i++)
        res += v[i];

    res /= (n - tmp * 2);    //평균
    res = round(res);    //반올림

    cout << res << endl;

    return 0;
}