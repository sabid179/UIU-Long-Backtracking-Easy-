#include <bits/stdc++.h>
typedef long long int llint;
typedef unsigned long long int ullint;
using namespace std;

bool __is_ok_;

bool __is_it_possible(int __tuples_[], int idx, int resuu)
{
    if (idx == 5)
    {
        if (resuu == 23)
        {
            return true;
        }
        return false;
    }
    return __is_it_possible(__tuples_, idx + 1, resuu + __tuples_[idx]) || __is_it_possible(__tuples_, idx + 1, resuu - __tuples_[idx]) || __is_it_possible(__tuples_, idx + 1, resuu * __tuples_[idx]);
}

void __send_custom_tuple_(int __tuples_[], int idx, int __custom_tuple_[])
{
    if (idx == 5)
    {
        __is_ok_ = __is_it_possible(__custom_tuple_, 1, __custom_tuple_[0]);
        return;
    }
    for (int i = 0; i < 5; i++)
    {
        if (__tuples_[i] != -1)
        {
            int __temp_ = __tuples_[i];
            __tuples_[i] = -1;
            __custom_tuple_[idx] = __temp_;
            __send_custom_tuple_(__tuples_, idx + 1, __custom_tuple_);
            if (__is_ok_)
            {
                return;
            }
            __tuples_[i] = __temp_;
        }
    }
}

int main()
{
    // int t = 1;
    // 	cin >> t;
    while (true)
    {
        __is_ok_ = false;
        int __tuples_[5];
        bool __is_all_zero = true;
        for (int i = 0; i < 5; i++)
        {
            cin >> __tuples_[i];
            if (__tuples_[i] != 0)
            {
                __is_all_zero = false;
            }
        }
        if (__is_all_zero)
        {
            break;
        }
        int __for_custom_[5];
        __send_custom_tuple_(__tuples_, 0, __for_custom_);
        if (__is_ok_)
        {
            cout << "Possible" << endl;
        }
        else
        {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}