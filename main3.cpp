#include<bits/stdc++.h>
using namespace std;

const int safe = 104;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int n, m, startN, startM, endN, endM;
int visited[safe][safe];
int grid[safe][safe];

void BFS(int y, int x) {
    queue<pair<int, int> > q;
    visited[y][x] = 1;
    q.push(make_pair(y, x));

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

int main() {
    cin >> n >> m;
    cin >> startN >> startM;
    cin >> endN >> endM;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    BFS(startN, startM);  // y좌표(행)가 먼저, x좌표(열)가 나중

    cout << visited[endN][endM] - 1 << endl;

    return 0;
}
