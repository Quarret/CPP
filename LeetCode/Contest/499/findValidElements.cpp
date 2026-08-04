#include <bits/stdc++.h>
using ll = long long;
using namespace std;


vector<int> findValidElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre(n + 1, 0), suf(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        pre[i + 1] = max(pre[i], nums[i]);
    }

    for (int i = n - 2; i >= 0; i--) {
        suf[i] = max(suf[i + 1], nums[i + 1]);
    }

    vector<int> ans;
    ans.push_back(nums[0]);
    for (int i = 1; i < n - 1; i++) {
        if (nums[i] > pre[i] || nums[i] > suf[i]) ans.push_back(nums[i]);
    }
    if (n != 1) ans.push_back(nums.back());

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}