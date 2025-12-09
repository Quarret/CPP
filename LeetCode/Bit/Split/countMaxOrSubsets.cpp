#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int countMaxOrSubsets(vector<int>& nums) {
    int maxx = 0, ans = 0, n = nums.size();
    
    auto dfs = [&](this auto&& dfs, int i, int or_) -> void {
        if (i >= n) {
            if (or_ == maxx) ans++;
            else if (or_ > maxx) {
                maxx = or_;
                ans = 1;
            }
            return;
        }

        dfs(i + 1, or_);
        dfs(i + 1, or_ | nums[i]);
    };

    dfs(0, 0);

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {3,1};
    countMaxOrSubsets(arr);

    return 0;
}
