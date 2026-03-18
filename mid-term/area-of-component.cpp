#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> moved = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
int current_area;

bool valid(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '-' || vis[i][j])
        return false;
    return true;
}

void dfs(int si, int sj) {
    vis[si][sj] = true;
    current_area++;

    for (int i = 0; i < 4; i++) {
        int ci = si + moved[i].first;
        int cj = sj + moved[i].second;

        if (valid(ci, cj)) {
            dfs(ci, cj);
        }
    }
}

int main() {
    if (!(cin >> n >> m)) return 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    memset(vis, false, sizeof(vis));
    
    int min_area = INT_MAX;
    bool found_component = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                current_area = 0;
                dfs(i, j);
                min_area = min(min_area, current_area);
                found_component = true;
            }
        }
    }

    if (!found_component) {
        cout << -1 << endl;
    } else {
        cout << min_area << endl;
    }

    return 0;
}