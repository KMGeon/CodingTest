#include<bits/stdc++.h>
using namespace std;

#define y1 aaaa
int grid[104][104], visited[104][104];
int m, n, k;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
vector<int> v;

int dfs(int y, int x) {
    int rtn = 1;
    visited[y][x] = 1;


    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= m || nx < 0 || nx >= n || visited[ny][nx] == 1) continue;
        if (grid[ny][nx] == 1) continue;

        rtn += dfs(ny, nx);
    }
    return rtn;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // m : 세로 ,  n : 가로 , k : 직사각형
    cin >> n >> m >> k;


    for (int i = 0; i < k; i++) {
        int y1, x1, y2, x2;

        for (int i = 0; i < k; i++) {
            cin >> x1 >> y1 >> x2 >> y2;
            for (int x = x1; x < x2; x++) {
                for (int y = y1; y < y2; y++) {
                    grid[x][y] = 1;
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != 1 && visited[i][j] == 0) {
                int rtn = dfs(i, j);
                v.push_back(rtn);
            }
        }
    }

    cout << v.size() << endl;
    sort(v.begin(), v.end());

    for (auto t: v) {
        cout << t << " ";
    }

    return 0;
}
