#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];
int visited[100];
int nodeList[] = {10, 12, 14, 16, 18, 20, 22, 24};

void BFS(int here) {
    queue<int> q;
    visited[here] = 1;  // 시작점의 거리는 1
    q.push(here);

    while(q.size()) {
        int here = q.front();
        q.pop();

        for(int there : adj[here]) {
            if(visited[there]==true) continue;
            visited[there] = visited[here] + 1;
            q.push(there);
        }
    }
}

int main() {
    // 그래프 연결 정보 설정
    adj[10].push_back(12);
    adj[10].push_back(14);
    adj[10].push_back(16);

    adj[12].push_back(18);
    adj[12].push_back(20);

    adj[20].push_back(22);
    adj[20].push_back(24);

    BFS(10);

    for(int i : nodeList) {
        cout << i << " : " << visited[i] << '\n';
    }

    // 시작점 거리는 1이기 때문에 -1을 추가적으로 해야된다.
    cout << "10번으로부터 24번까지 최단거리는 : " << visited[24] - 1 << '\n';

    return 0;
}

/**
                    10
                   /|\
                  / | \
                 /  |  \
                12  14  16
               /|
              / |
             /  |
            18  20
               /|\
              / | \
             /  |  \
            22  |  24
 */

/**
 BFS 특징
 1. 다시 방문하지 않는다.  > visited
 2. 같은 가중치를 가지느그래프에서 최단거리알고리즘   > visited[there] = visited[here] + 1;


1. BFS 수도코드
Queue<int> q;
q.push(here);
visited[here] = 1;

while(q.size()){
    int here = q.front();
    q.pop();

    for(int there : adj[here]) {
        if(visited[there]) continue;
        visited[there] = visited[here] + 1;
        q.push(there);
    }
}
 */
