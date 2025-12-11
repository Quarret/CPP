#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long minCost(vector<int>& nums, vector<int>& cost) {
    long long cnt = reduce(cost.begin(), cost.end(), 0LL);
    cnt /= 2;
    
    int n = nums.size();
    vector<int> idxs(n);
    ranges::iota(idxs, 0);
    ranges::sort(idxs, {}, [&](int &i) {
        return nums[i];
    });

    int x = 0;
    for (int i = 0; i < n; i++) {
        cnt -= cost[idxs[i]];
        if (cnt < 0) {
            x = nums[idxs[i]];
            break;
        } 
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += 1LL * abs(nums[i] - x) * cost[i];
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
