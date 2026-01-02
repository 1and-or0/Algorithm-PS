#include <climits>
#include <iostream>
#define endl "\n"
using namespace std;

int const addition = 0, subtraction = 1, multiplication = 2, division = 3;
const int n_max = 11;
int n;
int nums[n_max] = {0};
int cnt[4] = {0};
int _min = INT_MAX, _max = INT_MIN;

int calculate(int a, int op, int b)
{
    int result = 0;
    switch (op)
    {
    case addition:
        result = a + b;
        break;
    case subtraction:
        result = a - b;
        break;
    case multiplication:
        result = a * b;
        break;
    case division:
        result = a / b;
        break;
    default:
        cout << "op is unvalid" << endl;
        break;
    }

    return result;
}

void func(int left, const int index)
{
    if (index >= n)
    {
        if (_max < left)
            _max = left;
    
        if (_min > left)
            _min = left;
        return;
    }

    for (int op_i = 0; op_i < sizeof(cnt)/sizeof(cnt[0]); op_i++)
    {
        if (cnt[op_i] == 0)
            continue;
        int temp = calculate(left, op_i, nums[index]);
        cnt[op_i] -= 1;
        func(temp, index + 1);
        cnt[op_i] += 1;
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    
    for (int i = 0; i < sizeof(cnt)/sizeof(cnt[0]); i++)
    {
        cin >> cnt[i];
    }

    func(nums[0], 1);

    cout << _max << endl;
    cout << _min << endl;

    return 0;
}
