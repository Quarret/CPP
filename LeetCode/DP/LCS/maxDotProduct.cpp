#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    vector memo(n, vector<int>(m, INT_MIN));

    auto dfs = [&](this auto&& dfs, int i, int j) -> int {
        if (i < 0 || j < 0) return INT_MIN / 2;

        int &res = memo[i][j];
        if (res != INT_MIN) return res;
        int val = nums1[i] * nums2[j];
        res = max({dfs(i - 1, j - 1) + val, dfs(i - 1, j), dfs(i, j - 1), val});
    
        return res;
    };

    return dfs(n - 1, m - 1);
}

int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    vector<int> f(m + 1, INT32_MIN / 2);

    for (int i = 0; i < n; i++) {
        int topleft = f[0];
        for (int j = 0; j < m; j++) {
            int tmp = f[j + 1];

            int v = nums1[i] * nums2[j];
            f[j + 1] = max({topleft + v, v, f[j], f[j + 1]});
            topleft = tmp;
        }
    }

    return f[m];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
