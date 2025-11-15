#include <bits/stdc++.h>
using namespace std;

int n, ret;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    // 돈, 시간
    vector<pair<int, int> > v;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    // 내림차순
    sort(v.begin(), v.end(), greater<pair<int, int> >());


    bool visited[10001] = {false};
    int sum = 0;

    for (auto x: v) {
        int price = x.first;
        int time = x.second;

        for (int d = time; d >= 1; d--) {
            if (!visited[d]) { // 방문을 안했어
                sum+=price;
                visited[d] = true;
                break;
            }
        }
    }

    cout << sum << endl;


    return 0;
}
