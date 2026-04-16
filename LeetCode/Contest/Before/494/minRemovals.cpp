#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int minRemovals(vector<int>& nums, int target) {
    int n = nums.size();
    vector memo(n, vector<int>(100000, -1));
    auto dfs = [&](this auto&& dfs, int i, int path) -> int {
        if (i < 0) {
            if (path != target) return INT_MAX / 2;
            else return 0;
        }

        int &res = memo[i][path];
        if (res != -1) {
            return res;
        }

        int x = nums[i];
        res = min(dfs(i - 1, path ^ x), dfs(i - 1, path) + 1);
        return res;
    };
    
    int ans = dfs(n - 1, 0);
    return ans > 40 ? -1 : ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}