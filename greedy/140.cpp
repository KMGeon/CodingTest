#include <bits/stdc++.h>
using namespace std;

int from, to, n, idx = 0, ret = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    vector<pair<int, int>> v;
    for (int i=0; i<n;i++) {
        cin >> from >> to;
        v.push_back({to,from});
    }

    sort(v.begin(), v.end());
    from = v[0].second;
    to = v[0].first;

    for (int i=1; i<n;i++) {
        if (v[i].second < to) continue;
        from = v[i].second;
        to =  v[i].first;
        ret ++;
    }
    cout << ret << endl;

    return 0;
}


/**
 *도서관에 1개의 좌석이 있다.
 *각 학생의 도착 시간과 떠나는 시간이 주어진다 .
 *  도착 시간과 떠나는 시간을 정수로 주어지며,
 *  도착 시간은 떠나는 시간보다 항상 작거나 같다.
 */