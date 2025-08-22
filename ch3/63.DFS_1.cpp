#include<bits/stdc++.h>
using namespace std;

const int n = 6;
vector<int> adj[n];
int visited[n];

void DFS(int u) {
    visited[u] = 1;
    cout << u << "\n";

    for(int v : adj[u]) {
        if(visited[v] == 0) {
            DFS(v);
        }
    }

    // cout << u << "로부터 시작된 함수가 종료되었습니다.\n";
    return;
}

// 돌다리도 두둘겨서 건너기
void dfs1(int  here) {
    visited[here] = 1;
    for (int there : adj[here]) {
        if (visited[there]) continue;
        dfs1(there);
    }
}

// 못먹어도 go ( 방문 상관없이 가지)
void dfs2(int  here) {
    if (visited[here]) return;
    visited[here] = 1;
    for (int there : adj[here]) {
        dfs2(there);
    }
}

int main() {
    // 그래프 구성 (인접 리스트)
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[2].push_back(5);

    // DFS 시작
    DFS(1);

    return 0;
}

/**
DFS , BFS 모두 시간 복잡도는 O(V+E)로 같다.
DFS : 메모리를 덜 사용하며 / 절단점을 구할 수 있다.  / 코드가 짧다. / 완탐에서 많이 사용한다.
VFS : 메모리를 더 씀 / 가중치가 같은 그래프내에서 최단거리를 구할 수 있다. / 코드가 더 길다.
*/