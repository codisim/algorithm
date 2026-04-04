#include <bits/stdc++.h>
using namespace std;

int val[1005], weigt[1005];
int dp[1005][1005];

int knapsack(int i, int mx_weigt)
{
    if (i < 0 || mx_weigt <= 0)
        return 0;

    if (dp[i][mx_weigt] != -1)
        return dp[i][mx_weigt];

    if (weigt[i] <= mx_weigt)
    {
        int opt1 = knapsack(i - 1, mx_weigt - weigt[i]) + val[i];
        int opt2 = knapsack(i - 1, mx_weigt);

        dp[i][mx_weigt] = max(opt1, opt2);
        return dp[i][mx_weigt];
    }
    else
    {
        dp[i][mx_weigt] = knapsack(i - 1, mx_weigt);
        return dp[i][mx_weigt];
    }
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

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= mx_weigt; j++)
            dp[i][j] = -1;

    cout << knapsack(n - 1, mx_weigt);

    return 0;
}