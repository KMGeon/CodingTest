#include <bits/stdc++.h>
using namespace std;

int n, x, cnt;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cin >> x;

    sort(v.begin(), v.end());

    int left = 0;
    int right = n - 1;

    while (left < right) {
        if (v[left] + v[right] == x) {
            left++;
            cnt ++;
        }else if (v[left] + v[right] > x) {
            right --;
        }else if (v[left] + v[right] <x) {
            left ++;
        }
    }

    cout << cnt;


    return 0;
}
