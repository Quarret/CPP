/*** 
 * @Author: Quarret
 * @Date: 2025-06-04 17:14:42
 * @LastEditTime: 2025-06-04 17:19:55
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int similarPairs(vector<string>& words) {
    int n = words.size(), ans = 0;
    unordered_map<long long, int> mp;

    for (int i = 0; i < n; i++) {
        long long m = words[i].size(), num = 0;
        for (int j = 0; j < m; j++) {
            num |= 1 << (words[i][j] - 'a');//一维bool数组统计重复字符串利用位运算压缩
        }

        if (mp.find(num) != mp.end()) ans += mp[num];
        mp[num]++;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
