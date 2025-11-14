#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    // (끝나는 시간, 시작 시간) 순서로 저장 -> 자동으로 끝나는 시간 우선 정렬됨
    vector<pair<int, int>> meetings;

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        meetings.push_back({end, start}); // (끝, 시작) 순서 주의!
    }

    sort(meetings.begin(), meetings.end());
    int count = 1 , select = 0;

    for (int i=0; i<meetings.size(); i++) {
        if (i==0) continue;
        if (meetings[i].second >= meetings[select].first) {
            select = i;
            count ++;
        }
    }


    cout << count << '\n';

    return 0;
}