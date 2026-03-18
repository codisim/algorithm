#include <bits/stdc++.h>
using namespace std;

int dis[105][105];
int n, m;

vector<pair<int, int>> moves = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int bfs(int si, int sj, int di, int dj)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dis[i][j] = -1;
        }
    }

    queue<pair<int, int>> q;
    q.push({si, sj});
    dis[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();

        int r = curr.first;
        int c = curr.second;

        if (r == di && c == dj)
            return dis[r][c];

        for (auto move : moves)
        {
            int nr = r + move.first;
            int nc = c + move.second;

            if (valid(nr, nc) && dis[nr][nc] == -1)
            {
                dis[nr][nc] = dis[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int ki, kj, qi, qj;
        cin >> ki >> kj >> qi >> qj;
        cout << bfs(ki, kj, qi, qj) << endl;
    }
    return 0;
}