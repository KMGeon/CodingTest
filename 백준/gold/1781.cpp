#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    vector<pair<int, int>> problems;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        problems.push_back({a, b});  // {데드라인, 컵라면}
    }

    // 데드라인 순서로 정렬
    sort(problems.begin(), problems.end());

    // 최소 힙 (컵라면이 적은 것이 top)
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++) {
        int deadline = problems[i].first;
        int cups = problems[i].second;

        minHeap.push(cups);

        // 힙 크기가 데드라인을 초과하면 가장 적은 것 제거
        if (minHeap.size() > deadline) {
            minHeap.pop();
        }
    }

    // 힙에 남아있는 것들의 합
    long long ret = 0;
    while (!minHeap.empty()) {
        ret += minHeap.top();
        minHeap.pop();
    }

    cout << ret << endl;
    return 0;
}
