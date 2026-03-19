#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int n, m;
vector<string> grid;

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;

    grid.resize(n);
    int startX, startY, endX, endY;

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'R') {
                startX = i; startY = j;
            } else if (grid[i][j] == 'D') {
                endX = i; endY = j;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({startX, startY});

    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    visited[startX][startY] = true;
    bool found = false;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;

        if (x == endX && y == endY) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny) && !visited[nx][ny] && grid[nx][ny] != '#') {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }

    if (found) {

        pair<int, int> curr = parent[endX][endY];
        
        while (curr.first != -1 && grid[curr.first][curr.second] != 'R') {
            grid[curr.first][curr.second] = 'X';
            curr = parent[curr.first][curr.second];
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << grid[i] << "\n";
    }

    return 0;
}