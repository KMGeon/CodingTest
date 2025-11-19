#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    // 도착시간, 검문시간
    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    // 도착 시간 순으로 정렬
    sort(v.begin(), v.end());

    long long currentTime = 0;

    for (int i = 0; i < n; i++) {
        int arrive = v[i].first;
        int wait = v[i].second;

        // 검문 시작 = max(도착 시간, 현재 검문 종료 시간)
        currentTime = max((long long)arrive, currentTime) + wait;
    }

    cout << currentTime << endl;
    return 0;
}
