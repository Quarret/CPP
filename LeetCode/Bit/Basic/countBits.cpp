/*** 
 * @Author: Quarret
 * @Date: 2025-07-06 11:32:18
 * @LastEditTime: 2025-07-06 11:33:10
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> countBits(int n) {
    vector<int> ans(n, 0);
    for (int i = 0; i <= n; i++) {
        ans[i] = __builtin_popcount(i);
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
