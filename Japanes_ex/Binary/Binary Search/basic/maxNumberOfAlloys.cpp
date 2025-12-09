#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
    auto check = [&](int idx) -> int {
        int l = 0, mid = 0;
        int minpos = min_element(cost.begin(), cost.end()) - cost.begin();
        int r = budget / cost[minpos] + stock[minpos] + 1;

        auto check2 = [&](int t) -> bool {
            long long ans = 0;
            for (int i = 0; i < n; i++) {
                if (composition[idx][i] * t - stock[i] > 0) {
                    ans += (composition[idx][i] * t - stock[i]) * cost[i];
                }

                // long long num = (long long)((long long)composition[idx][i] * (long long)t) - (long long)stock[i];
                // ans += max((long long)0, num) * (long long)cost[i];
            }

            return ans <= budget;
        };

        while (l + 1 < r) {
            mid = l + (r - l) / 2;
            (check2(mid) ? l : r) = mid;
        }

        return l;
    };

    int res = 0;
    for (int i = 0; i < k; i++) {
        res = max(check(i), res);
    }

    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
