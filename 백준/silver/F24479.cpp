#include<bits/stdc++.h>
using namespace std;

int visited[100004];
vector<int> adj[100004];
int n, m, start;
int order_count = 1;

void dfs(int here) {
    visited[here] = order_count++;

    for (int neighbor : adj[here]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    cin >> n >> m >> start;

    for (int i = 0; i < m; i++) {
        int y, x;
        cin >> y >> x;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(start);

    for (int i = 1; i <= n; i++) {
        cout << visited[i] << "\n";
    }

    return 0;
}