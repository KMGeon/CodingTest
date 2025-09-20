#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 200000;
int n, k;
int visited[MAX+4];
long long cnt[MAX+4];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    if (n == k) {
        cout << 0 << endl;
        cout << 1 << endl;
        return 0;
    }

    memset(visited, 0, sizeof(visited));
    queue<int> q;

    visited[n] = 1;
    cnt[n] = 1;
    q.push(n);

    while (q.size()) {
        int now = q.front();
        q.pop();

        for (int next : {now -1, now +1, now *2}) {
            if (next >=0 && MAX >= next) {
                if (!visited[next]) {
                    q.push(next);
                    visited[next] =1;
                    visited[next] = visited[now]+1;
                    cnt[next] += cnt[now];
                }else if (visited[next] == visited[now] + 1) {
                    cnt[next] += cnt[now];
                }
            }

        }
    }

    cout << visited[k] - 1 << '\n';
    cout << cnt[k] << '\n';

    return 0;
}