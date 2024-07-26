#include <bits/stdc++.h>
typedef long long int llint;
typedef unsigned long long int ullint;
using namespace std;

bool is_prime(int N)
{
    int iteration_count = sqrt(N) + 1;
    for (int i = 2; i < iteration_count; i++)
    {
        if (N % i == 0)
        {
            return false;
        }
    }
    return true;
}

void get_sequence(int arr[], int idx, int N, int temp_arr[])
{
    if (idx == N)
    {
        bool is_all_ok = true;
        if (!is_prime(temp_arr[N - 1] + 1))
        {
            is_all_ok = false;
        }
        if (is_all_ok)
        {
            for (int i = 0; i < N; i++)
            {
                cout << temp_arr[i];
                if (i != N - 1)
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
        return;
    }
    for (int i = 1; i < N; i++)
    {
        if (arr[i] != -1)
        {
            temp_arr[idx] = arr[i];
            arr[i] = -1;
            if (is_prime(temp_arr[idx] + temp_arr[idx - 1]))
            {
                get_sequence(arr, idx + 1, N, temp_arr);
            }
            arr[i] = temp_arr[idx];
        }
    }
}

int main()
{
    int cases = 1, N;
    if (scanf("%d", &N) == -1)
    {
        return 0;
    }
    while (true)
    {
        cout << "Case " << cases++ << ":" << endl;
        int arr[N];
        for (int i = 0; i < N; i++)
        {
            arr[i] = i + 1;
        }
        int temp_arr[N] = {1};
        get_sequence(arr, 1, N, temp_arr);
        if (scanf("%d", &N) != -1)
        {
            cout << endl;
        }
        else
        {
            break;
        }
    }
    return 0;
}