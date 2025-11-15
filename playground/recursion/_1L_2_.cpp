#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int cnt =0 ;

    for (int i = 0; i < n; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i] + arr[j] ==m) cnt ++;
        }
    }

    cout << cnt << endl;
    return 0;
}