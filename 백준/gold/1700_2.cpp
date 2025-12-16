#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    vector<int> v(m);
    set<int> s;

    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }

    int cnt = 0;

    for (int i = 0; i < m; i++) {
        if (s.count(v[i]) > 0) {
            continue;
        }

        if (s.size() < n) {
            s.insert(v[i]);
            continue;
        }

        // 가장 나중에 나오는 기기 찾기
        int toRemove = -1;
        int farthest = -1;

        for (int plugged : s) {
            int j = i + 1;
            while (j < m && v[j] != plugged) {
                j++;
            }
            // j가 크면 더 멀리 있는 것
            if (j > farthest) {
                farthest = j;
                toRemove = plugged;
            }
        }

        s.erase(toRemove);
        s.insert(v[i]);
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}