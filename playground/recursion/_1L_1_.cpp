#include <bits/stdc++.h>
using namespace std;

/**
* 시간 복잡도 초과
*/

 int main() {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     int n, m;
     cin >> n >> m;

     vector<int> arr(n);
     for (int i = 0; i < n; i++) {
         cin >> arr[i];
     }

     vector<bool> mask(n, false);
     for (int i = n - 2; i < n; i++) {
         mask[i] = true;
     }

     int count = 0;

     do {
         vector<int> selected;
         for (int i = 0; i < n; i++) {
             if (mask[i]) {
                 selected.push_back(arr[i]);
             }
         }

         if (selected[0] + selected[1] == m) {
             count++;
         }
     } while (next_permutation(mask.begin(), mask.end()));

     cout << count;
     return 0;
 }
