#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int combinationSum4(vector<int>& nums, int target) {
    vector<int> memo(target + 1, -1);
    
    auto dfs = [&](this auto&& dfs, int x) -> int {
        if (x == 0) return 1;

        int &res = memo[x];
        if (res != memo[x]) return res;
        res = 0;
        for (int val : nums) {
            if (x - val >= 0) res += dfs(x - val);
        }

        return res;
    };

    return dfs(target);
}

int combinationSum4(vector<int>& nums, int target) {
    vector<unsigned int> f(target + 1);
    f[0] = 1;

    for (long long i = 1; i <= target; i++) {
        for (long long x : nums) {
            if (i - x < 0) continue;
            f[i] += f[i - x];
        }
    }

    return f[target];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
