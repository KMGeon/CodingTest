#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vector<string> v;

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        v.push_back(temp);
    }

    int rtn = 0;
    for (string str: v) {
        stack<char> _stack;
        for (char x: str) {
            if (_stack.size() > 0 && _stack.top() == x) {
                _stack.pop();
            } else {
                _stack.push(x);
            }
        }
        if (_stack.size()==0)rtn++;
    }

    cout << rtn << endl;

    return 0;
}
