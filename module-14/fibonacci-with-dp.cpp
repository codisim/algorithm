#include <bits/stdc++.h>
using namespace std;

long long int dp[1005];

long long int fibo(int n)
{
    if (n < 2)
        return n;

    dp[n] = (fibo(n - 1) + fibo(n - 2));
    return dp[n];
}

int main()
{
    memset(dp, -1, sizeof(dp));

    long long int n;
    cin >> n;

    long long int val = fibo(n);

    cout << val;
    return 0;
}