#include<bits/stdc++.h>
using namespace std;

int n, ret;
int grid[30][30], visited[30][30];
const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
vector<int> complexSizes;

int dfs(int y, int x) {
    int rtn = 1;
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
        if (grid[ny][nx] == 0) continue;
        rtn += dfs(ny, nx);
    }
    return rtn;
}

bool check(int y, int x) {
    return grid[y][x] == 1 && !visited[y][x];
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++) {
            grid[i][j] = row[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (check(i, j)) {
                int complexSize = dfs(i, j);
                complexSizes.push_back(complexSize);
                ret++;
            }
        }
    }

    sort(complexSizes.begin(), complexSizes.end());

    cout << ret << endl;
    for (int size : complexSizes) {
        cout << size << endl;
    }

    return 0;
}