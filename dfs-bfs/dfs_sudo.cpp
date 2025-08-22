#include<bits/stdc++.h>
using namespace std;

const int n = 6;
vector<int> adj[n];
int visited[n];


void DFS(int  here) {
    visited[here] = 1;
    cout << here << endl;
    for (int there : adj[here]) {
        if (visited[there]) continue;
        DFS(there);
    }
}

int main() {
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[2].push_back(5);

    // DFS 시작
    DFS(1);

    return 0;
}
// 그래프 구성 (인접 리스트)
/*
    그래프 구조:

    1
   / \
  2   3
 / \
4   5
*/