#include <bits/stdc++.h>
typedef long long int llint;
typedef unsigned long long int ullint;
using namespace std;

vector<int> __vector_;

void __print_all_(int __array_[], int idx, int N, int count)
{
    if (count == 6)
    {
        for (int i = 0; i < 5; i++)
        {
            cout << __vector_[i] << " ";
        }
        cout << __vector_[5] << endl;
        return;
    }
    if (idx == N)
    {
        return;
    }
    __vector_.push_back(__array_[idx]);
    __print_all_(__array_, idx + 1, N, count + 1);
    __vector_.pop_back();
    __print_all_(__array_, idx + 1, N, count);
}

int main()
{
    bool __first_time = true;
    while (true)
    {
        int N;
        cin >> N;
        if (N == 0)
        {
            break;
        }
        if (!__first_time)
        {
            cout << endl;
        }
        else
        {
            __first_time = false;
        }
        int __array_[N];
        for (int _i = 0; _i < N; _i++)
        {
            cin >> __array_[_i];
        }
        __print_all_(__array_, 0, N, 0);
    }
    return 0;
}