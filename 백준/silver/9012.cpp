#include<bits/stdc++.h>
using namespace std;

int t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for (int i = 0; i < t; i++) {
        stack<char> stack;
        string str;
        cin >> str;


        for (int j = 0; j < str.length(); j++) {
            if (stack.empty()) stack.push(str[j]);
            else if (!stack.empty()) {
                char top = stack.top(); // 값을 가져오기
                if (top == '(' && str[j] == ')') {
                    stack.pop();
                } else {
                    stack.push(str[j]);
                }
            }
        }

        if (stack.size() == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
