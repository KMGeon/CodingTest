/*
URL: https://www.acmicpc.net/problem/2589
제약: N≤50, M≤50, 시간 1초
복잡도: O(N×M×(N+M)) ≈ 50×50×100 = 250,000

ASCII 시각화:
각 L에서 BFS:
L-W-L-L    →    1-X-3-4
W-L-W-L         X-2-X-5  
L-L-L-W         3-2-3-X
최대값: 5가 답
*/

#include<bits/stdc++.h>
using namespace std;

int n, m, ret;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
char grid[54][54];
int visited[54][54];

int bfs(int sy, int sx) {
    // visited 초기화
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }
    
    visited[sy][sx] = 1;
    queue<pair<int, int>> q;
    q.push({sy, sx});
    
    int maxDist = 0;

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(grid[ny][nx] != 'L' || visited[ny][nx]) continue;
            
            visited[ny][nx] = visited[y][x] + 1;
            maxDist = max(maxDist, visited[ny][nx] - 1); // 거리는 -1
            q.push({ny, nx});
        }
    }
    
    return maxDist;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'L') {
                ret = max(ret, bfs(i, j));
            }
        }
    }

    cout << ret << endl;
    return 0;
}