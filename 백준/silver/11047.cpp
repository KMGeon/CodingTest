#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int count = 0;

    for (int i=n-1; i>=0; i--) {
        if (k/arr[i] >0) {
            count += k/arr[i];
            k %= arr[i];
        }
    }


    cout << count << endl;

    return 0;
}