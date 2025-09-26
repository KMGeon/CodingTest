#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int n;
unordered_map<int, int> range;
vector<int> time_list;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int e, x;
        cin >> e >> x;

        if (range.count(e) == 0) {
            range.insert(make_pair(e, 1));
        }
        else {
            range[e] += 1;
        }

        if (range.count(x) == 0) {
            range.insert(make_pair(x, -1));
        }
        else {
            range[x] -= 1;
        }

        time_list.push_back(e);
        time_list.push_back(x);
    }

    sort(time_list.begin(), time_list.end());
    time_list.erase(unique(time_list.begin(), time_list.end()), time_list.end());

    int max_sum = -1;
    pair<int, int> max_range = make_pair(-1, -1);

    int check_sum = 0;
    for (int i = 0; i < time_list.size(); i++) {

        check_sum += range[time_list[i]];

        if (max_sum < check_sum) {
            max_sum = check_sum;
            max_range.first = time_list[i];
            max_range.second = -1;
        }

        else if (max_sum > check_sum && max_range.second == -1) {
            max_range.second = time_list[i];
        }
    }

    cout << max_sum << "\n";
    cout << max_range.first << " " << max_range.second << "\n";

    return 0;
}