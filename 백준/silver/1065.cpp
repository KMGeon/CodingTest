#include <bits/stdc++.h>
using namespace std;

bool hansu(int num) {
    if (num < 100) return true;  // 1~99는 모두 한수

    string s = to_string(num);
    int diff = s[0] - s[1];

    for (int i = 0; i < s.size()-1; i++) {
        if (s[i] - s[i+1] != diff) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (hansu(i)) count++;
    }

    cout << count << endl;
    return 0;
}
