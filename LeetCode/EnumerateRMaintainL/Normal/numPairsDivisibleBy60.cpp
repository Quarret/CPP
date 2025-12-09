/*** 
 * @Author: Quarret
 * @Date: 2025-05-06 22:19:40
 * @LastEditTime: 2025-06-04 12:29:03
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numPairsDivisibleBy60(vector<int>& time) {
    int n = time.size();
    unordered_map<int, int> mp;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int num = time[i] % 60;//迭代不变量
        if (num) ans += mp[60 - num];
        else ans += mp[0];
        mp[num]++;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
