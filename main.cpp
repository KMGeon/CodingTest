#include<bits/stdc++.h>
using namespace std;

int n;
vector<string> v;
string s, ret;

void go() {

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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
        if (ret.size()) {
            go();
        }
    }

    sort(v.begin(), v.end());
    for (string i:v) cout << i << endl;
    return 0;
}


/**
 int : 10글자
 longlong 19글자

 a : 97
 A: 65
 */