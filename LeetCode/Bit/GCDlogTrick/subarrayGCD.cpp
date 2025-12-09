#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int subarrayGCD(vector<int>& nums, int k) {
    int n = nums.size(), ans = 0;
    
    for (int i = 0; i < n; i++) {
        if (nums[i] == k) ans++;

        for (int j = i - 1; j >= 0 && gcd(nums[j], nums[i]) != nums[j]; j--) {
            nums[j] = gcd(nums[i], nums[j]);
            if (nums[j] == k) ans++;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
