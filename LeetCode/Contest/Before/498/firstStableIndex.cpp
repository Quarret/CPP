#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int firstStableIndex(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> pre(n + 1, 0), suf(n + 1, INT_MAX);
    
    for (int i = 0; i < n; i++) {
        pre[i + 1] = max(pre[i], nums[i]);
    }

    int ans = INT_MAX;
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = min(suf[i + 1], nums[i]);
        if ((pre[i + 1] - suf[i]) <= k) ans = i;
    }

    return ans != INT_MAX ? ans : -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}