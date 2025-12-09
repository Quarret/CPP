#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countMaxOrSubsets(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    int maxx = 0;
    
    for (int x : nums) maxx |= x;
    for (int i = 0; i < n; i++) {
        if (nums[i] == maxx) ans++;

        for (int j = i - 1; j >= 0 && (nums[j] | nums[i]) != nums[j]; j--) {
            nums[j] |= nums[i];
            ans++;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
