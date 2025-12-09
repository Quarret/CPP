/*** 
 * @Author: Quarret
 * @Date: 2025-07-06 08:23:20
 * @LastEditTime: 2025-07-06 08:45:12
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> sortByBits(vector<int>& arr) {
    unordered_map<int, int> mp;
    for (auto& x: arr) {
        int cnt = 0, num = x;
        while (num) {
            cnt += num % 2;
            num /= 2;
        }
        mp[x] = cnt;
    }


    sort(arr.begin(), arr.end(), [&](int& a, int& b) {
        if (mp[a] == mp[b]) return a < b;
        return mp[a] < mp[b];
    });

    return arr;
}

vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [&](int& a, int& b) {
        int cnt1 = __builtin_popcount(a);
        int cnt2 = __builtin_popcount(b);

        return cnt1 == cnt2 ? a < b : cnt1 < cnt2;
    });

    return arr;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
