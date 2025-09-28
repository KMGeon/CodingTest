#include <bits/stdc++.h>
using namespace std;


int solution(vector<int> a, vector<int> b) {
    int answer = 0;

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());


    int size = a.size();

    for (int i = 0; i < size; i++) {
        answer += a[i] * b[i];
    }

    return answer;
}
