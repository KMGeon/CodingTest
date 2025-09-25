#include <bits/stdc++.h>
using namespace std;

int n, m;
int grid[1004][1004];
const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    queue<pair<int, int>> q;

    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m && grid[ny][nx] == 0) {
                grid[ny][nx] = grid[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }

    int maxVal = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                cout << -1 << endl;
                return 0;
            }
            maxVal = max(maxVal, grid[i][j]);
        }
    }

    cout << maxVal - 1 << endl;
    return 0;
}