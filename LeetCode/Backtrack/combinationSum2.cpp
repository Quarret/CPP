#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    int n = candidates.size();
    ranges::sort(candidates);
    vector<vector<int>> ans;
    vector<int> path, suf(n + 1);

    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + candidates[i];
    }

    auto dfs = [&](this auto&& dfs, int i, int s) -> void {
        if (i == n) {
            if (s == target) {
                ans.push_back(path);
            }
            return;
        }

        if (s > target || s + suf[i] < target) {
            return;
        }

        int x = candidates[i];
        path.push_back(candidates[i]);
        dfs(i + 1, s + candidates[i]);
        path.pop_back();

        i++;
        while (i < n && candidates[i] == x) {
            i++;
        }
        dfs(i, s);
    };

    dfs(0, 0);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
