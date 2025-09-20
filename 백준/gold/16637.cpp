#include <bits/stdc++.h>
using namespace std;

int n, ret = -987654321;
string s;
vector<int> numV;
vector<char> operV;

int calculate(char a, int b, int c) {
    if (a == '+') return b + c;
    if (a == '-') return b - c;
    if (a == '*') return b * c;
}

void go(int here, int hereSum) {

    // 기저사례
    if (here == numV.size()-1) {
        ret = max(ret, hereSum);
        return;
    }

    // 2개로 뻗어야 한다.
    int v1 = calculate(operV[here], hereSum, numV[here+1]);
    go(here +1, v1);

    if (here +2 <= numV.size()-1) {
        int temp = calculate(operV[here + 1], numV[here + 1], numV[here + 2]);
        go(here + 2, calculate(operV[here], hereSum, temp));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> s;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)numV.push_back(s[i] - '0');
        else operV.push_back(s[i]);
    }

    go(0, numV[0]);

    cout << ret << endl;

    return 0;
}
