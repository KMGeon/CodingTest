#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // dp[i] = i를 1,2,3의 합으로 나타내는 방법의 수
    int dp[12] = {0};
    dp[0] = 1;  // 기저 조건
    dp[1] = 1;  // 1
    dp[2] = 2;  // 1+1, 2
    dp[3] = 4;  // 1+1+1, 1+2, 2+1, 3

    for (int i = 4; i <= 11; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\\n';
    }

    return 0;
}