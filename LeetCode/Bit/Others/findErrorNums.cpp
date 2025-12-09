#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    int sum = 0, n = nums.size(), pre = n * (1 + n) / 2;
    vector<int> cnt(n + 1, 0);
    vector<int> ans(2, 0);
    
    for (int x: nums) {
        cnt[x]++;
        sum += x;
        if (cnt[x] == 2) ans[0] = x;
    }

    ans[1] = ans[0] + pre - sum;
    return ans;
}

/*
还是根据1数位来分组
首先计算出 rep ^ los值
根据rep ^ los的lowbit位区分为两组
*/


vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++) sum ^= (i + 1) ^ nums[i];
    int lowbit = sum & -sum;

    vector<int> ans(2, 0);
    for (int i = 0; i < n; i++) {
        if (((i + 1) & lowbit) == lowbit) ans[0] ^= (i + 1);//一定要注意异或运算的顺序
        else ans[1] ^= (i + 1);

        if ((nums[i] & lowbit) == lowbit) ans[0] ^= nums[i];
        else ans[1] ^= nums[i];
    }

    for (int x: nums) {
        if (x == ans[0]) {
            return ans;
        }
    }

    swap(ans[0], ans[1]);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
