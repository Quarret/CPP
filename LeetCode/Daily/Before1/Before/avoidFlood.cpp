#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 贪心
// 越晚的抽水日应该越留到后面使用
vector<int> avoidFlood(vector<int>& rains) {
    int n = rains.size();
    vector<int> ans(n, -1);
    unordered_map<int, int> full_day; // lake -> 装满
    set<int> dry_day; // 未使用的抽水日
    for (int i = 0; i < n; i++) {
        int lake = rains[i];
        if (lake == 0) {
            ans[i] = 1;
            dry_day.insert(i);
            continue;
        }

        if (full_day.contains(lake)) {
            int j = full_day[lake];

            auto it = dry_day.upper_bound(j);
            if (it == dry_day.end()) {
                return {};
            }
            ans[*it] = lake;
            dry_day.erase(it);
        }
        full_day[lake] = i;
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
