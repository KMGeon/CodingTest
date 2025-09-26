#include <bits/stdc++.h>
using namespace std;

int visited[204];

void dfs(int here, int n, vector<vector<int>>& computers) {
    visited[here] = 1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && computers[here][i] == 1) {
            dfs(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    memset(visited, 0, sizeof(visited));

    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n, computers);
            answer++;
        }
    }

    return answer;
}