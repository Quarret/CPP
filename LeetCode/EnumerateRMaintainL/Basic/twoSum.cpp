#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
维护左，枚举右
对于双变量问题，枚举其中的一个变量转化为单变量问题，左侧值用hash表维护
*/
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        auto it = mp.find(target - nums[i]);

        if (it != mp.end()) {
            return {it->second, i};
        }

        mp[nums[i]] = i;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
