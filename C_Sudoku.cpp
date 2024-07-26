#include <bits/stdc++.h>
typedef long long int llint;
typedef unsigned long long int ullint;
using namespace std;

bool __is_printed_;

void _get_perfect_sudoko(int *_int_array, int idx)
{
    if (__is_printed_)
    {
        return;
    }
    else if (idx == 16)
    {
        int _arr_1__[4] = {};
        _arr_1__[_int_array[0] - 1]++;
        _arr_1__[_int_array[1] - 1]++;
        _arr_1__[_int_array[4] - 1]++;
        _arr_1__[_int_array[5] - 1]++;

        int _arr_2__[4] = {};
        _arr_2__[_int_array[2] - 1]++;
        _arr_2__[_int_array[3] - 1]++;
        _arr_2__[_int_array[6] - 1]++;
        _arr_2__[_int_array[7] - 1]++;

        int _arr_3__[4] = {};
        _arr_3__[_int_array[8] - 1]++;
        _arr_3__[_int_array[9] - 1]++;
        _arr_3__[_int_array[12] - 1]++;
        _arr_3__[_int_array[13] - 1]++;

        int _arr_4__[4] = {};
        _arr_4__[_int_array[10] - 1]++;
        _arr_4__[_int_array[11] - 1]++;
        _arr_4__[_int_array[14] - 1]++;
        _arr_4__[_int_array[15] - 1]++;

        for (int i = 0; i < 16; i++)
        {
            if (i < 4)
            {
                _arr_1__[_int_array[i] - 1]++;
            }
            else if (i < 8)
            {
                _arr_2__[_int_array[i] - 1]++;
            }
            else if (i < 12)
            {
                _arr_3__[_int_array[i] - 1]++;
            }
            else if (i < 16)
            {
                _arr_4__[_int_array[i] - 1]++;
            }
        }

        for (int i = 0; i < 16; i++)
        {
            if (i % 4 == 0)
            {
                _arr_1__[_int_array[i] - 1]++;
            }
            else if (i % 4 == 1)
            {
                _arr_2__[_int_array[i] - 1]++;
            }
            else if (i % 4 == 2)
            {
                _arr_3__[_int_array[i] - 1]++;
            }
            else if (i % 4 == 3)
            {
                _arr_4__[_int_array[i] - 1]++;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            if (_arr_1__[i] != 3 || _arr_2__[i] != 3 || _arr_3__[i] != 3 || _arr_4__[i] != 3)
            {
                return;
            }
        }
        for (int i = 0; i < 16; i++)
        {
            cout << _int_array[i];
            if ((i + 1) % 4 == 0)
            {
                cout << endl;
            }
        }
        __is_printed_ = true;
        return;
    }
    int arr1[4] = {};
    int arr2[4] = {};
    if (_int_array[idx] == 99)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_int_array[idx / 4 * 4 + i] != 99)
            {
                arr1[_int_array[idx / 4 * 4 + i] - 1]++;
            }
            if (_int_array[4 * i + idx % 4] != 99)
            {
                arr2[_int_array[4 * i + idx % 4] - 1]++;
            }
        }
        for (int i = 1; i < 5; i++)
        {
            if (arr1[i - 1] == 0 && arr2[i - 1] == 0)
            {
                int __temp_ = _int_array[idx];
                _int_array[idx] = i;
                _get_perfect_sudoko(_int_array, idx + 1);
                _int_array[idx] = __temp_;
            }
        }
    }
    else
    {
        _get_perfect_sudoko(_int_array, idx + 1);
    }
}

int main()
{
    int t, temp = 1;
    cin >> t;
    while (temp - 1 != t)
    {
        __is_printed_ = false;
        string str[4];
        for (int i = 0; i < 4; i++)
        {
            cin >> str[i];
        }
        int _int_array[16];
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (str[i][j] != '*')
                {
                    _int_array[4 * i + j] = str[i][j] - 48;
                }
                else
                {
                    _int_array[4 * i + j] = 99;
                }
            }
        }
        cout << "Case #" << temp << ":" << endl;
        _get_perfect_sudoko(_int_array, 0);
        temp++;
    }
    return 0;
}