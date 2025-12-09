#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<int> path;
    vector<vector<int>> ans;

    auto dfs = [&](this auto&& dfs, int i) -> void {
        if (i == n) {
            ans.push_back(path);
            return;
        }

        dfs(i + 1);

        path.push_back(nums[i]);
        dfs(i + 1);
        path.pop_back();
    };

    dfs(0);
    return ans;
}

// 二进制枚举
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans(1 << n);
    
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) {
                ans[i].push_back(nums[j]);
            }
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
