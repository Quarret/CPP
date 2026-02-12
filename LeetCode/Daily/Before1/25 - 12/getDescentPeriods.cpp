#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long getDescentPeriods(vector<int>& prices) {
    int n = prices.size();
    long long ans = 0;
    
    long long cnt = 0, pre = prices[0] + 1;
    for (int i = 0; i < n; i++) {
        if (prices[i] - pre == -1) {
            cnt++;
        } else {
            ans += cnt * (cnt + 1) / 2;
            cnt = 1;
        }
        pre = prices[i];
    }
    ans += cnt * (cnt + 1) / 2;
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
