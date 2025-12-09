#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minDeletions(string s) {
    unordered_map<int, int> mp;
    for (char c : s) {
        mp[c]++;
    }
    
    vector<int> nums;
    for (auto[_, c] : mp) {
        nums.push_back(c);
    }
    sort(nums.begin(), nums.end(), greater());

    int n = nums.size(), ans = 0;
    for (int i = 1; i < n; i++) {
        if (nums[i] >= nums[i - 1]) {
            ans += min(nums[i] - (nums[i - 1] - 1), nums[i]);
            nums[i] = nums[i - 1] - 1;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
