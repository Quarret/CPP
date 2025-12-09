#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<vector<int>> findSubsequences(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> st;
    vector<int> path;
    
    auto dfs = [&](this auto&& dfs, int i) -> void {
        if (i == n) {
            if (path.size() >= 2) {
                st.insert(path);
            }
            return;
        }
        
        dfs(i + 1);
        
        if (nums[i] >= path.back()) {
            path.push_back(nums[i]);
            dfs(i + 1);
            path.pop_back();
        }
    };
    
    for (int i = 0; i < n; i++) {
        path.push_back(nums[i]);
        dfs(i + 1);
        path.pop_back();
    }
    
    
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
