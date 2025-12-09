#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
1 3 -2 3 -1
*/
bool find132pattern(vector<int>& nums) {
    int n = nums.size();

    if (n < 3) return false;

    vector<int> sufmin(n, 1e9 + 5), sufmax(n, -1e9 + 5);
    unordered_map<int, int> mp;
    mp[nums.back()]++;

    sufmin.back() = nums.back(), sufmax.back() = nums.back();
    for (int i = n - 2; i >= 0; i--) {
        sufmin[i] = min(nums[i], sufmin[i + 1]);
        sufmax[i] = max(nums[i], sufmax[i + 1]);

        if (i) mp[nums[i]]++; 
    }

    int minidx = 0;
    for (int j = 1; j < n - 1; j++) {
        mp[nums[j]]--;

        if (nums[j] > nums[minidx]) {
            if (nums[minidx] < sufmin[j + 1] && sufmin[j + 1] < nums[j]) return true; 
            if (nums[minidx] < sufmax[j + 1] && sufmax[j + 1] < nums[j]) return true;
            if (nums[minidx] == sufmin[j + 1] && sufmax[j + 1] == nums[j]) {
                if (n - j - mp[nums[minidx]] - mp[nums[j]] > 0) return true;
            }
        }

        if (nums[j] < nums[minidx]) minidx = j;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
