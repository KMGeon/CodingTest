#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;
int grid[1004][1004];
const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<pair<int, int>> q;

    cin >> m >> n;  // m=가로(열), n=세로(행)

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    int rtn = 0;

    while (!q.empty()) {
        int qSize = q.size();

        for (int s = 0; s < qSize; s++) {
            tie(y, x) = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

                if (grid[ny][nx] == 0) {
                    grid[ny][nx] = 1;
                    q.push({ny, nx});
                }
            }
        }

        if (!q.empty()) rtn++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << rtn;
    return 0;
}