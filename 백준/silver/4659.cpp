#include<bits/stdc++.h>
using namespace std;

bool check(char a) {
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') {
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    while (cin >> str && str != "end") {
        char ch[str.length()];
        strcpy(ch, str.c_str());

        int checkMoum = false;
        int check1 = false;
        int check2 = true;
        int lCnt = 0;
        int rCnt = 0;
        char temp = '\0';

        for (int i = 0; i < str.length(); i++) {
            if (check(ch[i])) {
                check1 = true;
                lCnt++;
                rCnt = 0;
            } else {
                lCnt = 0;
                rCnt++;
            }

            if (i == 0) {
                temp = ch[i];
            } else {
                if (temp == ch[i]) {
                    check2 = false;
                    if (ch[i] == 'e' || ch[i] == 'o') {
                        check2 = true;
                    }
                } else {
                    temp = ch[i];
                }
            }

            if (lCnt == 3 || rCnt == 3) {
                check2 = false;
                break;
            }
        }

        if (check1 && check2) {
            cout << "<" << str << "> is acceptable." << endl;
        } else {
            cout << "<" << str << "> is not acceptable." << endl;
        }
    }
    return 0;
}
