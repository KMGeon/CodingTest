#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> v;
string s, ret;

/**
 * 항상 front를 사용할 때 size로 체크를 해야된다.
 */
void go() {
    while (true) {
        if (ret.size() && ret.front() == '0') {
            ret.erase(ret.begin());
        } else {
            break;
        }
    }

    if (ret.size() == 0) ret = "0";

    v.push_back(ret);

    ret = "";
}


/**
 *   숫자를 sort를 하면 [12, 1, 10]
 *   -> 1,10,12
 *
 *   문자열을 그냥 sort 하면 [20, 123]
 *   ->  123, 20 (아스키 코드로 비교하기 때문에 custom sort를 만들어야 한다.)
 */
bool cmp(string a, string b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        ret = "";
        for (int j = 0; j < s.size(); j++) {
            if (s[j] < 65) {
                ret += s[j];
            } else if (ret.size()) {
                go();
            }
        }
        if (ret.size()) go();
    }
    sort(v.begin(), v.end(), cmp);
    for (string i: v)cout << i << "\n";
    return 0;
}
