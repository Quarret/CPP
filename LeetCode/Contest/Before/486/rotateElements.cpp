#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> rotateElements(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> not_neg;
    for (int i = 0; i < n; i++) {
        if (nums[i] >= 0) not_neg.push_back(i);
    }

    vector<int> ans = nums;
    int m = not_neg.size();
    for (int i = 0; i < m; i++) {
        int idx = not_neg[i];
        int new_idx = not_neg[((i - k) % m + m) % m];
        ans[new_idx] = nums[idx]; 
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}