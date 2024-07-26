#include <bits/stdc++.h>
typedef long long int llint;
typedef unsigned long long int ullint;
using namespace std;

int __max_time_;
string __solN__;

void __get_ans_(int arr[], int N, int K, string str, int idx, int __sum_)
{
    if (__sum_ > N)
    {
        return;
    }
    else if (__sum_ > __max_time_)
    {
        __max_time_ = __sum_;
        __solN__ = str;
    }
    if (idx == K)
    {
        return;
    }
    __get_ans_(arr, N, K, str + to_string(arr[idx]) + " ", idx + 1, __sum_ + arr[idx]);
    __get_ans_(arr, N, K, str, idx + 1, __sum_);
}

int main()
{
    while (true)
    {
        __max_time_ = INT_MIN;
        __solN__ = "";
        int N;
        if (scanf("%d", &N) == -1)
        {
            break;
        }
        int K;
        cin >> K;
        int arr[K];
        for (int i = 0; i < K; i++)
        {
            cin >> arr[i];
        }
        __get_ans_(arr, N, K, "", 0, 0);
        cout << __solN__ << "sum:" << __max_time_ << endl;
    }
    return 0;
}