#include<bits/stdc++.h>
using namespace std;

int visited[104][104], grid[104][104];
int n, m, cnt, cnt2;
const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
vector<pair<int, int> > v; // 치즈가 녹아야 하는 배열

void go(int y, int x) {
    visited[y][x] = 1;

    if (grid[y][x] == 1) {
        v.push_back({y, x});
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
        go(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    while (true) {
        memset(visited, 0, sizeof(visited));
        v.clear();
        go(0, 0);

        cnt2 = v.size();

        for (auto b: v) {
            grid[b.first][b.second] = 0;
        }

        bool flag = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) flag = 1;
            }
        }
        cnt++;
        if (!flag) break;
    }

    cout << cnt << endl << cnt2 << endl;
    return 0;
}
