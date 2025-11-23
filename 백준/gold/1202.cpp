#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> jewels(n);
    vector<int> bags(k);
    for (int i = 0; i < n; i++) {
        cin >> jewels[i].first >> jewels[i].second;
    }

    for (int i = 0; i < k; i++) {
        cin >> bags[i];
    }

    sort(jewels.begin(), jewels.end());
    sort(bags.begin(), bags.end());

    long long answer = 0;
    priority_queue<int> pq;
    int idx = 0;

    for (int i = 0; i < k; i++) {
        while (idx < n && jewels[idx].first <= bags[i]) {
            pq.push(jewels[idx].second);
            idx++;
        }

        if (!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer << '\n';

    return 0;
}
