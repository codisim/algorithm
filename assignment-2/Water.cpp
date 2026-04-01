#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> heights(n);
    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        heights[i] = {h, i};
    }

    sort(heights.rbegin(), heights.rend());

    int idx1 = heights[0].second;
    int idx2 = heights[1].second;

    if (idx1 < idx2)
    {
        cout << idx1 << " " << idx2 << endl;
    }
    else
    {
        cout << idx2 << " " << idx1 << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}