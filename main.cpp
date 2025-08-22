#include<bits/stdc++.h>
using namespace std;

// 인접 리스트로 그래프 표현 (각 노드의 연결 정보 저장)
vector<int> adj[100];

// 방문 배열 (0: 미방문, 양수: 시작점으로부터의 최단거리)
int visited[100];

// 그래프에 실제로 존재하는 노드들의 번호 리스트
int nodeList[] = {10, 12, 14, 16, 18, 20, 22, 24};

/**
 * BFS (너비우선탐색) 알고리즘
 * - 시작 노드에서 가까운 노드부터 차례대로 방문
 * - 가중치가 모두 1인 그래프에서 최단거리를 구할 수 있음
 * - 큐(FIFO)를 사용하여 구현
 */
void BFS(int start) {
    queue<int> q;                    // BFS용 큐 선언
    visited[start] = 1;              // 시작점의 거리를 1로 설정 (0은 미방문을 의미)
    q.push(start);                   // 시작점을 큐에 추가

    // 큐가 빌 때까지 반복 (모든 연결된 노드 탐색 완료까지)
    while(!q.empty()) {
        int current = q.front();     // 큐의 맨 앞 노드 가져오기
        q.pop();                     // 큐에서 제거

        // 현재 노드와 연결된 모든 인접 노드들 검사
        for(int neighbor : adj[current]) {
            if(visited[neighbor]) continue;          // 이미 방문한 노드는 건너뛰기
            
            // 인접 노드의 최단거리 = 현재 노드의 거리 + 1
            visited[neighbor] = visited[current] + 1;
            q.push(neighbor);                        // 인접 노드를 큐에 추가하여 다음에 탐색
        }
    }
}

int main() {
    /**
     * 그래프 연결 정보 설정 (인접 리스트 방식)
     * 트리 구조:
     *           10 (루트)
     *         / | \
     *        12 14 16
     *       / |
     *      18 20
     *        / \
     *       22 24
     */
    
    // 노드 10의 자식들: 12, 14, 16
    adj[10].push_back(12);
    adj[10].push_back(14);
    adj[10].push_back(16);

    // 노드 12의 자식들: 18, 20
    adj[12].push_back(18);
    adj[12].push_back(20);

    // 노드 20의 자식들: 22, 24
    adj[20].push_back(22);
    adj[20].push_back(24);

    // 노드 10에서 시작하여 BFS 수행
    BFS(10);

    // 결과 출력: 각 노드까지의 최단거리
    cout << "=== BFS 결과: 각 노드까지의 최단거리 ===" << '\n';
    for(int node : nodeList) {
        if(visited[node] > 0) {
            cout << "노드 " << node << " : " << visited[node] - 1 << "단계" << '\n';
        } else {
            cout << "노드 " << node << " : 도달 불가" << '\n';
        }
    }

    // 특정 노드까지의 최단거리 출력
    cout << "\n노드 10에서 노드 24까지의 최단거리: " << visited[24] - 1 << "단계" << '\n';

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
