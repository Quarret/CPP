/*** 
 * @Author: Quarret
 * @Date: 2025-07-08 08:53:59
 * @LastEditTime: 2025-07-09 15:44:56
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countTriplets(vector<int>& arr) {
    unordered_map<int, vector<int>> mp;
    int pre = 0, n = arr.size(), ans = 0;

    mp[0].push_back(0);// 前缀和的初始化一定不能忘了！！！这次搞了几个小时检查这个错误
    for (int i = 0; i < n; i++) {
        pre ^= arr[i];
        if (mp.find(pre) != mp.end()) {
            for (int x: mp[pre]) ans += i - x;
        }
        mp[pre].push_back(i + 1);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
