#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int go(
    ll a,
    ll b,
    ll c
) {
    if (b == 0) return 1;

    ll ret = go(a,b/2,c);
    ret = (ret * ret) %c;
    if (b%2) ret = (ret*a)%c;
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a, b, c;

    cin >> a >> b >> c;

    int rtn  = go(a, b, c);

    cout << rtn;

    return 0;
}
