#include <bits/stdc++.h>
using namespace std;

const int V = 10;
bool visited[V];
vector<int> adj[V];

void dfs(int node) {
    visited[node] = true;
    cout << node << " ";
    
    // Iterate through all adjacent vertices
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    // Initialize visited array
    memset(visited, false, sizeof(visited));
    
    // Build the adjacency list (undirected graph)
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(1);
    adj[3].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(3);
    
    cout << "DFS traversal starting from vertex 1: ";
    dfs(1);
    cout << endl;
    
    // If you want to traverse all disconnected components
    cout << "Complete DFS traversal (all components): ";
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < V; i++) {
        if (!visited[i] && !adj[i].empty()) {
            dfs(i);
        }
    }
    cout << endl;
    
    return 0;
}