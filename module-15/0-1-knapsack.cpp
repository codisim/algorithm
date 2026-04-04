#include <bits/stdc++.h>
using namespace std;

int val[1005], weigt[1005];

int knapsack(int i, int mx_weigt)
{
    if (i < 0 || mx_weigt <= 0)
        return 0;

    if (weigt[i] <= mx_weigt)
    {
        int opt1 = knapsack(i - 1, mx_weigt - weigt[i]) + val[i];
        int opt2 = knapsack(i - 1, mx_weigt);

        return max(opt1, opt2);
    }
    else
        return knapsack(i - 1, mx_weigt);
}

int main()
{
    int n, mx_weigt;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> val[i];

    for (int i = 0; i < n; i++)
        cin >> weigt[i];

    cin >> mx_weigt;

    return 0;
}