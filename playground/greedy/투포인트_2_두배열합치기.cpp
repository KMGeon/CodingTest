#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a, b;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        b.push_back(tmp);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int left = 0, right = 0;
    vector<int> result;

    while (left < n && right < m) {
        if (a[left] == b[right]) {
            result.push_back(a[left]);
            left++;
            right++;
        }else if (a[left] > b[right]) {
            right ++;
        }else {
            left ++;
        }
    }

    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}
// 5
// 1 3 9 5 2
// 5
// 3 2 5 7 8