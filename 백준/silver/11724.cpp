#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
int visited[1004];
vector<int> adj[1004];

void dfs(int here) {
    visited[here] =1;

    for (int neighbor : adj[here]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> n >> m;

    for (int i=0; i<m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
    }


    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            ret ++;
        }
    }

    cout << ret;
    return 0;
}