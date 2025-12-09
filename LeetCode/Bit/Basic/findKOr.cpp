/*** 
 * @Author: Quarret
 * @Date: 2025-07-06 10:20:00
 * @LastEditTime: 2025-07-06 10:23:29
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int findKOr(vector<int>& nums, int k) {
    int ans = 0;
    for (int i = 0; i <= 31; i++) {
        int cnt = 0;
        for (auto& x: nums) {
            if ((x >> i) & 1) cnt++;
        }
        if (cnt >= k) ans |= (1 << i);
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
