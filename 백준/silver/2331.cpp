#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
map<int, int> visited;  // 수 -> 첫 등장 인덱스 저장

int getNext(int num, int p) {
    string s = to_string(num);
    int sum = 0;

    for (char c : s) {
        int digit = c - '0';
        sum += pow(digit, p);
    }

    return sum;
}

void dfs(int here) {
    if (visited.count(here) == 0) {
        visited[here] = cnt;
        cnt++;

        int next = getNext(here, m);
        dfs(next);
    } else {
        cout << visited[here] << endl;
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> n >> m;

    dfs(n);

    return 0;
}