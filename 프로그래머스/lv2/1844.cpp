#include <bits/stdc++.h>
using namespace std;

int grid[104][104], visited[104][104];
int n, m;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void bfs(int y, int x) {
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});

    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || grid[ny][nx] == 0) continue;
            if (visited[ny][nx]) continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

int solution(vector<vector<int>> maps) {
    memset(grid, 0, sizeof(grid));
    memset(visited, 0, sizeof(visited));

    n = maps.size();
    m = maps[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = maps[i][j];
        }
    }

    bfs(0, 0);

    if (visited[n-1][m-1] == 0) {
        return -1;
    } else {
        return visited[n-1][m-1];
    }
}