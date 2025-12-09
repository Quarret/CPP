#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minGroupsForValidAssignment(vector<int>& balls) {
    unordered_map<int, int> mp;
    for (int x : balls) {
        mp[x]++;
    }

    int k = min_element(mp.begin(), mp.end(), [](const auto &a, const auto &b) {
        return a.second < b.second;
    })->second;

    int ans = 0;
    while (1) {
        for (auto [_, c] : mp) {
            if (c / k < c % k) {
                ans = 0;
                k--;
                break;
            }

            ans += (c + k) / (k + 1);
        }

        if (ans) {
            return ans;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
