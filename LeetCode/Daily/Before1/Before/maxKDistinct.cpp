#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> maxKDistinct(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end(), greater());
    
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (!ans.empty() && nums[i] == ans.back()) continue;
        ans.push_back(nums[i]);
        if (ans.size() == k) break;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
