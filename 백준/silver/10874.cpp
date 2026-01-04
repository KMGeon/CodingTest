#include <bits/stdc++.h>
using namespace std;

int n;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vector<int> v;

    for (int i=1; i<=n; i++) {
        v.push_back(i);
    }

    do {
        for (int num : v) {
            cout << num << " ";
        }
        cout << '\n';
    }while (next_permutation(v.begin(), v.end()));




    return 0;
}