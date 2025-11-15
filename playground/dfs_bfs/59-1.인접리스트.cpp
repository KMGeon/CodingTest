#include <bits/stdc++.h>
using namespace std;


const int V = 10;
bool visited[V];

vector<int> adj[V];


void dfs(int num) {
    visited[num] = true;
    cout << num << endl;

    for (int neighbor : adj[num]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
    return;
}


int main() {
    adj[1].push_back(2);
    adj[1].push_back(3);

    adj[2].push_back(1);

    adj[3].push_back(1);
    adj[3].push_back(4);

    adj[4].push_back(3);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            if (adj[i][j] != 0 && visited[i] == 0) {
                dfs(i);
            }
        }
    }
}
