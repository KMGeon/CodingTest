#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    long long answer = 0, prefixSum = 0;

    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        answer += a * prefixSum;
        prefixSum += a;
    }

    cout << answer << "\n";

    return 0;
}
