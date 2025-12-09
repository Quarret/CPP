#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size(), m = queries.size();
    vector<bool> ans;

    if (n == 1) {
        for (int i = 0; i < m; i++) ans.push_back(true);
        return ans;
    }

    vector<int> pre(n, 0);
    pre[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        pre[i + 1] = pre[i] + (nums[i] % 2 == nums[i + 1] % 2);
    }

    for (int i = 0; i < m; i++) {
        if (pre[queries[i][1]] - pre[queries[i][0]]) ans.push_back(false);
        else ans.push_back(true);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
