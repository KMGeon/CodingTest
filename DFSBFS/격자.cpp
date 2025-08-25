#include<bits/stdc++.h>
using namespace std;

// 방향 벡터: 상, 우, 하, 좌
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

//
int n, m, ret; // n: 행 수, m: 열 수, ret: 연결된 컴포넌트 개수
int a[104][104]; // 격자판
bool visited[104][104]; // 방문 체크 배열

bool check(int y, int x) {
    return a[y][x] == 1 && !visited[y][x];
}

// DFS 함수: (y, x)에서 시작하여 연결된 모든 1들을 방문
void DFS(int y, int x) {
    visited[y][x] = true;

    // 4방향 탐색
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        // 경계 체크
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

        // 1이면서 방문하지 않은 곳만 탐색
        if (check(ny, nx)) {
            DFS(ny, nx);
        }
    }
}


int main() {
    // 입출력 속도 최적화
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    // 격자판 크기 입력
    cin >> n >> m;

    // 격자판 데이터 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }


    for (int i = 0; i < n; i++) { // y
        for (int j = 0; j < m; j++) { // x
            if (check(i,j)) {
                ret++;
                DFS(i, j);
            }
        }
    }

    // 연결된 컴포넌트의 개수 출력
    cout << ret << "\n";

    return 0;
}

/*
========== 문제 설명 ==========
격자판에서 1로 이루어진 연결된 영역(컴포넌트)의 개수를 구하는 문제

입력:
- 첫 줄: n(행), m(열)
- 다음 n줄: 각 줄마다 m개의 숫자 (0 또는 1)

출력:
- 연결된 1들의 그룹 개수

========== 예제 ==========
입력:
5 5
1 0 1 0 1
1 1 0 0 1
0 0 0 1 1
0 0 0 1 1
0 1 0 0 0

출력:
4

설명:
좌상단의 2x2 영역과 우하단의 2x3 영역, 총 2개의 연결된 컴포넌트

========== 알고리즘 ==========
1. 격자판을 순회하며 1이면서 방문하지 않은 셀 찾기
2. 해당 셀에서 DFS 시작하여 연결된 모든 1들을 방문 처리
3. 컴포넌트 개수 증가
4. 모든 셀 확인 완료까지 반복

시간복잡도: O(n × m)
공간복잡도: O(n × m);
*/
