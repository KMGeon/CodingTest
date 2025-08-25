#include<bits/stdc++.h>
using namespace std;

constexpr int safe = 104;
int grid[safe][safe], visited[safe][safe];
int num;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int height) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && ny < num && nx >= 0 && nx < num) {
            // 해당 높이보다 높고, 아직 방문하지 않은 경우
            if (grid[ny][nx] > height && !visited[ny][nx]) {
                dfs(ny, nx, height);
            }
        }
    }
}

int main() {1
    cin >> num;

    int maxHeight = 0;

    // 입력받으면서 최대 높이 찾기
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cin >> grid[i][j];
            maxHeight = max(maxHeight, grid[i][j]);
        }
    }

    int maxSafeAreas = 0;

    // 모든 가능한 비의 높이에 대해 시뮬레이션
    // 높이 0 = 아무것도 잠기지 않음, 높이 maxHeight = 모든 것이 잠김
    for (int rainHeight = 0; rainHeight <= maxHeight; rainHeight++) {
        // visited 배열 초기화
        memset(visited, 0, sizeof(visited));

        int safeAreas = 0;

        // 각 칸을 확인
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num; j++) {
                // 비 높이보다 높고, 아직 방문하지 않은 경우
                if (grid[i][j] > rainHeight && !visited[i][j]) {
                    safeAreas++;
                    dfs(i, j, rainHeight);
                }
            }
        }

        maxSafeAreas = max(maxSafeAreas, safeAreas);
    }

    cout << maxSafeAreas << endl;

    return 0;
}