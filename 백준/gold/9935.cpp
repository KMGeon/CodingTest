#include <bits/stdc++.h>
using namespace std;

string str, tg;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> str >> tg;

    string temp;

    for (char x : str) {
        temp += x;

        if (
            temp.size() >= tg.size() &&
            temp.substr(temp.size() - tg.size(),tg.size()) ==tg
        ) {
            temp.erase(temp.end() - tg.size(), temp.end());
        }
    }

    if (temp.size() ==0) {
        cout <<"FRULA" << endl;
    }else {
        cout << temp << endl;
    }


    return 0;
}
