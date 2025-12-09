#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> constructTransformedArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    
    for (int i = 0; i < n; i++) {
        ans[i] = nums[((i + nums[i]) % n + n) % n];
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
