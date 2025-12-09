#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

bool checkEqualPartitions(vector<int>& nums, long long target) {
    int n = nums.size();
    auto dfs = [&](this auto&& dfs, int i, long long mul1, long long mul2) -> bool {
        if (mul1 > target || mul2 > target) {
            return false;
        }

        if (i == n) {
            return mul1 == target && mul2 == target;
        }

        return dfs(i + 1, mul1 * nums[i], mul2) || dfs(i + 1, mul1, mul2 * nums[i]);
    };

    return dfs(0, 1, 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
