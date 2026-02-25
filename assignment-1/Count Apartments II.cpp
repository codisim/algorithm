#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
int n, m;

vector<pair<int,int>> moved = {{-1,0},{1,0},{0,-1},{0,1}};

bool valid(int i, int j)
{
    return (i >= 0 && j >= 0 && i < n && j < m);
}

int dfs(int si, int sj)
{
    vis[si][sj] = true;
    int cnt = 1;  

    for(int i = 0; i < 4; i++)
    {
        int ci = si + moved[i].first;
        int cj = sj + moved[i].second;

        if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
        {
            cnt += dfs(ci, cj);
        }
    }

    return cnt;
}

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];

    memset(vis, false, sizeof(vis));

    vector<int> apartments;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!vis[i][j] && grid[i][j] == '.')
            {
                int rooms = dfs(i, j);
                apartments.push_back(rooms);
            }
        }
    }

    if(apartments.empty())
    {
        cout << 0 << endl;
        return 0;
    }

    sort(apartments.begin(), apartments.end());

    for(int x : apartments)
        cout << x << " ";

    cout << endl;

    return 0;
}