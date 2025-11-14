#include <bits/stdc++.h>
using namespace std;

int n;
int a[104], b[104];

bool myComp(int a, int b) {
    return a >b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }


    sort(a, a+n);
    sort(b, b+n,myComp);

    int sum = 0;
    for (int i=0; i<n; i++) {
        sum += (a[i] * b[i]);
    }

    cout << sum << endl;


    return 0;
}
