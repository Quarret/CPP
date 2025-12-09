#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int getMaxLen(vector<int>& nums) {
    int pre[2];
    pre[1] = -1;
    pre[0] = INT_MAX;
    
    int opt = 1, n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!nums[i]) {
            opt = 1;
            pre[0] = INT_MAX;
            pre[1] = i;
            continue;
        }

        opt ^= nums[i] > 0 ? 0 : 1;
        if (pre[opt] == INT_MAX) {
            pre[opt] = i;
        } else {
            ans = max(ans, i - pre[opt]);
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
