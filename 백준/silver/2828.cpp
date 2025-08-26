#include<bits/stdc++.h>
using namespace std;

int n, m, k;
int rtn;

int main() {
    cin >> n >> m;
    cin >> k;

    int left = 1;
    int right = left + m - 1;

    for (int i = 0; i < k; i++) {
        int apple;
        cin >> apple;

        if (left <= apple && apple <= right) {
            continue;
        } else if (apple > right) {
            int move = apple - right;
            rtn += move;
            right = apple;
            left = right - m + 1;
        } else if (apple < left) {
            int move = left - apple;
            rtn += move;
            left = apple;
            right = left + m - 1;
        }
    }

    cout << rtn << endl;

    return 0;
}