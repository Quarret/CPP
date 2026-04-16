#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> nums;
    for (int i = 0; i < 3 * n; i++) {
        nums.push_back(a[i % n]);
    }
    vector memo(3 * n, -1);
    auto dfs = [&](auto&& dfs, int i) -> int {
        int &res = memo[i];
        if (res != -1) return res;
        
        res = 0;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) res = max(res, dfs(dfs, j));
        }
        res += 1;
        
        return res;
    };
    
    int ans = 0;
    for (int i = 0; i < 3 * n; i++) {
        ans = max(ans, dfs(dfs, i));
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}