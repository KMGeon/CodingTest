#include <bits/stdc++.h>
using namespace std;

int n,m;
char grid[24][24], visited[24];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<n;i++) {
        for (int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i=0; i<n;i++) {
        for (int j=0; j<m; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    visited[0] = 1;




    return 0;
}