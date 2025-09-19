#include <bits/stdc++.h>
using namespace std;

constexpr int SAFE = 1004;
int n, m, l;
int visited[SAFE];
vector<int> adj[SAFE];

void dfs(int here) {
    visited[here] = 1;
    cout << here << " ";

    for (int v: adj[here]) {
        if (visited[v] == 0) {
            dfs(v);
        }
    }
    return;
}

void bfs(int start) {
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int here = q.front();
        q.pop();
        cout << here << " ";

        for (int next : adj[here]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> l;

    for (int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
    }

    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(l);

    cout << endl;
    memset(visited, 0, sizeof(visited));

    bfs(l);


    return 0;
}

// 입력
// 4 5 1
// 1 2
// 1 3
// 1 4
// 2 4
// 3 4
// 결과
// 1 2 4 3
// 1 2 3 4
