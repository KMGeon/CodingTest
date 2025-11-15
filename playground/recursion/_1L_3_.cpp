#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = 0;
vector<int> materials;

// 두 재료의 합이 m인지 확인하는 함수
void findArmor(int start, vector<int> &selected) {
    // 2개의 재료를 모두 선택했을 때
    if (selected.size() == 2) {
        // 두 재료의 합이 m인지 확인
        if (materials[selected[0]] + materials[selected[1]] == m) {
            cnt++;
        }
        return;
    }

    // 다음 재료 선택 (start+1부터 시작하여 중복 방지)
    for (int i = start + 1; i < n; i++) {
        selected.push_back(i);
        findArmor(i, selected);
        selected.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    materials.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> materials[i];
    }

    vector<int> selected;
    findArmor(-1, selected);

    cout << cnt << endl;
    return 0;
}