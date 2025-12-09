#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre(n + 1, 1), suf(n + 1, 1);

    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] * nums[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] * nums[i];
    }

    for (int i = 0; i < n; i++) {
        nums[i] = pre[i] * suf[i + 1];
    }

    return nums;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
