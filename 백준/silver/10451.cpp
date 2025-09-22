#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1004];
bool visited[1004];

void dfs(int node) {
    visited[node] = true;

    for(int next : adj[node]) {
        if(!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for(int i = 1; i <= n; i++) adj[i].clear();
        fill(visited, visited + n + 1, false);

        for(int i = 1; i <= n; i++) {
            int next;
            cin >> next;
            adj[i].push_back(next);
        }

        int cycleCount = 0;

        for(int i = 1; i <= n; i++) {
            if(!visited[i]) {
                dfs(i);
                cycleCount++;
            }
        }

        cout << cycleCount << "\n";
    }

    return 0;
}