#include <bits/stdc++.h>
using namespace std;

bool canChange(string a, string b) {
    int diff = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) diff++;
    }
    return diff == 1;
}

int dfs(string current, string target, vector<string>& words, vector<int>& visited, int depth) {
    if (current == target) {
        return depth;
    }

    int minDepth = INT_MAX;

    for (int i = 0; i < words.size(); i++) {
        if (!visited[i] && canChange(current, words[i])) {
            visited[i] = 1;
            int result = dfs(words[i], target, words, visited, depth + 1);
            if (result != -1) {
                minDepth = min(minDepth, result);
            }
            visited[i] = 0;
        }
    }

    return minDepth == INT_MAX ? -1 : minDepth;
}

int solution(string begin, string target, vector<string> words) {
    if (find(words.begin(), words.end(), target) == words.end()) {
        return 0;
    }

    vector<int> visited(words.size(), 0);
    int result = dfs(begin, target, words, visited, 0);

    return result == -1 ? 0 : result;
}