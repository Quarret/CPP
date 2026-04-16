#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    const int MOD = 1e9 + 7;

    for (auto &q : queries) {
        int l = q[0], r = q[1];
        int k = q[2], v = q[3];

        for (int i = l; i <= r; i += k) {
            nums[i] = (1LL * nums[i] * v) % MOD;
        }
    }

    int ans = 0;
    for (int x : nums) ans ^= x;
    return ans; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}