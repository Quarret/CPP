#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
由于数据小，可以暴力枚举所有子集，利用位运算
0 ~ 2 ^ n
二进制位上的1代表子集中含有这个数
*/
int subsetXORSum(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();

    for (int i = 0; i < (1 << n); i++) {
        int xor_ = 0;
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) == (1 << j)) xor_ ^= nums[j];    
        }
        ans += xor_;
    }

    return ans;
}

/*
直接暴力搜索
*/

int subsetXORSum(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();

    auto dfs = [&] (this auto&& dfs, int i, int xor_) {// (到达第几个数字, 当前子集的异或值)
        if (i >= n) {
            ans += xor_;
            return;
        }

        dfs(i + 1, xor_);//不进入子集
        dfs(i + 1, xor_ ^ nums[i]);//进入子集
    };

    dfs(0, 0);

    return ans;
}

/*
灵神思路
从特殊到一般：
首先我们考虑nums中的数值只有一位，假设至少有1个1
剩下n - 1个数，随机选取，则有2 ^ {n - 1} 种选法
若选出来的数字异或为1，则不放入我们手中的1
若选出来的数字异或为0，则放入我们手中的1

那么，可以我们可以得出结论：
只要nums中有1，则异或值为1的子集的个数为2 ^ {n - 1}, 若无1，则所有子集值为0

拓展到多位
加法运算就是不同位上的数相加：(or值判断该位是否有1)
2 ^ {n - 1} * (1 << idx)(idx: 0 .. n - 1)
*/

int subsetXORSum(vector<int>& nums) {
    int or_ = 0;
    for (int x : nums) {
        or_ |= x;
    }
    
    return or_ << (nums.size() - 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
