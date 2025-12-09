#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int subsetXORSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(1 << n);
    
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) {
                ans[i] ^= nums[j];
            }
        }
    }

    int s = 0;
    for (int x : ans) {
        s += x;
    }
    return s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
