#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {
    int f1 = -1e9, f0 = 1e9, n = nums.size(), s = 0, maxx = -1e9, minn = 1e9;
    for (int i = 0; i < n; i++) {
        s += nums[i];
        f1 = max(f1, 0) + nums[i];
        f0 = min(f0, 0) + nums[i];
        maxx = max(maxx, f1);
        minn = min(minn, f0);
    }
    
    if (s == minn) return maxx;
    return max(maxx, s - minn);
}   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
