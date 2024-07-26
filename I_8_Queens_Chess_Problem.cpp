#include <bits/stdc++.h>
typedef long long int llint;
typedef unsigned long long int ullint;
using namespace std;

bool is_printed;
int soln;

void get_result(int rows[], int idx, string perms, int fc, char fr)
{
    if (idx == 8)
    {
        string cols = "12345678";
        bool is_everything_okeh = true;
        for (int i = 0; i < 8; i++)
        {
            for (int j = i + 1; j < 8; j++)
            {
                if (abs(perms[i] - perms[j]) == abs(cols[i] - cols[j]))
                {
                    is_everything_okeh = false;
                    break;
                }
            }
            if (!is_everything_okeh)
            {
                break;
            }
        }
        if (is_everything_okeh)
        {
            printf("%2d      ", soln++);
            for (int i = 0; i < 8; i++)
            {
                cout << (perms[i] - 48);
                if (i != 7)
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
        return;
    }
    if (idx == fc)
    {
        get_result(rows, idx + 1, perms + to_string(fr), fc, fr);
    }
    else
    {
        for (int i = 0; i < 8; i++)
        {
            if (rows[i] != -1)
            {
                int temp = rows[i];
                rows[i] = -1;
                get_result(rows, idx + 1, perms + to_string(temp), fc, fr);
                rows[i] = temp;
            }
        }
    }
}

int main()
{
    int t = 1, temp = 1;
    cin >> t;
    while (true)
    {
        soln = 1;
        int x, y;
        cin >> x >> y;
        int rows[] = {1, 2, 3, 4, 5, 6, 7, 8};
        rows[x - 1] = -1;
        cout << "SOLN       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8" << endl
             << endl;
        get_result(rows, 0, "", y - 1, (char)x);

        if (temp == t)
        {
            break;
        }
        cout << endl;
        temp++;
    }
    return 0;
}