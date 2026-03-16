#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> moved = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '-')
        return false;
    return true;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + moved[i].first;
        int cj = sj + moved[i].second;

        if (valid(ci, cj) && !vis[ci][cj])
            dfs(ci, cj);
    }
}

int main()
{
    if (!(cin >> n >> m))
        return 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int si, sj, di, dj;
    cin >> si >> sj;
    cin >> di >> dj;

    memset(vis, false, sizeof(vis));

    if (grid[si][sj] == '.')
    {
        dfs(si, sj);
    }

    if (vis[di][dj])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}