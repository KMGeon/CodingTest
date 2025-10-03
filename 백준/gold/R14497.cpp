#include <bits/stdc++.h>
using namespace std;
#define y1 aaa

const int MAX = 304;
int n, m, x1, y1, x2, y2, cnt;
char grid[MAX][MAX];
int visited[MAX][MAX];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<pair<int, int> > mainQ;

    cin >> n >> m;
    cin >> y1 >> x1 >> y2 >> x2;
    y1--, x1--, y2--, x2--;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            grid[i][j] = s[j];
        }
    }

    visited[y1][x1] = 1;
    mainQ.push({y1, x1});

    while (grid[y2][x2] != '0') {
        queue<pair<int, int> > subQ;
        cnt++;
        while (mainQ.size()) {
            auto now = mainQ.front();
            int y = now.first;
            int x = now.second;
            mainQ.pop();

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny <0 || ny >=n || nx <0 || nx >=m || visited[ny][nx]) continue;
                visited[ny][nx] = cnt;

                if (grid[ny][nx] != '0') {
                    grid[ny][nx] = '0';
                    subQ.push({ny,nx});
                }else {
                    mainQ.push({ny,nx});
                }
            }
        }
        mainQ = subQ;
    }

    cout << cnt;

    return 0;
}
