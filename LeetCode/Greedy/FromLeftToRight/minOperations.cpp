#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minOperations(vector<int>& nums) {
    int n = nums.size();
    
    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
        if (nums[i] == 0) {
            nums[i + 1] ^= 1;
            nums[i + 2] ^= 1;
            ans++;
        } 
    }

    return nums[n - 2] && nums[n - 1] ? ans : -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
