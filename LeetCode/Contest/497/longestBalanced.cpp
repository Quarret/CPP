#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int longestBalanced(string s) {
    int n = s.size();
    int total0 = ranges::count(s, '0');
    int total1 = n - total0;

    unordered_map<int, vector<int>> mp = {{0, {-1}}};
    int ans = 0, sum = 0;


    for (int i = 0; i < n; i++) {
        sum += s[i] == '1' ? 1 : -1;

        if (mp[sum].size() < 2) {
            mp[sum].push_back(i);
        }

        ans = max(ans, i - mp[sum][0]);

        auto it = mp.find(sum - 2);
        if (it != mp.end()) {
            auto &p = it->second;
            if ((i - p[0] - 2) / 2 < total0) {
                ans = max(ans, i - p[0]);
            } else if (p.size() > 1) {
                ans = max(ans, i - p[1]);
            }
        }

        it = mp.find(sum + 2);
        if (it != mp.end()) {
            auto &p = it->second;
            if ((i - p[0] - 2) / 2 < total1) {
                ans = max(ans, i - p[0]);
            } else if (p.size() > 1) {
                ans = max(ans, i - p[1]);
            }
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}