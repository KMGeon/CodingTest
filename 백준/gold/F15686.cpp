#include<bits/stdc++.h>
using namespace std;

int n, m;
int ret = INT_MAX;
vector<pair<int, int>> home, chicken;
int grid[54][54];




void combi(int start, vector<pair<int, int>>& v) {
    if (v.size() == m) {
        int cityDistance = 0;

        for (auto house : home) {
            int minDist = INT_MAX;

            // 선택된 치킨집들 중 가장 가까운 거리 찾기
            for (auto selectedChicken : v) {
                int dist = abs(house.first - selectedChicken.first) +
                          abs(house.second - selectedChicken.second);
                minDist = min(minDist, dist);
            }

            cityDistance += minDist;
        }

        ret = min(ret, cityDistance);
        return;
    }

    for (int i = start + 1; i < chicken.size(); i++) {
        v.push_back(chicken[i]);
        combi(i, v);
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            if (tmp == 1) home.push_back({i, j});
            if (tmp == 2) chicken.push_back({i, j});
        }
    }


    vector<pair<int,int>> v;
    combi(-1, v);

    cout << ret << endl;

    return 0;
}
