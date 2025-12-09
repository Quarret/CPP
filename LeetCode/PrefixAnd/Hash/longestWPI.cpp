/*** 
 * @Author: Quarret
 * @Date: 2025-06-10 16:13:30
 * @LastEditTime: 2025-06-10 16:55:03
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int longestWPI1(vector<int>& hours) {
    int n = hours.size(), pre = 0;
    unordered_map<int, int> mp;
    mp[0] = 0;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        pre += (hours[i] > 8);
        for (auto& it: mp) {
            if (2 * (pre - it.second) > i - it.first + 1) ans = max(ans, i - it.first + 1);
        }
        mp[i + 1] = pre;
    }

    return ans;
}

/*
简化数组元素为{-1, 1}大于8小时为1
利用前缀和的连续性
由于数组元素都是-1和1，相邻前缀和之间相差1
前缀和起始值为0
那么到达第一次-2之前一定会到达第一次-1，即第一次-1一定在第一次-2的左侧
第一次到达2之前一定会第一次到达1，即第一次1一定在第一次2的左侧

当pre大于0时，答案就是j
当pre小于0时，答案就是j - idx[pre - 1](pre - 1首次出现的位置)
为什么时pre - 1，因为第一次pre - 2的位置一定比第一次pre - 1的位置更加靠右
*/
int longestWPI(vector<int>& hours) {
    int n = hours.size();
    unordered_map<int, int> mp;
    int pre = 0, ans = 0;

    for (int i = 0; i < n; i++) {
        pre += (hours[i] > 8 ? 1 : -1);
        if (pre > 0) ans = i + 1;
        else {
            if (mp.find(pre - 1) != mp.end()) ans = max(ans, i - mp[pre - 1]);
            if (mp.find(pre) != mp.end()) mp[pre] = i;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> hours = {9,9,6,0,6,6,9};
    longestWPI(hours);

    return 0;
}
