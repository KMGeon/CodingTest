#include <bits/stdc++.h>
using namespace std;

int n;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;


    vector<int> v;
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            v.push_back(i);
        }
    }

    int start = 0, end = 0;
    int sum = 0, cnt = 0;

    while (true) {
        if (sum >= n) {
            sum -= v[start];
            start++;
        } else if (end == v.size()) {
            break;
        } else {
            sum += v[end];
            end++;
        }

        if (sum == n) {
            cnt++;
        }
    }


    cout << cnt << '\n';
    return 0;
}
