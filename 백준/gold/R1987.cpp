#include <bits/stdc++.h>
using namespace std;

int n, m, maxCnt = 1;
char grid[24][24];
bool visited[26];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void go(int y, int x, int cnt) {
    maxCnt = max(maxCnt, cnt);

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

        int alphaIdx = grid[ny][nx] - 'A';
        if (visited[alphaIdx]) continue;

        visited[alphaIdx] = true;
        go(ny, nx, cnt + 1);
        visited[alphaIdx] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n >> m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }

    visited[grid[0][0] - 'A'] = true;
    go(0, 0, 1);

    cout << maxCnt << '\n';

    return 0;
}