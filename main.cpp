#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        pq.push({end, start});
    }

    int count = 0;
    int lastEndTime = 0;


    while (!pq.empty()) {
        int endTime = pq.top().first;
        int startTime = pq.top().second;
        pq.pop();

        if (startTime >= lastEndTime) {
            count++;
            lastEndTime = endTime;
        }
    }

    cout << count << '\n';

    return 0;
}
