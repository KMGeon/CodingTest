#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100004];

bool myComp(int a, int b) {
    return a > b; // 내림차순
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n, myComp);


    int maxWeight = 0;
    for (int i = 0; i < n; i++) {
        maxWeight = max(arr[i] * (i+1), maxWeight);
    }

    cout << maxWeight << endl;

    return 0;
}
