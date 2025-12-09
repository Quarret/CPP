#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    
    int maxx = prices.back(), ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans = max(maxx - prices[i], ans);
        maxx = max(maxx, prices[i]);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
