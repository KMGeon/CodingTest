#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // a[i] 범위: 1 ~ 100000
    vector<bool> is_used(100001, false);

    long long answer = 0;
    int right = 0;

    // left를 0부터 n-1까지 움직인다
    for (int left = 0; left < n; left++) {

        // right를 가능한 만큼 확장
        while (right < n && is_used[a[right]] == false) {
            is_used[a[right]] = true;  // a[right]를 현재 구간에 포함
            right++;
        }

        // 현재 "중복 없는 구간"은 [left, right)
        // 이 구간을 시작점으로 하는 유효한 부분 수열 개수 = (right - left)
        answer += (right - left);

        // 다음 left를 위해 a[left]를 구간에서 제거
        is_used[a[left]] = false;
    }

    cout << answer << '\n';
    return 0;
}

// # 경우의 수  => long long  박자
// 등비수열 합: (n)*(n+1) /2 = 4*5/2 = 10
// 10 = 17/2