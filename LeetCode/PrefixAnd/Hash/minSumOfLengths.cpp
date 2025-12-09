/*** 
 * @Author: Quarret
 * @Date: 2025-06-03 08:48:20
 * @LastEditTime: 2025-06-09 10:31:58
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
本题主要问题还是解决 --- 枚举右维护左的问题，利用pre计算所有符合条件的子数组会写，但枚举右维护左想不到:(
*/
vector<int> arr = {7,3,4,7};
int minSumOfLengths(vector<int>& arr, int target) {
    int n = arr.size(), pre = 0, suf = 0;

    unordered_map<int, int> mp1, mp2;
    vector<int> minn1(n + 1, 1e9), minn2(n + 1, 1e9);
    mp1[0] = 0, mp2[0] = n;

    for (int i = 0; i < n; i++) {
        pre += arr[i];
        if (mp1.find(pre - target) != mp1.end()) {
            minn1[i + 1] = min(minn1[i], i + 1 - mp1[pre - target]);
        } else minn1[i + 1] = minn1[i];

        mp1[pre] = i + 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        suf += arr[i];
        if (mp2.find(suf - target) != mp2.end()) {
            minn2[i] = min(minn2[i + 1], mp2[suf - target] - i);
        } else minn2[i] = minn2[i + 1];

        mp2[suf] = i;
    }

    int ans = 1e9;
    for (int i = 1; i <= n - 1; i++) {
        ans = min(ans, minn1[i] + minn2[i]);
    }

    return (ans == 1e9 ? -1 : ans);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    minSumOfLengths(arr, 7);

    return 0;
}
