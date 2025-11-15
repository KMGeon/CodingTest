#include <bits/stdc++.h>
using namespace std;

// 두 개의 정렬된 배열을 병합하는 투포인터 알고리즘
// Time Complexity: O(n + m)
// Space Complexity: O(n + m)

vector<int> solution(int n, int m, vector<int>& a, vector<int>& b) {
    vector<int> answer;
    int p1 = 0, p2 = 0;

    while(p1 < n && p2 < m) {
        if(a[p1] < b[p2]) {
            answer.push_back(a[p1++]);
        } else {
            answer.push_back(b[p2++]);
        }
    }

    // 남은 원소들 추가
    while(p1 < n) answer.push_back(a[p1++]);
    while(p2 < m) answer.push_back(b[p2++]);

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    vector<int> b(m);
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<int> answer;
    int p1 = 0, p2 = 0;

    while(p1 < n && p2 < m) {
        if(a[p1] < b[p2]) {
            answer.push_back(a[p1++]);
        } else {
            answer.push_back(b[p2++]);
        }
    }

    while(p1 < n) answer.push_back(a[p1++]);
    while(p2 < m) answer.push_back(b[p2++]);


    for(int x : answer) {
        cout << x << " ";
    }

    return 0;
}