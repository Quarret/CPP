#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
    vector<int> idxs, pre, nums;
    int n = s.size();
    const int MOD = 1e9 + 7;
    pre.push_back(0);
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') continue;

        idxs.push_back(i);
        pre.push_back(pre.back() + s[i] - '0');
        nums.push_back(s[i] - '0');
    }

    vector<int> mods;
    mods.push_back(0);
    int m = nums.size(), num = 0, pow = 1;
    for (int i = m - 1; i >= 0; i--) {
        num = (num + (nums[i] * pow) % MOD) % MOD;
        pow = (pow * 10) % MOD;
        mods.push_back(num);
    }
    reverse(mods.begin(), mods.end());

    auto qpow = [&](long long x, long long y) -> long long {
        long long ret = 1;
        while (y) {
            if (y & 1) {
                ret = (ret * x) % MOD;
            }
            x = (x * x) % MOD;
            y >>= 1;
        }

        return ret % MOD;
    };

    vector<int> ans;
    for (auto &q : queries) {
        int l = q[0], r = q[1];
        int idx1 = lower_bound(idxs.begin(), idxs.end(), l) - idxs.begin();
        int idx2 = upper_bound(idxs.begin(), idxs.end(), r) - idxs.begin();
        long long s = pre[idx2] - pre[idx1];
        s %= MOD;


        int diff = m - idx2 + 1;
        long long x = qpow(10, diff);
        long long y = qpow(x, MOD);
        int res = ((mods[idx1] - mods[idx2]) + MOD) % MOD;
        res = (res * y * s) % MOD;
        ans.push_back(res);
    }

    return ans;
}

const int MOD = 1e9 + 7;
const int MX = 100001;
long long pow10[MX];
int init = [] {
    pow10[0] = 1;
    for (int i = 1; i < MX; i++) {
        pow10[i] = pow10[i - 1] * 10LL % MOD;
    }

    return 0;
}();

class Solution {
public:
vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
    int n = s.size();
    vector<int> pre_sum(n + 1), pre_non_zero(n + 1), pre_num(n + 1);
    for (int i = 0; i < n; i++) {
        int ch = s[i] - '0';
        pre_sum[i + 1] = (pre_sum[i] + ch) % MOD;
        pre_num[i + 1] = ch > 0 ? (pre_num[i] * 10LL + ch) % MOD : pre_num[i];
        pre_non_zero[i + 1] = pre_non_zero[i] + (ch != 0);
    }

    vector<int> ans;
    ans.reserve(queries.size());
    for (auto &q : queries) {
        int l = q[0], r = q[1];
        int s = (pre_sum[r + 1] - pre_sum[l]) % MOD;
        int len = pre_non_zero[r + 1] - pre_non_zero[l];
        long long x = (pre_num[r + 1] - 1LL * pre_num[l] * pow10[len]) % MOD + MOD;
        ans.push_back(s * x % MOD);
    }

    return ans;
}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
