#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> path;
    
    auto dfs = [&](this auto&& dfs, int i, int sum) -> void {
        if (path.size() == k) {
            if (sum == n) {
                ans.push_back(path);
            }
            return;
        }

        if (i == 10) {
            return;
        }

        dfs(i + 1, sum);

        path.push_back(i);
        dfs(i + 1, sum + i);
        path.pop_back();
    };

    dfs(1, 0);
    return ans;
}

// 枚举回溯
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> path;
    
    auto dfs = [&](this auto&& dfs, int i, int t) -> void {
        int d = k - path.size();

        // 剪枝 对称性: t < 0 -> (i + i - d + 1) * d / 2
        if (t < 0 || (i + i - d + 1) * d / 2 < t) {
            return;
        }

        // 路径长度等于 k, d = 0
        // t < 0 || t > 0 -> t == 0
        if (path.size() == k) {
            ans.push_back(path);
            return;
        }

        // 至少要可以选 d 个数字
        for (int j = i; j >= d; j--) {
            path.push_back(j);
            dfs(j - 1, t - j);
            path.pop_back();
        }
    };

    dfs(9, n);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
