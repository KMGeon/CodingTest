#include<bits/stdc++.h>
using namespace std;

const int safe = 54;

int m, n, k, ret;
int grid[safe][safe];
int visited[safe][safe];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};


void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
            if (grid[ny][nx] == 1 && !visited[ny][nx]) {
                dfs(ny, nx);
            }
        }
    }
    return;
}

int main() {
    int t;
    cin >> t; // 테스트 케이스 개수

    while (t--) {
        cin >> m >> n >> k; // 가로, 세로, 배추 개수

        // 초기화
        memset(grid, 0, sizeof(grid));
        memset(visited, 0, sizeof(visited));
        ret = 0;

        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            grid[y][x] = 1;
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j);
                    ret++;
                }
            }
        }

        cout << ret << '\n';
    }

    return 0;
}
