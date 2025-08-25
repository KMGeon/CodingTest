#include<bits/stdc++.h>
using namespace std;

const int n = 6;
vector<int> adj[n];
int visited[n];

void DFS_stack(int start) {
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int here = s.top();
        s.pop();

        if (visited[here]) continue;

        visited[here] = 1;
        cout << here << endl;

        for (int next : adj[here]) {
            if (!visited[next]) {
                s.push(next);
            }
        }
    }
}

int main() {
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[2].push_back(5);

    // DFS 시작
    DFS_stack(1);

    return 0;
}