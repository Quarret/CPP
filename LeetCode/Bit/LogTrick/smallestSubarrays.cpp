#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> nums = {1,0,2,1,3};
vector<int> smallestSubarrays(vector<int>& nums) {
    int n = nums.size();
    vector<int> suf(n + 1, 0);
    int cnt[35]{};
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] | nums[i];
    }

    vector<int> ans(n, 0);
    int or_ = 0;
    for (int l = 0, r = 0; r < n; r++) {
        or_ |= nums[r];
        for (int i = 0; i <= 31; i++) {
            if ((nums[r] & (1 << i)) == (1 << i)) {
                cnt[i]++;
            }
        }

        while (or_ == suf[l] && l <= r) {
            ans[l] = r - l + 1;

            for (int i = 0; i <= 31; i++) {
                if ((nums[l] & (1 << i)) == (1 << i)) {
                    if (cnt[i] == 1) or_ ^= 1 << i;
                    cnt[i]--;
                }
            }
            l++;
        }
    }

    return ans;
}

/*
其实62N的时间复杂度比nlogMax(约等于29N)要高
以i为右端点，倒叙或更新比i小的点的或值，由于10^9 < 2^29,所以最多修改29次
若更新则值变大，修改距离

利用的是或的性质，后集合包含该集合，则前集合一定包含，比单调性快一点，原因如上
*/

vector<int> smallestSubarrays(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 0);
    
    for (int i = 0; i < n; i++) {
        ans[i] = 1;

        for (int j = i - 1; j >= 0 && (nums[j] | nums[i]) != nums[j]; j--) {
            nums[j] |= nums[i];
            ans[j] = i - j + 1;
        }
    }

    return ans;
}

/*
灵神模板写法:原地去重 + 利用性质
*/
vector<int> smallestSubarrays(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    vector<pair<int, int>> ors;// 按位或的值 + 对应值的右端点


    for (int i = n - 1; i >= 0; i--) {
        ors.emplace_back(0, i);
        for (int j = 0; j < ors.size(); j++) {//更新集合，将nums[i]的值或入
            ors[j].first |= nums[i];
        }

        int k = 0;//k表示已去重最后一个元素下标
        for (int j = 0; j < ors.size(); j++) {
            //if (ors[k].first != ors[k].first) 
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    smallestSubarrays(nums);

    return 0;
}
