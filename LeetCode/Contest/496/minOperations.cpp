#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int solve(vector<int>& nums, int k) {
    int n = nums.size();
    
    vector memo(n, vector<int>(k + 1, -1));
    auto dfs = [&](this auto&& dfs, int i, int left) -> int {
        if (left == 0) {
            return 0;
        }

        if (left > (i + 1) / 2) return INT_MAX / 2;

        int &res = memo[i][left];
        if (res != -1) return res;

        int not_choose = dfs(i - 1, left);
        int choose = dfs(i - 2, left - 1) + max(max(nums[i - 1], nums[i + 1]) - nums[i] + 1, 0);

        res = min(not_choose, choose);
        return res;
    };

    return dfs(n - 2, k);
}

int minOperations(vector<int>& nums, int k) {
    int n = nums.size();
    if (k > n / 2) return -1;

    // 如果 nums[0] 是峰值
    vector<int> a = {nums.back()};
    a.insert(a.end(), nums.begin(), nums.end());
    int ans1 = solve(a, k);
    
    // 如果 nums[0] 不是峰值
    nums.push_back(nums[0]);
    int ans2 = solve(nums, k);

    return min(ans1, ans2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}