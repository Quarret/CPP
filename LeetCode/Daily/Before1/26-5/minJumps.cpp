#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int MX = 1e6 + 1;
vector<int> prime_factors[MX];

int init = [] {
    for (int i = 2; i < MX; i++) {
        if (prime_factors[i].empty()) {
            for (int j = i; j < MX; j += i) {
                prime_factors[j].push_back(i);
            }
        }
    }

    return 0;
}();

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            for (int p : prime_factors[nums[i]]) {
                groups[p].push_back(i);
            }
        }

        int ans = 0;
        vector vis(n, 0);
        vis[0] = 1;
        vector<int> q = {0};

        while (1) {
            auto tmp = q;
            q.clear();

            for (int i : tmp) {
                if (i == n - 1) {
                    return ans;
                }

                auto &idxs = groups[nums[i]];
                idxs.push_back(i + 1);

                if (i > 0) {
                    idxs.push_back(i - 1);
                }

                for (int j : idxs) {
                    if (vis[j]) continue;
                    vis[j] = 1;
                    q.push_back(j);
                }

                idxs.clear();
            }
            ans++;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}