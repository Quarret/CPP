#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size(), ans = 0;
    vector<int> f(n + 1);
    
    for (int i = 0; i < n; i++) {
        f[i + 1] = max(f[i], 0) + nums[i];
    }

    return *max_element(f.begin() + 1, f.end());
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
