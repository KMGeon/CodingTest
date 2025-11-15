#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    int sum = 0, maxResult;

    // 첫 번째 윈도우 계산
    for (int i = 0; i < m; i++) {
        sum += a[i];
    }
    maxResult = sum;  // 첫 윈도우를 maxResult에 반영

    // 슬라이딩 윈도우로 나머지 탐색
    for (int i = m; i < n; i++) {
        sum += a[i] - a[i - m];
        maxResult = max(maxResult, sum);  // 최댓값 갱신
    }

    cout << maxResult << '\n';

    return 0;
}
