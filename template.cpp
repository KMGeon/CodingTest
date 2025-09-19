#include <bits/stdc++.h>
using namespace std;

constexpr int SAFE = 1004;
int n,m;
int grid[SAFE][SAFE], visited[SAFE][SAFE];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> n >> m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }


    return 0;
}