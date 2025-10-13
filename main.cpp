#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s = 18;

    int idx = 1;

    cout << bitset<8>(s) << endl;
    if(s & (1 << idx)) {
        cout << "해당 idx : " << idx << "가 켜져있습니다.\n";
    } else {
        cout << "해당 idx : " << idx << "가 꺼져있습니다.\n";
    }


    return 0;
}