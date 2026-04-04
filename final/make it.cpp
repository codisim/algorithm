#include <bits/stdc++.h>
using namespace std;

int dp[100005];

bool can_reach(int current, int target)
{

    if (current == target)
        return true;

    if (current > target)
        return false;

    if (dp[current] != -1)
        return dp[current];

    bool opt1 = can_reach(current + 3, target);
    bool opt2 = can_reach(current * 2, target);

    dp[current] = (opt1 || opt2);

    return dp[current];
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        memset(dp, -1, sizeof(dp));

        if (can_reach(1, n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}