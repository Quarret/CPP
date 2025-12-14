#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int absDifference(vector<int>& nums, int k) {
    ranges::sort(nums);
    
    int s1 = 0, s2 = 0;
    for (int i = 0; i < k; i++) {
        s1 += nums[i];
    }

    int n = nums.size();
    for (int i = n - 1; i >= n - k; i--) {
        s2 += nums[i];
    }

    return s2 - s1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
