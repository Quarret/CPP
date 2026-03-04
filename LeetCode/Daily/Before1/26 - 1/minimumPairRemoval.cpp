#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minimumPairRemoval(vector<int>& nums) {
    int ans = 0;

    while (1) {
        if (is_sorted(nums.begin(), nums.end())) break;
        int idx = -1, mn = INT_MAX;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] + nums[i + 1] < mn) {
                idx = i;
                mn = nums[i] + nums[i + 1];
            }
        }

        vector<int> arr;
        for (int i = 0; i < nums.size(); i++) {
            if (i == idx) {
                arr.push_back(nums[i] + nums[i + 1]);
                continue;
            } 
            if (i == idx + 1) continue;

            arr.push_back(nums[i]);
        }

        ans++;
        nums = arr;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}