#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 相邻不同结论
// 对于每一个 nums[i] 和 forb[i] 相同的元素, 要为它找一个 j 使其 nums[i] != nums[j], 两者就可以删除
// 转化为: 有 n 个数, 每次至多可以删除其中的两个数字, 问最少要多少次操作删完

// 判断 -1: 鸽巢原理, 如果 x 在 nums 和 forbi 中的出现次数超过 n, 则一定有一列 nums[i] = forbi[i]
int minSwaps(vector<int>& nums, vector<int>& forbidden) {
    int n = nums.size(), mx = 0, m = 0;
    unordered_map<int, int> mp, cnt;
    for (int i = 0; i < n; i++) {
        mp[nums[i]]++;
        mp[forbidden[i]]++;
        if (mp[nums[i]] > n || mp[forbidden[i]] > n) {
            return -1;
        }

        if (nums[i] == forbidden[i]) {
            m++;
            mx = max(mx, ++cnt[nums[i]]);
        }
    }

    return max(mx, (m + 1) / 2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
