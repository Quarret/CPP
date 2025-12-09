#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<vector<int>> permuteUnique(vector<int>& nums) {
    int n = nums.size();
    vector<int> path(n), vis(n);
    set<vector<int>> st;
    
    auto dfs = [&](this auto&& dfs, int i) -> void {
        if (i == n) {
            st.insert(path);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (vis[j]) continue;
            vis[j] = 1;
            path[i] = nums[j];
            dfs(i + 1);
            vis[j] = 0;
        }
    };

    dfs(0);
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    int n = nums.size();
    vector<int> path(n), vis(n);
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    auto dfs = [&](this auto&& dfs, int i) -> void {
        if (i == n) {
            ans.push_back(path);
            return;
        }

        for (int j = 0; j < n; j++) {
            // nums[j] 已经在路径中, continue
            // num[j] == nums[j - 1]
            // nums[j - 1] 不在路径中, 若当前数字填入, 则会产生重复
            // nums[j - 1] 没填 nums[j] 填入 与 nums[j - 1] 填 nums[j] 不填重复
            // nums[j - 1] 在路径中, 剩余元素就是子问题
            if (vis[j] || (j > 0 && nums[j - 1] == nums[j] && !vis[j - 1])) {
                continue;
            }

            vis[j] = 1;
            path[i] = nums[j];
            dfs(i + 1);
            vis[j] = 0;
        }
    };

    dfs(0);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
