#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> st;
    vector<int> path;
    sort(nums.begin(), nums.end());
    
    auto dfs = [&](this auto&& dfs, int i) -> void {
        if (i == n) {
            st.insert(path);
            return;
        }

        dfs(i + 1);

        path.push_back(nums[i]);
        dfs(i + 1);
        path.pop_back();
    };

    dfs(0);
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int n = nums.size();
    vector<int> path;
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    
    auto dfs = [&](this auto&& dfs, int i) -> void {
        if (i == n) {
            ans.push_back(path);
            return;
        }

        // 选
        int x = nums[i];
        path.push_back(nums[i]);
        dfs(i + 1);
        path.pop_back();

        // 不选
        // 后面所有与 nums[i] 相同的都不选
        // 因为此时不选 [x, 空, y] 会与 前面选的情况重复 [x, 选y, 空]
        i++;
        while (i < n && nums[i] == x) {
            i++;
        }
        dfs(i);
    };

    dfs(0);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
