#include <bits/stdc++.h>
typedef long long int llint;
typedef unsigned long long int ullint;
using namespace std;

int K;
void print_permutation(char characters[], int pos, int N, string str)
{
    if (K == 0)
    {
        return;
    }
    if (pos == N)
    {
        cout << str << endl;
        K--;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (characters[i] != '.')
        {
            char temp = characters[i];
            characters[i] = '.';
            print_permutation(characters, pos + 1, N, str + temp);
            characters[i] = temp;
        }
    }
}

int main()
{
    int t = 1;
    cin >> t;
    int temp = 0;
    while (t != temp)
    {
        int N;
        cin >> N >> K;
        char characters[N];
        for (int i = 0; i < N; i++) {
            characters[i] = i + 65;
        }
        cout << "Case " << (temp + 1) << ":" << endl;
        print_permutation(characters, 0, N, "");
        temp++;
    }
    return 0;
}