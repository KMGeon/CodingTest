#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, check[10];
char a[20];
vector<string> ret;

bool good(char x, char y, char op){
    if(x < y && op == '<') return true;
    if(x > y && op == '>') return true;
    return false;
}

void go(int idx, string num){
    // idx: 현재 몇 번째 숫자를 선택중인지
    // num: 지금까지 만든 숫자 문자열

    // 종료 조건: n+1개의 숫자를 모두 선택했을 때
    if(idx == n + 1){
        ret.push_back(num);  // 완성된 숫자 조합 저장
        return;
    }

    for(int i = 0; i <= 9; i++){
        if(check[i]) continue;

        // 첫 번째 숫자거나, 이전 숫자와 부등호 조건을 만족하면
        if(idx == 0 || good(num[idx - 1], i + '0', a[idx - 1])){
            check[i] = 1;                      // 숫자 i 사용 체크
            go(idx + 1, num + to_string(i));  // 다음 자리로 재귀 호출
            check[i] = 0;                      // 백트래킹: 사용 체크 해제
            //  check[i] = 1;  // 🔴 "i를 사용하겠다"
            // go(...)        // 📞 더 깊이 탐색
            // check[i] = 0;  // 🔵 "i 사용 끝, 다시 쓸 수 있음"

        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;                              // 부등호 개수 입력
    for(int i = 0; i < n; i++) cin >> a[i];  // 부등호들 입력

    go(0, "");                             // 백트래킹 시작

    sort(ret.begin(), ret.end());          // 문자열 정렬 (사전순)

    // 정렬 후 맨 뒤가 최대값, 맨 앞이 최소값
    cout << ret[ret.size() - 1] << "\n" << ret[0] << "\n";
}