#include<bits/stdc++.h>
using namespace std;

// y1이 system header에서 정의되어 충돌을 피하기 위한 매크로
#define y1 aaaa

// 전역 변수들
int a[104][104];        // 2D 격자 배열 (1: 직사각형 영역, 0: 빈 공간)
int m, n, k;            // m: 세로 크기, n: 가로 크기, k: 직사각형 개수
int x1, x2, y1, y2;     // 직사각형의 좌하단(x1,y1)과 우상단(x2,y2) 좌표
int visited[104][104];  // 방문 체크 배열
const int dy[4] = {-1, 0, 1, 0};  // 상하좌우 이동을 위한 y 방향 배열
const int dx[4] = {0, 1, 0, -1};  // 상하좌우 이동을 위한 x 방향 배열
vector<int> ret;        // 각 영역의 크기를 저장할 벡터

// DFS를 사용해 연결된 빈 공간의 크기를 계산하는 함수
int dfs(int y, int x) {
    visited[y][x] = 1;  // 현재 위치를 방문 처리
    int ret = 1;        // 현재 셀부터 시작하여 크기를 1로 초기화

    // 4방향으로 탐색
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];  // 새로운 y 좌표
        int nx = x + dx[i];  // 새로운 x 좌표

        // 경계 체크 및 이미 방문한 곳인지 체크
        if (ny < 0 || ny >= m || nx < 0 || nx >= n || visited[ny][nx] == 1) continue;

        // 직사각형 영역(값이 1)이면 탐색하지 않음
        if (a[ny][nx] == 1) continue;

        // 재귀적으로 연결된 영역 탐색하여 크기 누적
        ret += dfs(ny, nx);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                a[y][x] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != 1 && visited[i][j] == 0) {
                ret.push_back(dfs(i, j));
            }
        }
    }

    sort(ret.begin(), ret.end());

    cout << ret.size() << "\n";
    for (int area : ret) {
        cout << area << " ";
    }

    return 0;
}
