#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<vector<int>> permute(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    vector<int> path;
    unordered_map<int, int> mp;

    auto dfs = [&](this auto&& dfs, int i) -> void {
        if (i == n) {
            ans.push_back(path);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (!mp[nums[j]]) {
                mp[nums[j]] = 1;
                path.push_back(nums[j]);
                dfs(i + 1);
                path.pop_back();
                mp[nums[j]] = 0;
            }
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
