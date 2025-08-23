#include<bits/stdc++.h>
using namespace std;

constexpr int num = 104;
int grid[num][num];
int visited[num][num];
int n, m;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};


void result(int y, int x) {
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
            q.push({ny, nx});  // ★ 새로운 좌표를 넣어야 함!
        }
    }
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;  // 한 줄을 문자열로 읽기
        for (int j = 0; j < m; j++) {
            grid[i][j] = row[j] - '0';  // 문자를 숫자로 변환
        }
    }

    result(0, 0);

    cout << visited[n-1][m-1]  << endl;

    return 0;
}
