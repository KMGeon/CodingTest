#include <bits/stdc++.h>
using namespace std;

int INF = 987654321;

// 최소 영양성분
int n, mp, mf, ms, mv;

// 격자판
struct A {
    int p, f, s, v, c;
} a[16];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> mp >> mf >> ms >> mv;

    for (int i = 0; i < n; i++) {
        cin >> a[i].p >> a[i].f >> a[i].s >> a[i].v >> a[i].c;
    }

    int min_cost = INF;
    vector<int> answer;  // 최종 답을 저장할 벡터

    for (int i = 1; i < (1 << n); i++) {
        int p = 0, f = 0, s = 0, v = 0, c = 0;
        vector<int> tmp;  // 현재 선택된 식재료 번호들

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                p += a[j].p;
                f += a[j].f;
                s += a[j].s;
                v += a[j].v;
                c += a[j].c;
                tmp.push_back(j + 1);  // ✅ 선택된 식재료 번호 저장 (1-based)
            }
        }

        if (p >= mp && f >= mf && s >= ms && v >= mv) {
            // ✅ 최소 비용이거나, 같은 비용이면 사전순으로 빠른 것
            if (c < min_cost || (c == min_cost && tmp < answer)) {
                min_cost = c;
                answer = tmp;  // ✅ 전체 벡터를 저장
            }
        }
    }

    // ✅ 결과 출력
    if (min_cost == INF) {
        cout << -1 << '\n';
    } else {
        cout << min_cost << '\n';
        for (int idx : answer) {
            cout << idx << ' ';
        }
        cout << '\n';
    }

    return 0;
}