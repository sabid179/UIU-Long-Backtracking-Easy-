#include <bits/stdc++.h>
typedef long long int llint;
typedef unsigned long long int ullint;
using namespace std;

void __print_password_(string str[], string str2, int str1_len, int str2_len, int idx, string __generated_password_)
{
    if (idx == str2_len)
    {
        cout << __generated_password_ << endl;
        return;
    }
    if (str2[idx] == '#')
    {
        for (int i = 0; i < str1_len; i++)
        {
            __print_password_(str, str2, str1_len, str2_len, idx + 1, __generated_password_ + str[i]);
        }
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            __print_password_(str, str2, str1_len, str2_len, idx + 1, __generated_password_ + to_string(i));
        }
    }
}

void __make_function_call_(string str[], string str2[], int N, int M, int idx)
{
    if (idx == M)
    {
        return;
    }
    __print_password_(str, str2[idx], N, str2[idx].length(), 0, "");
    __make_function_call_(str, str2, N, M, idx + 1);
}

int main()
{
    while (true)
    {
        int N;
        if (scanf("%d", &N) == -1)
        {
            break;
        }
        else
        {
            cout << "--" << endl;
        }
        cin.ignore();
        string str[N];
        for (int i = 0; i < N; i++)
        {
            cin >> str[i];
        }
        int M;
        cin >> M;
        string str2[M];
        for (int i = 0; i < M; i++)
        {
            cin >> str2[i];
        }
        __make_function_call_(str, str2, N, M, 0);
    }
    return 0;
}