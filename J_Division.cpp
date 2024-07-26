#include <bits/stdc++.h>
using namespace std;

bool solution_exist;

bool __get_ans(int N)
{
    int j, temp1, temp2, p = 0;
    int arr[10] = {};
    for (int i = 1234; i <= 98765; i++)
    {
        j = N * i;
        if (j > 98765)
        {
            break;
        }
        temp1 = i;
        temp2 = j;
        int a = 5;
        while (a--)
        {
            arr[temp1 % 10]++;
            temp1 /= 10;
            arr[temp2 % 10]++;
            temp2 /= 10;
        }
        int vd = 1;
        for (int i = 0; i < 10; i++)
        {
            if (arr[i] == 0)
            {
                vd = 0;
            }
            arr[i] = 0;
        }
        if (vd)
        {
            printf("%05d / %05d = %d\n", j, i, N);
            p = 1;
        }
    }
    if (p)
    {
        return true;
    }
    return false;
}

int main()
{
    bool st = false;
    while (true)
    {
        solution_exist = false;
        int N;
        scanf("%d", &N);
        if (N == 0)
        {
            return 0;
        }
        if (st)
        {
            cout << endl;
        }
        st = true;
        if (!__get_ans(N))
        {
            printf("There are no solutions for %d.\n", N);
        }
    }
    return 0;
}