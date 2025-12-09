/*** 
 * @Author: Quarret
 * @Date: 2025-06-06 10:19:40
 * @LastEditTime: 2025-06-06 10:23:08
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int findSpecialInteger(vector<int>& arr) {
    int n = arr.size(), ans = 0;
    vector<int> cnt(arr.back() + 5, 0);

    for (int i = 0; i < n; i++) {
        cnt[arr[i]]++;
        if (cnt[arr[i]] > n / 4) {
            ans = arr[i];
            break;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
