#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> A;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    A.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // ,: , ìx0| ¬©X0 \ ˜¬
    sort(A.begin(), A.end());

    int answer = INT_MAX;
    int left = 0;

    // TODO(human): Implement two-pointer logic here
    // Hint: Use left and right pointers to find minimum difference >= M
    // - Start with left=0, right=1
    // - Calculate diff = A[right] - A[left]
    // - If diff >= M: update answer and move left++
    // - If diff < M: move right++
    // - Handle edge case when left == right

    cout << answer << '\n';

    return 0;
}
