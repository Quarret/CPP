#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int findLength(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    vector memo(n, vector<int>(m, -1));
    
    int ans = 0;
    auto dfs = [&](this auto&& dfs, int i, int j) -> int {
        if (i < 0 || j < 0) return 0;

        int &res = memo[i][j];
        if (res != -1) return res;
        res = nums1[i] == nums2[j] ? dfs(i - 1, j - 1) + 1 : 0;

        return res;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, dfs(i, j));
        }
    }

    return ans;
}

int findLength(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    vector f(n + 1, vector<int>(m + 1, 0));

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            f[i + 1][j + 1] = nums1[i] == nums2[j] ? f[i][j] + 1 : 0;
            ans = max(ans, f[i + 1][j + 1]);
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
