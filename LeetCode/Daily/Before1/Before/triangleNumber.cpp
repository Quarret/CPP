#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int triangleNumber(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int ans = 0;
    for (int l = 0; l < n; l++) {
        for (int r = l + 1; r < n; r++) {
            int val = nums[l] + nums[r];
            auto pos = lower_bound(nums.begin() + r, nums.end(), val) - 1;
            if (pos == nums.end()) continue;
            cout << l << ' ' << r << ' ' << pos - nums.begin() - r << '\n';
            ans += pos - nums.begin() - r;
        }
    }

    return ans;
}

int triangleNumber(vector<int>& nums) {
    ranges::sort(nums);
    
    int ans = 0;
    for (int k = nums.size() - 1; k > 1; k--) {// 倒序遍历k
        int c = nums[k];
        int i = 0, j = k - 1;

        if (nums[0] + nums[1] > c) {// 最小的两条边都大于最大的, 接下来都大于
            ans += (k + 1) * k * (k - 1) / 6;
            break;
        }

        if (nums[k - 2] + nums[k - 1] < c) {// 最大的两条边都小于, 直接下一条最大边
            continue;
        }
        
        while (i < j) {
            if (nums[i] + nums[j] > c) {
                ans += j - i;
                j--;
            } else {
                i++;
            }
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
