#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int n = candidates.size();
    vector<vector<int>> ans;
    vector<int> path;

    auto dfs = [&](this auto&& dfs, int i, int sum) -> void {
        if (sum == target) {
            ans.push_back(path);
            return;
        }

        if (i == n || sum > target) {
            return;
        }

        // 不选
        dfs(i + 1, sum);

        // 选 (选 1 个或多个 candidates[i])
        path.push_back(candidates[i]);
        dfs(i, sum + candidates[i]);

        // 还原现场
        path.pop_back();
    };

    dfs(0, 0);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
