#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int alternatingSum(vector<int>& nums) {
    int n = nums.size(), ans = 0;
    
    for (int i = 0; i < n; i++) {
        ans += i % 2 == 0 ? nums[i] : -nums[i];
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
