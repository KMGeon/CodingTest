#include<bits/stdc++.h>
using namespace std;

int answer = 0;

void dfs(int idx, int sum, vector<int>& numbers, int target) {
    if (idx == numbers.size()) {
        if (sum == target) {
            answer++;
        }
        return;
    }
    
    dfs(idx + 1, sum + numbers[idx], numbers, target);
    dfs(idx + 1, sum - numbers[idx], numbers, target);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> numbers = {1,1,1,1,1};
    int target = 3;
    
    dfs(0, 0, numbers, target);
    cout << answer << endl;

    return 0;
}