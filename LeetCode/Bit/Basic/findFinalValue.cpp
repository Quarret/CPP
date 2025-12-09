/*** 
 * @Author: Quarret
 * @Date: 2025-07-07 09:47:08
 * @LastEditTime: 2025-07-07 11:12:43
 */

#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int findFinalValue(vector<int>& nums, int original) {
    unordered_map<int, int> mp;
    
    for (auto& x: nums) {
        mp[x] = 1;
        while (mp.find(original) != mp.end()) {
            original = original << 1;
        }
    }

    return original;
}

// 空间O(1)做法
int findFinalValue(vector<int>& nums, int original) {
    int mask = 0;

    for (auto& x: nums) {
        if (x % original == 0) {
            int k = x / original;

            if ((k & (k - 1)) == 0) mask |= k;//x是origin的2次幂倍数
        }
    }

    mask = ~mask;//原题是找出第一个0，反转mask转化为找第一个1
    //-mask = ~mask + 1
    return original * (mask & -mask);//mask & -mask 捕获最低位1 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
