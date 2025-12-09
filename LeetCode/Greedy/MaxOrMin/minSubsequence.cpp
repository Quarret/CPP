#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> minSubsequence(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    sort(nums.begin(), nums.end(), greater());
    
    vector<int> ans;
    int pre = 0;
    for (int x : nums) {
        pre += x;
        ans.push_back(x);
        if (pre > sum - pre) {
            break;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
