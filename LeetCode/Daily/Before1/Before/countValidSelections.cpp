#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int countValidSelections(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre(n + 1), suf(n + 1);

    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + nums[i];
    }
    
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + nums[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            if (pre[i] == suf[i + 1]) {
                ans += 2;
            } else if (pre[i] == suf[i + 1] + 1 || pre[i] + 1 == suf[i + 1]) {
                ans++;
            }
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
