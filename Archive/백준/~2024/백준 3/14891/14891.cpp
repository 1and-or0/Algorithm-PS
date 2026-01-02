#include <iostream>
#include <cmath>
#include <cstring>
#define endl "\n"
using namespace std;

const int clockwise = 1;
const int counterclockwise = -clockwise;

const int left_tooth = 6;
const int right_tooth = 2;

const int n = 0;
const int s = 1;

const int nums_of_gear = 4;
const int tooth_of_saw = 8;
char gears[nums_of_gear][tooth_of_saw+1] = {0}; 
int will_rotate[nums_of_gear] = {0};
int k;

bool is_connected(int i_gear, int j_gear)
{
    if (i_gear < 0 || j_gear < 0 || i_gear >= nums_of_gear || j_gear >= nums_of_gear)
        return false;

    
    if (i_gear > j_gear)
    {
        return (gears[j_gear][right_tooth] != gears[i_gear][left_tooth]);
    }
    else if (i_gear < j_gear)
    {
        return (gears[j_gear][left_tooth] != gears[i_gear][right_tooth]);
    }
    else
    {
        cout << "check value" << endl;
        return -1; 
    }
}

void rotate_a_gear(int i_gear, int dir)
{
    if (dir == clockwise)
    {
        char temp = gears[i_gear][tooth_of_saw-1];
        for (int t = 0; t < tooth_of_saw - 1; t++)
        {
            gears[i_gear][tooth_of_saw - t -1] = gears[i_gear][tooth_of_saw - t -1-1];
        }
        gears[i_gear][0] = temp;
    }
    else if (dir == counterclockwise)
    {
        char temp = gears[i_gear][0];
        for (int t = 0; t < tooth_of_saw - 1; t++)
        {
            gears[i_gear][t] = gears[i_gear][t+1];
        }
        gears[i_gear][tooth_of_saw -1] = temp;
    }
    else
    {
        cout << "dir: " << dir << " is not valid"<< endl;
    }
}

void rotate_gears(int n_gear, int dir)
{
    if (dir != 1 && dir != -1)
    {
        cout << "check value of dir" << endl;
        return;
    }
    
    will_rotate[n_gear] = dir;
    
    for (int g = 0; g < n_gear; g++)
    {
        if (gears[n_gear -g -1][right_tooth] != gears[n_gear -g][left_tooth])
        {
            will_rotate[n_gear -g-1] = -will_rotate[n_gear -g];
        }
        else
        {
            will_rotate[n_gear -g-1] = 0;
            break;
        }
    }
    
    for (int g = 0; g < nums_of_gear - n_gear-1; g++)
    {
        if (gears[n_gear +g][right_tooth] != gears[n_gear +g +1][left_tooth])
        {
            will_rotate[n_gear +g+1] = -will_rotate[n_gear +g];
        }
        else
        {
            will_rotate[n_gear +g+1] = 0;
            break;
        }
    }

    rotate_a_gear(n_gear, dir);
    for (int r = 0; r < n_gear; r++)
    {
        if (will_rotate[n_gear-r-1] == 0)
            break;
        rotate_a_gear(n_gear-r-1, -will_rotate[n_gear-r]);
    }

    for (int r = 0; r < nums_of_gear -n_gear-1; r++)
    {
        if (will_rotate[n_gear+r+1] == 0)
            break;
        rotate_a_gear(n_gear+r+1, -will_rotate[n_gear+r]);
    }
}

void ans()
{
    int total = 0;
    for (int i = 0; i < nums_of_gear; i++)
    {
        total += pow(2, i) * (((int)gears[i][0])-48);
    }
    cout << total;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 0; i < nums_of_gear; i++)
    {
        cin >> gears[i];
    }

    cin >> k;
    for (int j = 0; j < k; j++)
    {
        int n_gear, dir;
        cin >> n_gear >> dir;
        n_gear -= 1;

        rotate_gears(n_gear, dir);
    }
    
    ans();

    // for (int i = 0; i < nums_of_gear; i++)
    // {
    //     cout << i << "_gear: " << gears[i] << endl;
    // }

    return 0;
}
