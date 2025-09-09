#include<bits/stdc++.h>
using namespace std;
int a[10][10], visited[10][10], n, m, ret;
vector<pair<int, int>> virusList, wallList;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || a[ny][nx] == 1) continue;
        visited[ny][nx] = 1;
        dfs(ny, nx);
    }
}

int solve(){
    fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);

    cout << "바이러스 확산 시작..." << endl;
    for(pair<int, int> b : virusList){
        visited[b.first][b.second] = 1;
        cout << "바이러스 (" << b.first << "," << b.second << ")에서 DFS 시작" << endl;
        dfs(b.first, b.second);
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 0 && !visited[i][j]) cnt++;
        }
    }

    cout << "안전 영역 개수: " << cnt << endl;
    return cnt;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i <n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 2) virusList.push_back({i, j});
            if(a[i][j] == 0) wallList.push_back({i, j});
        }
    }

    cout << endl << endl;

    int combination_count = 0;

    for(int i = 0; i < wallList.size(); i++){
        for(int j = 0; j < i; j++){
            for(int k = 0; k < j; k++){
                combination_count++;

                // 벽 세우기
                a[wallList[i].first][wallList[i].second] = 1;
                a[wallList[j].first][wallList[j].second] = 1;
                a[wallList[k].first][wallList[k].second] = 1;

                int current_safe = solve();
                int prev_ret = ret;
                ret = max(ret, current_safe);


                // 벽 제거 (백트래킹)
                a[wallList[i].first][wallList[i].second] = 0;
                a[wallList[j].first][wallList[j].second] = 0;
                a[wallList[k].first][wallList[k].second] = 0;
            }
        }
    }

    cout << "전체 조합 수: " << combination_count << endl;
    cout << "최종 답: " << ret << endl;
    return 0;
}