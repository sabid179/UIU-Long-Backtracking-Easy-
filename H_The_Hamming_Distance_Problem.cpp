#include <bits/stdc++.h>
typedef long long int llint;
typedef unsigned long long int ullint;
using namespace std;

void __print_all_possible_ans_(int idx, int N, int H, string str)
{
    if (idx == N)
    {
        int dist = 0;
        for (int i = 0; i < N; i++)
        {
            if (str[i] == '1')
            {
                dist++;
            }
        }
        if (dist == H)
        {
            cout << str << endl;
        }
        return;
    }
    __print_all_possible_ans_(idx + 1, N, H, str + "0");
    __print_all_possible_ans_(idx + 1, N, H, str + "1");
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int N, H;
        cin >> N >> H;
        __print_all_possible_ans_(0, N, H, "");
        if (t != 0)
        {
            cout << endl;
        }
    }
    return 0;
}