#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> path;
    
    auto dfs = [&](this auto&& dfs, int i) -> void {
        if (path.size() == k) {
            ans.push_back(path);
            return;
        }

        if (i == n + 1) {
            return;
        }

        dfs(i + 1);

        path.push_back(i);
        dfs(i + 1);
        path.pop_back();
    };

    dfs(1);
    return ans;
}

// 枚举回溯
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> path;
    
    auto dfs = [&](this auto&& dfs, int i) -> void {
        if (path.size() == k) {
            ans.push_back(path);
            return;
        }

        int d = k - path.size();
        for (int j = i; j >= d; j--) {
            path.push_back(j);
            dfs(j - 1);
            path.pop_back();
        }
    };

    dfs(n);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
