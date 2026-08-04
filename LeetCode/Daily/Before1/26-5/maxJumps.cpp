#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxJumps(vector<int>& arr, int d) {
    int n = arr.size();
    vector<int> memo(n);
    
    auto dfs = [&](this auto&& dfs, int i) -> int {
        int &res = memo[i];
        if (res) return res;

        res = 1;

        for (int j = i - 1; j >= max(i - d, 0) && arr[i] > arr[j]; j--) {
            res = max(res, dfs(j) + 1);
        }
        
        for (int j = i + 1; j <= min(i + d, n - 1) && arr[i] > arr[j]; j++) {
            res = max(res, dfs(j) + 1);
        }

        return res;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dfs(i));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}