#include <iostream>
#include <cstring>
using namespace std;

int h, w;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h >> w;

    int grid[h][w];
    memset(grid, -1, sizeof(grid));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char tmp;
            cin >> tmp;

            if (tmp == 'c') {
                grid[i][j] = 0;

                for (int k = j + 1; k < w; k++) {
                    grid[i][k] = k - j;
                }
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}