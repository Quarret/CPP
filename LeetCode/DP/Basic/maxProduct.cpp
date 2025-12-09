#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    vector<int> f0(n + 1), f1(n + 1);
    f0[0] = 1, f1[0] = 1;
    
    int maxx = -1e9;
    for (int i = 0; i < n; i++) {
        f0[i + 1] = (nums[i] >= 0 ? min(f0[i], 1) : max(f1[i], 1)) * nums[i];
        f1[i + 1] = (nums[i] >= 0 ? max(f1[i], 1) : min(f0[i], 1)) * nums[i];
        maxx = max(maxx, f1[i + 1]);
    }
    
    return maxx;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
