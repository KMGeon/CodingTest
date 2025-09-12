#include<bits/stdc++.h>
using namespace std;

int n, m, v;
vector<int> adj[1004];
bool visited[1004];

void go(int here) {
    visited[here] = true;
    cout << here << " ";  // endl 대신 공백

    for (int x : adj[here]) {
        if (visited[x]) continue;
        go(x);
    }
    return;
}

int main() {
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // 작은 번호부터 방문하기 위해 정렬
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    go(v);
    cout << "\n";  // 마지막에 줄바꿈 한 번만

    return 0;
}