#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<bool> prefixesDivBy5(vector<int>& nums) {
    int base = 0, n = nums.size();
    vector<bool> ans(n);
    
    for (int i = 0; i < n; i++) {
        base = (base << 1 | nums[i]) % 5;
        if (base) {
            ans[i] = false;
        } else {
            ans[i] = true;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
