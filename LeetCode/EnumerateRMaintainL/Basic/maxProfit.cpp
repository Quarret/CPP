/*** 
 * @Author: Quarret
 * @Date: 2025-05-05 23:42:27
 * @LastEditTime: 2025-06-04 11:56:38
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> suf(n, 0);

    int num = 0;
    for (int i = n - 1; i >= 0; i--) {
        num = max(num, prices[i]);
        suf[i] = num;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, suf[i] - prices[i]);

    return ans;
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int minn = 1e9, ans = 0;

    for (int i = 0; i < n; i++) {
        ans = max(ans, prices[i] - minn);
        minn = min(minn, prices[i]);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
