#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
vector<pair<int, int>> v; // {무게, 가치}
vector<int> bag;
ll ret = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    // 골동품 입력
    for(int i = 0; i < n; i++){
        int m, value;
        cin >> m >> value;
        v.push_back({m, value});
    }

    // 가방 입력
    for(int i = 0; i < k; i++){
        int c;
        cin >> c;
        bag.push_back(c);
    }

    // 오름차순 정렬
    sort(v.begin(), v.end());      // 무게 기준 오름차순
    sort(bag.begin(), bag.end());  // 가방 무게 오름차순

    // 우선순위 큐 (최대 힙)
    priority_queue<int> pq;

    int j = 0;
    for(int i = 0; i < k; i++){
        // 현재 가방에 담을 수 있는 골동품들을 모두 pq에 넣기
        while(j < n && v[j].first <= bag[i]){
            pq.push(v[j].second); // 가치를 넣음
            j++;
        }

        // pq에서 가장 가치 높은 것 선택
        if(pq.size()){
            ret += pq.top();
            pq.pop();
        }
    }

    cout << ret << "\n";

    return 0;
}