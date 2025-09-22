#include <bits/stdc++.h>
using namespace std;

int n, k, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;

    if (n == k) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> visited(100001, -1);
    queue<int> q;

    q.push(n);
    visited[n] = 0;

    while (q.size()) {
        int now = q.front();
        q.pop();

        if (now == k) {
            cout << visited[k] << endl;
            break;
        }

        for (int x : {now - 1, now + 1, now * 2}) {
            if (x >= 0 && x <= 100000 && visited[x] == -1) {
                visited[x] = visited[now] + 1;
                q.push(x);
            }
        }
    }

    return 0;
}